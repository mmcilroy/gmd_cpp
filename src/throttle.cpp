#include "gmd/throttle.hpp"
#include "gmd/message.hpp"
#include <cstring>

using namespace gmd;

throttle::throttle()
{
    watch_.start();
}

bool throttle::on_next( const message& msg, size_t available )
{
    // make a copy of the trade / quote and store it in our map
    if( msg.is_quote() ) {
        std::memcpy( quotes_[ msg.to_quote().symbol() ], msg.get_buffer(), msg.get_length() );
    } else if( msg.is_trade() ) {
        std::memcpy( trades_[ msg.to_trade().symbol() ], msg.get_buffer(), msg.get_length() );
    }

    // publish most recent trade and quote once time period expires
    if( watch_.elapsed_ms() > 3000 ) {
        for( auto i = quotes_.begin(); i != quotes_.end(); i++ ) {
            publish( message( i->second, 512 ) );
        }
        for( auto i = trades_.begin(); i != trades_.end(); i++ ) {
            publish( message( i->second, 512 ) );
        }

        // reset state for next set of messages
        trades_.clear();
        quotes_.clear();
        watch_.start();
    }

    // we are active as long we have an active subscriber
    return handlers_.size() > 0;
}

void throttle::subscribe( handler* h )
{
    handlers_.push_back( h );
}

void throttle::publish( const message& msg )
{
    std::vector< std::vector< handler* >::iterator > del;

    // publish to subscribers
    for( auto i = handlers_.begin(); i != handlers_.end(); i++ ) {
        if( !(*i)->on_next( msg, 0 ) ) {
            del.push_back( i );
        }
    }

    // remove completed handlers
    for( auto j = del.begin(); j != del.end(); j++ ) {
        handlers_.erase( *j );
    }
}
