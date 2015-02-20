#include "gmd/message.hpp"

std::ostream& operator<<( std::ostream& o, const gmd::trade& m )
{
    o << "Trade: "
      << "symbol: '" << m.trade_.symbol() << "', "
      << "price: '" << m.trade_.tradePrice() << "', "
      << "size: " << m.trade_.tradeSize();

    return o;
}

std::ostream& operator<<( std::ostream& o, const gmd::quote& m )
{
    sbe::GmdQuote& n = const_cast< sbe::GmdQuote& >( m.quote_ );

    sbe::GmdQuoteHdr& qhdr = n.quoteHdr();
    o << "Quote: "
      << "symbol: '" << qhdr.symbol() << "', "
      << "condition: '" << qhdr.quoteCondition() << "', "
      << "flags: " << qhdr.quoteFlags();

    sbe::GmdQuote::SingleQuoteGroup& qgrp = n.singleQuoteGroup();
    while( qgrp.hasNext() )
    {
        qgrp.next();
        o << std::endl
          << "\t"
          << "price: " << qgrp.quotePrice() << ", "
          << "size: " << qgrp.quoteSize() << ", "
          << "numOrders: " << qgrp.numberOfOrders() << ", "
          << "side: " << qgrp.side() << ", "
          << "feedId: " << qgrp.feedId();
    }

    return o;
}

std::ostream& operator<<( std::ostream& o, const gmd::message& m )
{
    o << "PacketHdr: "
      << "packetLength=" << m.phdr_.packetLength() << ", "
      << "headerLength=" << (int)m.phdr_.headerLength() << ", "
      << "numberOfMessages=" << m.phdr_.numberOfMessages() << std::endl

      << "MessageHdr: "
      << "messageLength=" << m.mhdr_.messageLength() << ", "
      << "messageHeaderLength=" << (int)m.mhdr_.messageHdrLength() << ", "
      << "feedId=" << m.mhdr_.feedId() << ", "
      << "messageType=" << m.mhdr_.messageType() << ", "
      << "turnKey=" << m.mhdr_.turnKey() << ", "
      << "exchangeTimeStamp=" << m.mhdr_.exchangeTimeStamp() << ", "
      << "exchangeSequenceNumber=" << m.mhdr_.exchangeSequenceNumber() << std::endl;

    if( m.is_quote() ) {
        o << m.to_quote();
    } else if( m.is_trade() ) {
        o << m.to_trade();
    }

    return o;
}

/*
inline std::ostream& operator<<( std::ostream& o, const sbe::GmdSubscriptionRequest& r )
{
    o << "SubscriptionRequest: "
      << "symbol: '" << r.symbol();

    return o;
}
*/
