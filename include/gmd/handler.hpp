#pragma once

#include <cstddef>

namespace gmd {

class message;

struct handler
{
    virtual bool on_next( const message&, size_t available ) = 0;
};

}
