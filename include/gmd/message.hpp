#pragma once

#include "gmd/sbe/GmdQuote.hpp"
#include "gmd/sbe/GmdTrade.hpp"
#include "gmd/sbe/GmdLogonRequest.hpp"
#include "gmd/sbe/GmdSubscriptionRequest.hpp"
#include <ostream>

namespace gmd { class trade; class quote; class message; }

std::ostream& operator<<( std::ostream&, const gmd::trade& );
std::ostream& operator<<( std::ostream&, const gmd::quote& );
std::ostream& operator<<( std::ostream&, const gmd::message& );

namespace gmd {

class trade
{
public:
    trade( char*, size_t );
    trade( trade&& );

    const char* symbol();
    int64_t price();
    uint32_t size();

private:
    friend std::ostream& ::operator<<( std::ostream&, const trade& );
    sbe::GmdTrade trade_;

    char* buf_;
    size_t len_;
};

class quote
{
public:
    quote( char*, size_t );
    quote( quote&& );

    const char* symbol();

private:
    friend std::ostream& ::operator<<( std::ostream&, const quote& );
    sbe::GmdQuote quote_;
    sbe::GmdQuoteHdr* header_;

    char* buf_;
    size_t len_;
};

class message
{
public:
    message( char*, size_t );

    char* get_buffer() const;
    size_t get_length() const;
    int get_type() const;

    bool is_trade() const;
    bool is_quote() const;

    trade to_trade() const;
    quote to_quote() const;

private:
    friend std::ostream& ::operator<<( std::ostream&, const message& );
    sbe::GmdPacketHdr phdr_;
    sbe::GmdMessageHdr mhdr_;

    char* buf_;
    size_t len_;
};

#include "message.inl"

}
