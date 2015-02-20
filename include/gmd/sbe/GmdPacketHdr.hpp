/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDPACKETHDR_HPP_
#define _GMDPACKETHDR_HPP_

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

class GmdPacketHdr
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

public:
    GmdPacketHdr &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 24)), 0))
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
        return 24;
    }


    static const sbe_uint8_t protocolIdNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t protocolIdMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t protocolIdMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t protocolId(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 0)));
    }

    GmdPacketHdr &protocolId(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 0)) = (value);
        return *this;
    }

    static const sbe_uint8_t headerLengthNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t headerLengthMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t headerLengthMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t headerLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 1)));
    }

    GmdPacketHdr &headerLength(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 1)) = (value);
        return *this;
    }

    static const sbe_uint8_t packetCategoryNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t packetCategoryMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t packetCategoryMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t packetCategory(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 2)));
    }

    GmdPacketHdr &packetCategory(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 2)) = (value);
        return *this;
    }

    static const sbe_uint8_t versionIdNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t versionIdMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t versionIdMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t versionId(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 3)));
    }

    GmdPacketHdr &versionId(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 3)) = (value);
        return *this;
    }

    static const sbe_uint16_t packetLengthNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t packetLengthMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t packetLengthMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t packetLength(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 4)));
    }

    GmdPacketHdr &packetLength(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 4)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint16_t numberOfMessagesNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t numberOfMessagesMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t numberOfMessagesMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t numberOfMessages(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 6)));
    }

    GmdPacketHdr &numberOfMessages(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 6)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint64_t packetSequenceNumberNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t packetSequenceNumberMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t packetSequenceNumberMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t packetSequenceNumber(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 8)));
    }

    GmdPacketHdr &packetSequenceNumber(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t sendTimestampNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t sendTimestampMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t sendTimestampMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t sendTimestamp(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 16)));
    }

    GmdPacketHdr &sendTimestamp(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 16)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}

#endif
