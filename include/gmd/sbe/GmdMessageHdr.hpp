/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDMESSAGEHDR_HPP_
#define _GMDMESSAGEHDR_HPP_

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

class GmdMessageHdr
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

public:
    GmdMessageHdr &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 48)), 0))
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
        return 48;
    }


    static const sbe_uint16_t messageTypeNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t messageTypeMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t messageTypeMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t messageType(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 0)));
    }

    GmdMessageHdr &messageType(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint16_t messageLengthNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t messageLengthMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t messageLengthMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t messageLength(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 2)));
    }

    GmdMessageHdr &messageLength(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 2)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint16_t feedIdNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t feedIdMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t feedIdMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t feedId(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 4)));
    }

    GmdMessageHdr &feedId(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 4)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint8_t messageHdrLengthNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t messageHdrLengthMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t messageHdrLengthMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t messageHdrLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 6)));
    }

    GmdMessageHdr &messageHdrLength(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 6)) = (value);
        return *this;
    }

    static const sbe_uint8_t updateTypeNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t updateTypeMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t updateTypeMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t updateType(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 7)));
    }

    GmdMessageHdr &updateType(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 7)) = (value);
        return *this;
    }

    static const sbe_uint64_t exchangeSequenceNumberNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t exchangeSequenceNumberMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t exchangeSequenceNumberMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t exchangeSequenceNumber(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 8)));
    }

    GmdMessageHdr &exchangeSequenceNumber(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint32_t symbolSequenceNumberNullValue()
    {
        return ULONG_MAX;
    }

    static const sbe_uint32_t symbolSequenceNumberMinValue()
    {
        return 0;
    }

    static const sbe_uint32_t symbolSequenceNumberMaxValue()
    {
        return 4294967293;
    }

    sbe_uint32_t symbolSequenceNumber(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 16)));
    }

    GmdMessageHdr &symbolSequenceNumber(const sbe_uint32_t value)
    {
        *((sbe_uint32_t *)(buffer_ + offset_ + 16)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const sbe_uint8_t feedSubIdNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t feedSubIdMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t feedSubIdMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t feedSubId(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 20)));
    }

    GmdMessageHdr &feedSubId(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 20)) = (value);
        return *this;
    }

    static const sbe_char_t reservedNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t reservedMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t reservedMaxValue()
    {
        return (sbe_char_t)126;
    }

    sbe_char_t reserved(void) const
    {
        return (*((sbe_char_t *)(buffer_ + offset_ + 21)));
    }

    GmdMessageHdr &reserved(const sbe_char_t value)
    {
        *((sbe_char_t *)(buffer_ + offset_ + 21)) = (value);
        return *this;
    }

    static const sbe_uint16_t timeIndexNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t timeIndexMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t timeIndexMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t timeIndex(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 22)));
    }

    GmdMessageHdr &timeIndex(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 22)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const sbe_uint64_t exchangeTimeStampNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t exchangeTimeStampMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t exchangeTimeStampMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t exchangeTimeStamp(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 24)));
    }

    GmdMessageHdr &exchangeTimeStamp(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 24)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t acqTimeStampNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t acqTimeStampMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t acqTimeStampMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t acqTimeStamp(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 32)));
    }

    GmdMessageHdr &acqTimeStamp(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 32)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t turnKeyNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t turnKeyMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t turnKeyMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t turnKey(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 40)));
    }

    GmdMessageHdr &turnKey(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 40)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}

#endif
