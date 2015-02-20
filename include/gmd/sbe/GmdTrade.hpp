/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDTRADE_HPP_
#define _GMDTRADE_HPP_

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

#include <sbe/GmdSingleQuoteGroupHdr.hpp>
#include <sbe/GmdQuoteHdr.hpp>
#include <sbe/GmdMessageHdr.hpp>
#include <sbe/GmdPacketHdr.hpp>

using namespace sbe;

namespace sbe {

class GmdTrade
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    GmdTrade(const GmdTrade&) {}

public:

    GmdTrade(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)108;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)3;
    }

    static const sbe_uint16_t sbeSchemaId(void)
    {
        return (sbe_uint16_t)1;
    }

    static const sbe_uint16_t sbeSchemaVersion(void)
    {
        return (sbe_uint16_t)1;
    }

    static const char *sbeSemanticType(void)
    {
        return "";
    }

    sbe_uint64_t offset(void) const
    {
        return offset_;
    }

    GmdTrade &wrapForEncode(char *buffer, const int offset, const int bufferLength)
    {
        buffer_ = buffer;
        offset_ = offset;
        bufferLength_ = bufferLength;
        actingBlockLength_ = sbeBlockLength();
        actingVersion_ = sbeSchemaVersion();
        position(offset + actingBlockLength_);
        positionPtr_ = &position_;
        return *this;
    }

    GmdTrade &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion,
                         const int bufferLength)
    {
        buffer_ = buffer;
        offset_ = offset;
        bufferLength_ = bufferLength;
        actingBlockLength_ = actingBlockLength;
        actingVersion_ = actingVersion;
        positionPtr_ = &position_;
        position(offset + actingBlockLength_);
        return *this;
    }

    sbe_uint64_t position(void) const
    {
        return position_;
    }

    void position(const sbe_uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > bufferLength_), 0))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        position_ = position;
    }

    int size(void) const
    {
        return position() - offset_;
    }

    char *buffer(void)
    {
        return buffer_;
    }

    int actingVersion(void) const
    {
        return actingVersion_;
    }

    static const int packetHdrId(void)
    {
        return 1;
    }

    static const int packetHdrSinceVersion(void)
    {
         return 0;
    }

    bool packetHdrInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *packetHdrMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

private:
    GmdPacketHdr packetHdr_;

public:

    GmdPacketHdr &packetHdr(void)
    {
        packetHdr_.wrap(buffer_, offset_ + 0, actingVersion_, bufferLength_);
        return packetHdr_;
    }

    static const int messageHdrId(void)
    {
        return 2;
    }

    static const int messageHdrSinceVersion(void)
    {
         return 0;
    }

    bool messageHdrInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *messageHdrMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

private:
    GmdMessageHdr messageHdr_;

public:

    GmdMessageHdr &messageHdr(void)
    {
        messageHdr_.wrap(buffer_, offset_ + 24, actingVersion_, bufferLength_);
        return messageHdr_;
    }

    static const int symbolId(void)
    {
        return 3;
    }

    static const int symbolSinceVersion(void)
    {
         return 0;
    }

    bool symbolInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *symbolMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
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
        return (buffer_ + offset_ + 72);
    }

    sbe_char_t symbol(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 72 + (index * 1))));
    }

    void symbol(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 72 + (index * 1))) = (value);
    }

    int getSymbol(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getSymbol [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 72, length);
        return length;
    }

    GmdTrade &putSymbol(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 72, src, 24);
        return *this;
    }

    static const int tradePriceId(void)
    {
        return 4;
    }

    static const int tradePriceSinceVersion(void)
    {
         return 0;
    }

    bool tradePriceInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *tradePriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_int64_t tradePriceNullValue()
    {
        return LLONG_MIN;
    }

    static const sbe_int64_t tradePriceMinValue()
    {
        return -9223372036854775807L;
    }

    static const sbe_int64_t tradePriceMaxValue()
    {
        return 9223372036854775807L;
    }

    sbe_int64_t tradePrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_int64_t *)(buffer_ + offset_ + 96)));
    }

    GmdTrade &tradePrice(const sbe_int64_t value)
    {
        *((sbe_int64_t *)(buffer_ + offset_ + 96)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const int tradeSizeId(void)
    {
        return 5;
    }

    static const int tradeSizeSinceVersion(void)
    {
         return 0;
    }

    bool tradeSizeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *tradeSizeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint32_t tradeSizeNullValue()
    {
        return ULONG_MAX;
    }

    static const sbe_uint32_t tradeSizeMinValue()
    {
        return 0;
    }

    static const sbe_uint32_t tradeSizeMaxValue()
    {
        return 4294967293;
    }

    sbe_uint32_t tradeSize(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 104)));
    }

    GmdTrade &tradeSize(const sbe_uint32_t value)
    {
        *((sbe_uint32_t *)(buffer_ + offset_ + 104)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }
};
}
#endif
