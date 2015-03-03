#include "gmd/tcp_publisher.hpp"
#include "gmd/tcp_connector.hpp"
#include "gmd/handler.hpp"
#include "gmd/message.hpp"
#include "pulsar/subscriber.hpp"
#include <cstring>
#include <vector>
#include <thread>

using namespace gmd;

namespace {
const size_t MAX_MSG_LEN = 512;
}

struct tcp_publisher::impl
{
    pulsar::publisher< char[ MAX_MSG_LEN ], pulsar::block_wait_strategy > pub_;
    pulsar::subscriber< char[ MAX_MSG_LEN ], pulsar::block_wait_strategy >& sub_;

    tcp_connector connector_;

    // handlers to dispatch to
    std::vector< handler* > handlers_;

    // tcp connector thread
    std::thread connector_thread_;

    impl() :
        pub_( 16*1024 ),
        sub_( pub_.subscribe() ),
        connector_( [ this ]( const message& msg ) {
            pub_.publish( 1, [&]( char* buf ) {
                std::memcpy( buf, msg.get_buffer(), msg.get_length() );
            } );
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

    void start()
    {
        sub_.subscribe( [ this ]( const char* msg, size_t rem ) {
            for( auto j=handlers_.begin(); j!=handlers_.end(); j++ ) {
                (*j)->on_next( message( const_cast< char* >( msg ), MAX_MSG_LEN ), rem );
            }
            return true;
        } );
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

void tcp_publisher::start()
{
    impl_->start();
}

void tcp_publisher::stop()
{
    impl_->stop();
}
