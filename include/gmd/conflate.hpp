#pragma once

#include "gmd/handler.hpp"
#include <map>
#include <vector>

namespace gmd {

// conflated message handler
// publishes only the most recent quote update to subscribers
// every trade is published
class conflate : public handler
{
public:
    bool on_next( const message&, size_t available );

    void subscribe( handler* );

private:
    void publish( const message& );

    std::map< std::string, const message* > quotes_;
    std::vector< handler* > handlers_;
};

}
