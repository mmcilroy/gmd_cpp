inline message::message( char* buf, size_t len ) :
    buf_( buf ),
    len_( len )
{
    phdr_.wrap( buf, 0, 0, sbe::GmdPacketHdr::size() );
    mhdr_.wrap( buf + sbe::GmdPacketHdr::size(), 0, 0, sbe::GmdMessageHdr::size() );
}

inline char* message::get_buffer() const
{
    return buf_;
}

inline size_t message::get_length() const
{
    return len_;
}

inline int message::get_type() const
{
    return mhdr_.messageType();
}

inline bool message::is_trade() const
{
    return mhdr_.messageType() == 13;
}

inline bool message::is_quote() const
{
    return mhdr_.messageType() == 12;
}

inline trade message::to_trade() const
{
    return trade( buf_, len_ );
}

inline quote message::to_quote() const
{
    return quote( buf_, len_ );
}

inline trade::trade( char* buf, size_t len ) :
    buf_( buf ),
    len_( len )
{
    trade_.wrapForDecode( buf, 0, sbe::GmdTrade::sbeBlockLength(), 0, len );
}

inline trade::trade( trade&& t ) :
    trade( t.buf_, t.len_ )
{
}

inline const char* trade::symbol()
{
    return trade_.symbol();
}

inline int64_t trade::price()
{
    return trade_.tradePrice();
}

inline uint32_t trade::size()
{
    return trade_.tradeSize();
}

inline quote::quote( char* buf, size_t len ) :
    buf_( buf ),
    len_( len )
{
    quote_.wrapForDecode( buf, 0, sbe::GmdQuote::sbeBlockLength(), 0, len );
    header_ = &quote_.quoteHdr();
}

inline quote::quote( quote&& q ) :
    quote( q.buf_, q.len_ )
{
}

inline const char* quote::symbol()
{
    return header_->symbol();
}
