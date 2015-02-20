#include "gmd/tcp_connector.hpp"
#include "gmd/handler.hpp"
#include "gmd/message.hpp"

#include <boost/asio.hpp>

#include <set>
#include <sstream>
#include <iostream>

using boost::asio::ip::tcp;
using namespace gmd;

namespace {

const size_t MAX_MSG_LEN = 4096;
const size_t CONNECT_INTERVAL = 1;

struct tcp_session
{
    // paramaters for this session
    tcp_params params_;

    // function to call on receipt of a complete message
    std::function< void ( const gmd::message& ) > callback_;

    // stores the gmd message
    std::unique_ptr< char[] > buf_;

    // asio objects
    boost::asio::deadline_timer timer_;
    boost::asio::io_service& io_;
    boost::asio::ip::tcp::socket sock_;

    // the symbols we are subscribing to
    typedef std::set< std::string > symbol_set;
    symbol_set symbols_active_;
    symbol_set symbols_pending_;

    // holds the index of the address we will connect to (ie primary / secondary)
    int addr_;

    tcp_session( const tcp_params& params, std::function< void ( const message& ) > callback, boost::asio::io_service& io ) :
        params_( params ),
        callback_( callback ),
        buf_( new char[ MAX_MSG_LEN ] ),
        timer_( io, boost::posix_time::seconds( CONNECT_INTERVAL ) ),
        io_( io ),
        sock_( io ),
        addr_( 0 )
    {
        // constructor
    }

    void symbol( std::string sym )
    {
        // add sym to our pending list
        symbols_pending_.insert( sym );
    }

    void connect()
    {
        std::cout << "connect " << params_.host[ addr_ ] << ":" << params_.port[ addr_ ] << std::endl;

        // move all active symbols back to pending which will cause us to resubscribe
        symbols_pending_.insert( symbols_active_.begin(), symbols_active_.end() );
        symbols_active_.clear();

        // establish tcp connection
        // if connection fails we will retry
        tcp::resolver resolver( io_ );
        auto it = resolver.resolve( { params_.host[ addr_ ], params_.port[ addr_ ] } );
        boost::asio::async_connect(
            sock_,
            it,
            [this]( boost::system::error_code ec, tcp::resolver::iterator ) {
                if( ec ) {
                    timer_.expires_from_now( boost::posix_time::seconds( CONNECT_INTERVAL ) );
                    timer_.async_wait( [this]( const boost::system::error_code& ) { connect(); } );
                } else {
                    login(); // connected ok
                }
            } );
    }

    void failover()
    {
        std::cout << "failover" << std::endl;

        // flip the host / port and close the current connection
        // this will cause current handlers to return an error thus
        // resulting in a new call to connect()
        addr_ = ( addr_+1 ) % 2;
        sock_.close();
    }

    void next_message()
    {
        // if there are symbols that we have yet to subscribe to, handle that
        // otherwise start reading the next message
        if( symbols_pending_.size() ) {
            subscribe();
        } else {
            read_header();
        }
    }

    void login()
    {
        std::cout << "login" << std::endl;

        // build the login request
        char* buf = new char[512];
        memset( buf, 0, 512 );

        sbe::GmdLogonRequest lreq;
        lreq.wrapForEncode( buf, 0, 512 )
            .packetHdr()
            .headerLength( 3 )
            .numberOfMessages( 1 )
            .packetLength( sbe::GmdLogonRequest::sbeBlockLength() );

        lreq.messageHdr()
            .messageType( 21 )
            .messageHdrLength( sbe::GmdMessageHdr::size() / 8 )
            .messageLength( sbe::GmdLogonRequest::sbeBlockLength() - sbe::GmdPacketHdr::size() )
            .feedId( params_.feed );

        strcpy( const_cast< char* >( lreq.clientId() ), params_.user.c_str() );
        strcpy( const_cast< char* >( lreq.password() ), params_.pass.c_str() );

        // send it
        boost::asio::async_write(
            sock_,
            boost::asio::buffer( buf, sbe::GmdLogonRequest::sbeBlockLength() ),
            [this, buf]( boost::system::error_code ec, size_t ) {
                delete [] buf;
                if( ec ) {
                    connect(); // reconnect
                } else {
                    next_message();
                }
            } );
    }

