/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDSINGLEQUOTEGROUPHDR_HPP_
#define _GMDSINGLEQUOTEGROUPHDR_HPP_

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

class GmdSingleQuoteGroupHdr
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

public:
    GmdSingleQuoteGroupHdr &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 2)), 0))
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
        return 2;
    }


    static const sbe_uint8_t blockLengthNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t blockLengthMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t blockLengthMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t blockLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 0)));
    }

    GmdSingleQuoteGroupHdr &blockLength(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 0)) = (value);
        return *this;
    }

    static const sbe_uint8_t numInGroupNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t numInGroupMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t numInGroupMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t numInGroup(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 1)));
    }

    GmdSingleQuoteGroupHdr &numInGroup(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 1)) = (value);
        return *this;
    }
};
}

#endif
