#include "gmd/tcp_publisher.hpp"
#include "gmd/tcp_connector.hpp"
#include "gmd/handler.hpp"
#include "gmd/message.hpp"
#include "pulsar/subscription.hpp"
#include "pulsar/stopwatch.hpp"
#include "pulsar/wait.hpp"
#include <cstring>
#include <vector>
#include <thread>

using namespace gmd;

namespace {
const size_t MAX_MSG_LEN = 512;
}

struct tcp_publisher::impl
{
    tcp_connector connector_;

    pulsar::source< char[ MAX_MSG_LEN ] > src_;
    pulsar::subscription< char[ MAX_MSG_LEN ] >& sub_;

    // handlers to dispatch to
    std::vector< handler* > handlers_;

    // tcp connector thread
    std::thread connector_thread_;

    impl() :
        src_( 16*1024 ),
        sub_( src_.subscribe() ),
        connector_( [ this ]( const message& msg ) {
            // wait for slot to become available
            pulsar::yield_sleep_wait wait;
            pulsar::wait_till_available( src_, wait, 1 );

            // copy message into slot
            std::memcpy( src_.at( 0 ), msg.get_buffer(), msg.get_length() );

            // make slot available to subscriber
            src_.commit( 1 );
        } )
    {
    }

    ~impl()
    {
        stop();
    }

    void session( const char* market, const tcp_params& params )
    {
        connector_.session( market, params );
    }

    void symbol( const char* market, const char* symbol )
    {
        connector_.symbol( market, symbol );
    }

    void failover( const char* market )
    {
        connector_.failover( market );
    }

    void subscribe( handler* h )
    {
        // store handler
        handlers_.push_back( h );

        // if this is the first handler launch the connector thread
        if( handlers_.size() == 1 ) {
            connector_thread_ = std::thread( &tcp_connector::start, &connector_ );
        }
    }

    size_t publish()
    {
        if( handlers_.size() <= 0 ) {
            return 0;
        }

        // wait for a message to become available
        pulsar::yield_sleep_wait wait;
        pulsar::stopwatch watch;
        watch.start();
        size_t batch;
        while( watch.elapsed_ms() < 1000 && ( ( batch = sub_.available() ) < 1 ) ) {
            wait();
        }

        // keep track of completed handlers
        std::vector< std::vector< handler* >::iterator > del;

        // dispatch available messages to handlers
        size_t i;
        for( i=0; i<batch; i++ ) {
            for( auto j=handlers_.begin(); j!=handlers_.end(); j++ ) {
                if( !(*j)->on_next( message( (char*)sub_.at( i ), MAX_MSG_LEN ), batch-i-1 ) ) {
                    del.push_back( j );
                    break;
                }
            }
        }

        // remove completed handlers
        for( auto k=del.begin(); k!=del.end(); k++ ) {
            handlers_.erase( *k );
        }

        if( i>0 ) {
            sub_.commit( i );
        }

        return i;
    }

    void start()
    {
        while( handlers_.size() ) {
            publish();
        }
    }

    void stop()
    {
        if( connector_thread_.get_id() != std::thread::id() ) {
            connector_.stop();
            connector_thread_.join();
        }
    }
};

tcp_publisher::tcp_publisher() :
    impl_( new impl )
{
}

tcp_publisher::~tcp_publisher()
{
}

void tcp_publisher::session( const char* market, const tcp_params& params )
{
    impl_->session( market, params );
}

void tcp_publisher::symbol( const char* market, const char* sym )
{
    impl_->symbol( market, sym );
}

void tcp_publisher::failover( const char* market )
{
    impl_->failover( market );
}

void tcp_publisher::subscribe( handler* h )
{
    impl_->subscribe( h );
}

size_t tcp_publisher::publish()
{
    impl_->publish();
}

void tcp_publisher::start()
{
    impl_->start();
}

void tcp_publisher::stop()
{
    impl_->stop();
}
