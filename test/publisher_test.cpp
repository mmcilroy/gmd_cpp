#include "gmd/tcp_publisher.hpp"
#include "gmd/tcp_connector.hpp"
#include "gmd/handler.hpp"
#include "gmd/message.hpp"
#include <cstring>
#include <thread>
#include <iostream>

struct my_handler : public gmd::handler
{
    virtual bool on_next( const gmd::message& msg, size_t available )
    {
        std::cout << msg << std::endl;
        return true;
    }
};

int main()
{
    gmd::tcp_params params;
    params.host[0] = "169.182.163.54";
    params.port[0] = "14002";
    params.host[1] = "0.0.0.0";
    params.port[1] = "14003";
    params.user = "bilge";
    params.pass = "bilge";
    params.feed = 22;

    gmd::tcp_publisher tcp;
    tcp.session( "XLON", params );
    tcp.symbol( "XLON", "VOD.L" );
    tcp.subscribe( new my_handler );
    tcp.start();

    /*
    std::thread t0( [ &tcp ]() {
        tcp.start();
    } );

    while( 1 ) {
        std::chrono::milliseconds dura( 5000 );
        std::this_thread::sleep_for( dura );
        tcp.failover( "XLON" );
    }
    */
}
