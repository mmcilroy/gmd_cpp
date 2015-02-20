#include "gmd/conflate.hpp"
#include "gmd/message.hpp"

using namespace gmd;

bool conflate::on_next( const message& msg, size_t available )
{
    // store the quote in our map
    // publish all trades
    if( msg.is_quote() ) {
        quotes_[ msg.to_quote().symbol() ] = &msg;
    } else {
        publish( msg );
    }

    // if there are no more messages available publish all the most recent
    // quote for each symbol
    if( available == 0 && quotes_.size() ) {
        for( auto i = quotes_.begin(); i != quotes_.end(); i++ ) {
            publish( *i->second );
        }
        quotes_.clear();
    }

    // we are active as long we have an active subscriber
    return handlers_.size() > 0;
}

void conflate::subscribe( handler* h )
{
    handlers_.push_back( h );
}

void conflate::publish( const message& msg )
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
