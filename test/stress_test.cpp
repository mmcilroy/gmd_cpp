#include "gmd/tcp_publisher.hpp"
#include "gmd/tcp_connector.hpp"
#include "gmd/handler.hpp"
#include "gmd/message.hpp"
#include <cstring>
#include <thread>
#include <fstream>
#include <iostream>

struct my_handler : public gmd::handler
{
    virtual bool on_next( const gmd::message& msg, size_t available )
    {
        std::cout << msg << std::endl;
        return true;
    }
};

void symbols( gmd::tcp_publisher& tcp, size_t count )
{
    std::ifstream sym_file( "symbols.txt" );
    if( sym_file.good() ) {
        std::string sym;
        for( int i=0; i<count; i++ ) {
            std::getline( sym_file, sym );
            if( sym.size() ) {
                tcp.symbol( "XLON", sym.c_str() );
            }
        }
    }
}

int main( int argc, char** argv )
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
    symbols( tcp, atoi( argv[1] ) );
    tcp.subscribe( new my_handler );
    tcp.start();
}
