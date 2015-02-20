#pragma once

#include <functional>
#include <memory>
#include <string>

namespace gmd {

class message;

// this structure holds all parameters required to establish a gmd tcp session
struct tcp_params
{
    std::string host[2]; // primary and optional secondary ip
    std::string port[2]; // primary and optional secondary port
    std::string user;    // user id for login
    std::string pass;    // password for login
    int feed;            // feed id
};

// tcp_connector allows the user to subscribe to multiple gmd sessions using tcp
// gmd messages are passed back to the user via a callback function
class tcp_connector
{
public:
    // constructor
    // user must a supply a callback function which will called on receipt of a message
    tcp_connector( std::function< void( const message& ) > );

    ~tcp_connector();

    // establish a new session for market using supplied parameters
    void session( const std::string& market, const tcp_params& params );

    // subscribe to a symbol on specified market
    void symbol( const std::string& market, const std::string& symbol );

    // for specified market switch the active connection from primary to
    // secondary or vice versa
    void failover( const std::string& market );

    // start dispatching messages to callback function
    // this function will not return until stop is called
    void start();

    // stop dispatching
    void stop();

private:
    class impl; std::unique_ptr< impl > impl_;
};

}
