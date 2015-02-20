#include "gmd/tcp_connector.hpp"
#include "gmd/message.hpp"
#include <cstring>
#include <thread>
#include <iostream>

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

    gmd::tcp_connector tcp( []( const gmd::message& msg ) {
        std::cout << msg << std::endl << std::endl;
    } );

    tcp.session( "XLON", params );
    tcp.symbol( "XLON", "VOD.L" );

    std::thread t0( &gmd::tcp_connector::start, &tcp );
    std::chrono::milliseconds dura( 5000 );

    while( 1 ) {
        std::this_thread::sleep_for( dura );
        tcp.failover( "XLON" );
    }

    t0.join();
}
