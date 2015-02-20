/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDQUOTE_HPP_
#define _GMDQUOTE_HPP_

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

class GmdQuote
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    GmdQuote(const GmdQuote&) {}

public:

    GmdQuote(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)102;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)4;
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

    GmdQuote &wrapForEncode(char *buffer, const int offset, const int bufferLength)
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

    GmdQuote &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion,
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

    static const int quoteHdrId(void)
    {
        return 3;
    }

    static const int quoteHdrSinceVersion(void)
    {
         return 0;
    }

    bool quoteHdrInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *quoteHdrMetaAttribute(const MetaAttribute::Attribute metaAttribute)
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
    GmdQuoteHdr quoteHdr_;

public:

    GmdQuoteHdr &quoteHdr(void)
    {
        quoteHdr_.wrap(buffer_, offset_ + 72, actingVersion_, bufferLength_);
        return quoteHdr_;
    }

    class SingleQuoteGroup
    {
    private:
        char *buffer_;
        int bufferLength_;
        int *positionPtr_;
        int blockLength_;
        int count_;
        int index_;
        int offset_;
        int actingVersion_;
        GmdSingleQuoteGroupHdr dimensions_;

    public:

        void wrapForDecode(char *buffer, int *pos, const int actingVersion, const int bufferLength)
        {
            buffer_ = buffer;
            bufferLength_ = bufferLength;
            dimensions_.wrap(buffer_, *pos, actingVersion, bufferLength);
            blockLength_ = dimensions_.blockLength();
            count_ = dimensions_.numInGroup();
            index_ = -1;
            actingVersion_ = actingVersion;
            positionPtr_ = pos;
            *positionPtr_ = *positionPtr_ + 2;
        }

        void wrapForEncode(char *buffer, const int count,
                           int *pos, const int actingVersion, const int bufferLength)
        {
            buffer_ = buffer;
            bufferLength_ = bufferLength;
            dimensions_.wrap(buffer_, *pos, actingVersion, bufferLength);
            dimensions_.blockLength((sbe_uint8_t)32);
            dimensions_.numInGroup((sbe_uint8_t)count);
            index_ = -1;
            count_ = count;
            blockLength_ = 32;
            actingVersion_ = actingVersion;
            positionPtr_ = pos;
            *positionPtr_ = *positionPtr_ + 2;
        }

        static const int sbeHeaderSize()
        {
            return 2;
        }

        static const int sbeBlockLength()
        {
            return 32;
        }

        int count(void) const
        {
            return count_;
        }

        bool hasNext(void) const
        {
            return index_ + 1 < count_;
        }

        SingleQuoteGroup &next(void)
        {
            offset_ = *positionPtr_;
            if (SBE_BOUNDS_CHECK_EXPECT(( (offset_ + blockLength_) > bufferLength_ ),0))
            {
                throw std::runtime_error("buffer too short to support next group index [E108]");
            }
            *positionPtr_ = offset_ + blockLength_;
            ++index_;

            return *this;
        }


        static const int quotePriceId(void)
        {
            return 5;
        }

        static const int quotePriceSinceVersion(void)
        {
             return 0;
        }

        bool quotePriceInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *quotePriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_int64_t quotePriceNullValue()
        {
            return LLONG_MIN;
        }

        static const sbe_int64_t quotePriceMinValue()
        {
            return -9223372036854775807L;
        }

        static const sbe_int64_t quotePriceMaxValue()
        {
            return 9223372036854775807L;
        }

        sbe_int64_t quotePrice(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_int64_t *)(buffer_ + offset_ + 0)));
        }

        SingleQuoteGroup &quotePrice(const sbe_int64_t value)
        {
            *((sbe_int64_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            return *this;
        }

        static const int quoteSizeId(void)
        {
            return 6;
        }

        static const int quoteSizeSinceVersion(void)
        {
             return 0;
        }

        bool quoteSizeInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *quoteSizeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint32_t quoteSizeNullValue()
        {
            return ULONG_MAX;
        }

        static const sbe_uint32_t quoteSizeMinValue()
        {
            return 0;
        }

        static const sbe_uint32_t quoteSizeMaxValue()
        {
            return 4294967293;
        }

        sbe_uint32_t quoteSize(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 8)));
        }

        SingleQuoteGroup &quoteSize(const sbe_uint32_t value)
        {
            *((sbe_uint32_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static const int numberOfOrdersId(void)
        {
            return 7;
        }

        static const int numberOfOrdersSinceVersion(void)
        {
             return 0;
        }

        bool numberOfOrdersInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *numberOfOrdersMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint16_t numberOfOrdersNullValue()
        {
            return USHRT_MAX;
        }

        static const sbe_uint16_t numberOfOrdersMinValue()
        {
            return (sbe_uint16_t)0;
        }

        static const sbe_uint16_t numberOfOrdersMaxValue()
        {
            return (sbe_uint16_t)65534;
        }

        sbe_uint16_t numberOfOrders(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 12)));
        }

        SingleQuoteGroup &numberOfOrders(const sbe_uint16_t value)
        {
            *((sbe_uint16_t *)(buffer_ + offset_ + 12)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            return *this;
        }

        static const int sideId(void)
        {
            return 8;
        }

        static const int sideSinceVersion(void)
        {
             return 0;
        }

        bool sideInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *sideMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_char_t sideNullValue()
        {
            return (sbe_char_t)0;
        }

        static const sbe_char_t sideMinValue()
        {
            return (sbe_char_t)32;
        }

        static const sbe_char_t sideMaxValue()
        {
            return (sbe_char_t)126;
        }

        sbe_char_t side(void) const
        {
            return (*((sbe_char_t *)(buffer_ + offset_ + 14)));
        }

        SingleQuoteGroup &side(const sbe_char_t value)
        {
            *((sbe_char_t *)(buffer_ + offset_ + 14)) = (value);
            return *this;
        }

        static const int marketCenterIdId(void)
        {
            return 9;
        }

        static const int marketCenterIdSinceVersion(void)
        {
             return 0;
        }

        bool marketCenterIdInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *marketCenterIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint8_t marketCenterIdNullValue()
        {
            return UCHAR_MAX;
        }

        static const sbe_uint8_t marketCenterIdMinValue()
        {
            return (sbe_uint8_t)0;
        }

        static const sbe_uint8_t marketCenterIdMaxValue()
        {
            return (sbe_uint8_t)254;
        }

        sbe_uint8_t marketCenterId(void) const
        {
            return (*((sbe_uint8_t *)(buffer_ + offset_ + 15)));
        }

        SingleQuoteGroup &marketCenterId(const sbe_uint8_t value)
        {
            *((sbe_uint8_t *)(buffer_ + offset_ + 15)) = (value);
            return *this;
        }

        static const int marketMakerIdId(void)
        {
            return 10;
        }

        static const int marketMakerIdSinceVersion(void)
        {
             return 0;
        }

        bool marketMakerIdInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *marketMakerIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint32_t marketMakerIdNullValue()
        {
            return ULONG_MAX;
        }

        static const sbe_uint32_t marketMakerIdMinValue()
        {
            return 0;
        }

        static const sbe_uint32_t marketMakerIdMaxValue()
        {
            return 4294967293;
        }

        sbe_uint32_t marketMakerId(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 16)));
        }

        SingleQuoteGroup &marketMakerId(const sbe_uint32_t value)
        {
            *((sbe_uint32_t *)(buffer_ + offset_ + 16)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static const int padId(void)
        {
            return 11;
        }

        static const int padSinceVersion(void)
        {
             return 0;
        }

        bool padInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *padMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint16_t padNullValue()
        {
            return USHRT_MAX;
        }

        static const sbe_uint16_t padMinValue()
        {
            return (sbe_uint16_t)0;
        }

        static const sbe_uint16_t padMaxValue()
        {
            return (sbe_uint16_t)65534;
        }

        sbe_uint16_t pad(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 20)));
        }

        SingleQuoteGroup &pad(const sbe_uint16_t value)
        {
            *((sbe_uint16_t *)(buffer_ + offset_ + 20)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            return *this;
        }

        static const int indexId(void)
        {
            return 12;
        }

        static const int indexSinceVersion(void)
        {
             return 0;
        }

        bool indexInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *indexMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint16_t indexNullValue()
        {
            return USHRT_MAX;
        }

        static const sbe_uint16_t indexMinValue()
        {
            return (sbe_uint16_t)0;
        }

        static const sbe_uint16_t indexMaxValue()
        {
            return (sbe_uint16_t)65534;
        }

        sbe_uint16_t index(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 22)));
        }

        SingleQuoteGroup &index(const sbe_uint16_t value)
        {
            *((sbe_uint16_t *)(buffer_ + offset_ + 22)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            return *this;
        }

        static const int feedIdId(void)
        {
            return 13;
        }

        static const int feedIdSinceVersion(void)
        {
             return 0;
        }

        bool feedIdInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *feedIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
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
            return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 24)));
        }

        SingleQuoteGroup &feedId(const sbe_uint16_t value)
        {
            *((sbe_uint16_t *)(buffer_ + offset_ + 24)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            return *this;
        }

        static const int quoteFlagsId(void)
        {
            return 14;
        }

        static const int quoteFlagsSinceVersion(void)
        {
             return 0;
        }

        bool quoteFlagsInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *quoteFlagsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint8_t quoteFlagsNullValue()
        {
            return UCHAR_MAX;
        }

        static const sbe_uint8_t quoteFlagsMinValue()
        {
            return (sbe_uint8_t)0;
        }

        static const sbe_uint8_t quoteFlagsMaxValue()
        {
            return (sbe_uint8_t)254;
        }

        sbe_uint8_t quoteFlags(void) const
        {
            return (*((sbe_uint8_t *)(buffer_ + offset_ + 26)));
        }

        SingleQuoteGroup &quoteFlags(const sbe_uint8_t value)
        {
            *((sbe_uint8_t *)(buffer_ + offset_ + 26)) = (value);
            return *this;
        }

        static const int subMarketCenterIdId(void)
        {
            return 15;
        }

        static const int subMarketCenterIdSinceVersion(void)
        {
             return 0;
        }

        bool subMarketCenterIdInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *subMarketCenterIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint8_t subMarketCenterIdNullValue()
        {
            return UCHAR_MAX;
        }

        static const sbe_uint8_t subMarketCenterIdMinValue()
        {
            return (sbe_uint8_t)0;
        }

        static const sbe_uint8_t subMarketCenterIdMaxValue()
        {
            return (sbe_uint8_t)254;
        }

        sbe_uint8_t subMarketCenterId(void) const
        {
            return (*((sbe_uint8_t *)(buffer_ + offset_ + 27)));
        }

        SingleQuoteGroup &subMarketCenterId(const sbe_uint8_t value)
        {
            *((sbe_uint8_t *)(buffer_ + offset_ + 27)) = (value);
            return *this;
        }

        static const int aggregateSizeId(void)
        {
            return 16;
        }

        static const int aggregateSizeSinceVersion(void)
        {
             return 0;
        }

        bool aggregateSizeInActingVersion(void)
        {
            return (actingVersion_ >= 0) ? true : false;
        }


        static const char *aggregateSizeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
            }

            return "";
        }

        static const sbe_uint32_t aggregateSizeNullValue()
        {
            return ULONG_MAX;
        }

        static const sbe_uint32_t aggregateSizeMinValue()
        {
            return 0;
        }

        static const sbe_uint32_t aggregateSizeMaxValue()
        {
            return 4294967293;
        }

        sbe_uint32_t aggregateSize(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 28)));
        }

        SingleQuoteGroup &aggregateSize(const sbe_uint32_t value)
        {
            *((sbe_uint32_t *)(buffer_ + offset_ + 28)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }
    };

private:
    SingleQuoteGroup singleQuoteGroup_;

public:

    static const int singleQuoteGroupId(void)
    {
        return 4;
    }


    SingleQuoteGroup &singleQuoteGroup(void)
    {
        singleQuoteGroup_.wrapForDecode(buffer_, positionPtr_, actingVersion_, bufferLength_);
        return singleQuoteGroup_;
    }

    SingleQuoteGroup &singleQuoteGroupCount(const int count)
    {
        singleQuoteGroup_.wrapForEncode(buffer_, count, positionPtr_, actingVersion_, bufferLength_);
        return singleQuoteGroup_;
    }
};
}
#endif
