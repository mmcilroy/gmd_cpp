/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDQUOTEHDR_HPP_
#define _GMDQUOTEHDR_HPP_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#include <sbe/sbe.hpp>

using namespace sbe;

namespace sbe {

class GmdQuoteHdr
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

public:
    GmdQuoteHdr &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 30)), 0))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        buffer_ = buffer;
        offset_ = offset;
        actingVersion_ = actingVersion;
        return *this;
    }

    static const int size(void)
    {
        return 30;
    }


    static const sbe_char_t symbolNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t symbolMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t symbolMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int symbolLength(void)
    {
        return 24;
    }

    const char *symbol(void) const
    {
        return (buffer_ + offset_ + 0);
    }

    sbe_char_t symbol(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 0 + (index * 1))));
    }

    void symbol(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 0 + (index * 1))) = (value);
    }

    int getSymbol(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getSymbol [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 0, length);
        return length;
    }

    GmdQuoteHdr &putSymbol(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 0, src, 24);
        return *this;
    }

    static const sbe_char_t quoteConditionNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t quoteConditionMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t quoteConditionMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int quoteConditionLength(void)
    {
        return 4;
    }

    const char *quoteCondition(void) const
    {
        return (buffer_ + offset_ + 24);
    }

    sbe_char_t quoteCondition(const int index) const
    {
        if (index < 0 || index >= 4)
        {
            throw std::runtime_error("index out of range for quoteCondition [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 24 + (index * 1))));
    }

    void quoteCondition(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 4)
        {
            throw std::runtime_error("index out of range for quoteCondition [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 24 + (index * 1))) = (value);
    }

    int getQuoteCondition(char *dst, const int length) const
    {
        if (length > 4)
        {
             throw std::runtime_error("length too large for getQuoteCondition [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 24, length);
        return length;
    }

    GmdQuoteHdr &putQuoteCondition(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 24, src, 4);
        return *this;
    }

    static const sbe_uint16_t quoteFlagsNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t quoteFlagsMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t quoteFlagsMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t quoteFlags(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 28)));
    }

    GmdQuoteHdr &quoteFlags(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 28)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }
};
}

#endif