    void subscribe()
    {
        // subscribe to the first symbol from pending symbols
        std::string symbol = *symbols_pending_.begin();
        symbols_pending_.erase( symbols_pending_.begin() );
        symbols_active_.insert( symbol );
        std::cout << "subscribe: " << symbol
                  << ", pending: " << symbols_pending_.size()
                  << ", active: " << symbols_active_.size() << std::endl;

        // build the subscription request
        char* buf = new char[512];
        memset( buf, 0, 512 );

        sbe::GmdSubscriptionRequest sreq;
        sreq.wrapForEncode( buf, 0, 512 )
            .packetHdr()
            .headerLength( 3 )
            .numberOfMessages( 1 )
            .packetLength( sbe::GmdSubscriptionRequest::sbeBlockLength() );

        sreq.messageHdr()
            .messageType( 1 )
            .messageHdrLength( sbe::GmdMessageHdr::size() / 8 )
            .messageLength( sbe::GmdSubscriptionRequest::sbeBlockLength() - sbe::GmdPacketHdr::size() )
            .feedId( params_.feed );

        sreq.numberOfSymbols( 1 );
        sreq.subscriptionInfoSize( 48/8 );
        sreq.feedId( params_.feed );
        sreq.marketCenterId( params_.feed );
        sreq.subscriptionType( 2 );
        strcpy( const_cast< char* >( sreq.symbol() ), symbol.c_str() );

        // send it
        boost::asio::async_write(
            sock_,
            boost::asio::buffer( buf, sbe::GmdSubscriptionRequest::sbeBlockLength() ),
            [this, buf]( boost::system::error_code ec, size_t ) {
                delete [] buf;
                if( ec ) {
                    connect();
                } else {
                    next_message();
                }
            } );
    }

    void read_header()
    {
        // read as many bytes required to form a complete header
        boost::asio::async_read(
            sock_,
            boost::asio::buffer( buf_.get(), sbe::GmdPacketHdr::size() ),
            boost::asio::transfer_exactly( sbe::GmdPacketHdr::size() ),
            [this]( boost::system::error_code ec, size_t len ) {
                if( ec ) {
                    connect();
                } else {
                    sbe::GmdPacketHdr phdr;
                    phdr.wrap( buf_.get(), 0, 0, sbe::GmdPacketHdr::size() );
                    read_body( phdr.packetLength() - sbe::GmdPacketHdr::size() );
                }
            } );
    }

    void read_body( size_t len )
    {
        // once we have a complete header we know the size of the full message so read
        // that number of bytes
        boost::asio::async_read(
            sock_,
            boost::asio::buffer( buf_.get() + sbe::GmdPacketHdr::size(), MAX_MSG_LEN - sbe::GmdPacketHdr::size() ),
            boost::asio::transfer_exactly( len ),
            [this]( boost::system::error_code ec, size_t len ) {
                if( ec ) {
                    connect();
                } else {
                    callback();
                    next_message();
                }
            } );
    }

    void callback()
    {
        // blockLength needs to be tweaked for it to work with sbe
        sbe::GmdMessageHdr mhdr;
        mhdr.wrap( buf_.get() + sbe::GmdPacketHdr::size() , 0, 0, sbe::GmdMessageHdr::size() );
        if( mhdr.messageType() == 12 ) {
            sbe::GmdSingleQuoteGroupHdr shdr;
            shdr.wrap( const_cast< char* >( buf_.get() + sbe::GmdPacketHdr::size() + sbe::GmdMessageHdr::size() + sbe::GmdQuoteHdr::size() ), 0, 0, sbe::GmdSingleQuoteGroupHdr::size() );
            shdr.blockLength( shdr.blockLength() * 8 );
        }

        // got a complete message so call the callback function
        callback_( message( buf_.get(), mhdr.messageLength() + sbe::GmdPacketHdr::size() ) );
    }
};

}

struct tcp_connector::impl
{
    boost::asio::io_service io_;

    std::function< void ( const message& ) > callback_;

    typedef std::map< std::string, std::unique_ptr< tcp_session > > session_map;
    session_map sessions_;

    impl( std::function< void ( const message& ) > callback ) :
        callback_( callback )
    {
    }

    void session( const std::string& market, const tcp_params& params )
    {
        std::unique_ptr< tcp_session > sess( new tcp_session( params, callback_, io_ ) );
        sess->connect();
        sessions_[ market ] = std::move( sess );
    }

    void symbol( const std::string& market, std::string sym )
    {
        tcp_session* sess = sessions_[ market ].get();
        io_.post( [ sess, sym ]() { 
            sess->symbol( sym );
        } );
    }

    void failover( const std::string& market )
    {
        tcp_session* sess = sessions_[ market ].get();
        io_.post( [ sess ]() {
            sess->failover();
        } );
    }

    void start()
    {
        io_.run();
    }

    void stop()
    {
        io_.stop();
    }
};

tcp_connector::tcp_connector( std::function< void( const message& ) > callback ) :
    impl_( new impl( callback ) )
{
}

tcp_connector::~tcp_connector()
{
}

void tcp_connector::session( const std::string& market, const tcp_params& params )
{
    return impl_->session( market, params );
}

void tcp_connector::symbol( const std::string& market, const std::string& symbol )
{
    impl_->symbol( market, symbol );
}

void tcp_connector::failover( const std::string& market )
{
    impl_->failover( market );
}

void tcp_connector::start()
{
    impl_->start();
}

void tcp_connector::stop()
{
    impl_->stop();
}
