#pragma once

#include <memory>

namespace gmd {

class handler;
class tcp_params;

class tcp_publisher
{
public:
    tcp_publisher();

    ~tcp_publisher();

    // connect a tcp session
    void session( const char* market, const tcp_params& params );

    // issue a subscription request to market for symbol
    void symbol( const char* market, const char* symbol );

    // flip between primary and secondary sessions
    void failover( const char* market );

    // keep a pointer to handler
    // launch publishing thread
    void subscribe( handler* );

    // start a dedicated thread for dispatching to handler
    // thread will exit when all handlers complete
    // once started user cannot call subscribe
    void start();

    // cleanup
    void stop();

private:
    class impl; std::unique_ptr< impl > impl_;
};

}
