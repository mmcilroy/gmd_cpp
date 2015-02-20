#pragma once

#include "gmd/handler.hpp"
#include "pulsar/stopwatch.hpp"
#include <map>
#include <vector>

namespace gmd {

// throttled message handler
// publishes only the most recent quote, trade message every x milliseconds
class throttle : public handler
{
public:
    throttle();

    bool on_next( const message&, size_t available );

    void subscribe( handler* );

private:
    void publish( const message& );

    pulsar::stopwatch watch_;
    std::map< std::string, char[512] > quotes_;
    std::map< std::string, char[512] > trades_;
    std::vector< handler* > handlers_;
};

}
