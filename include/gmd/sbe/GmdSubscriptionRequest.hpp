/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDSUBSCRIPTIONREQUEST_HPP_
#define _GMDSUBSCRIPTIONREQUEST_HPP_

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

class GmdSubscriptionRequest
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    GmdSubscriptionRequest(const GmdSubscriptionRequest&) {}

public:

    GmdSubscriptionRequest(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)128;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)2;
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

    GmdSubscriptionRequest &wrapForEncode(char *buffer, const int offset, const int bufferLength)
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

    GmdSubscriptionRequest &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion,
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

    static const int numberOfSymbolsId(void)
    {
        return 3;
    }

    static const int numberOfSymbolsSinceVersion(void)
    {
         return 0;
    }

    bool numberOfSymbolsInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *numberOfSymbolsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t numberOfSymbolsNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t numberOfSymbolsMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t numberOfSymbolsMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t numberOfSymbols(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 72)));
    }

    GmdSubscriptionRequest &numberOfSymbols(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 72)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int subscriptionInfoSizeId(void)
    {
        return 4;
    }

    static const int subscriptionInfoSizeSinceVersion(void)
    {
         return 0;
    }

    bool subscriptionInfoSizeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *subscriptionInfoSizeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint8_t subscriptionInfoSizeNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t subscriptionInfoSizeMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t subscriptionInfoSizeMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t subscriptionInfoSize(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 74)));
    }

    GmdSubscriptionRequest &subscriptionInfoSize(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 74)) = (value);
        return *this;
    }

    static const int reserved1Id(void)
    {
        return 5;
    }

    static const int reserved1SinceVersion(void)
    {
         return 0;
    }

    bool reserved1InActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *reserved1MetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t reserved1NullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t reserved1MinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t reserved1MaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int reserved1Length(void)
    {
        return 5;
    }

    const char *reserved1(void) const
    {
        return (buffer_ + offset_ + 75);
    }

    sbe_char_t reserved1(const int index) const
    {
        if (index < 0 || index >= 5)
        {
            throw std::runtime_error("index out of range for reserved1 [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 75 + (index * 1))));
    }

    void reserved1(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 5)
        {
            throw std::runtime_error("index out of range for reserved1 [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 75 + (index * 1))) = (value);
    }

    int getReserved1(char *dst, const int length) const
    {
        if (length > 5)
        {
             throw std::runtime_error("length too large for getReserved1 [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 75, length);
        return length;
    }

    GmdSubscriptionRequest &putReserved1(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 75, src, 5);
        return *this;
    }

    static const int symbolId(void)
    {
        return 6;
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
        return (buffer_ + offset_ + 80);
    }

    sbe_char_t symbol(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 80 + (index * 1))));
    }

    void symbol(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 80 + (index * 1))) = (value);
    }

    int getSymbol(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getSymbol [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 80, length);
        return length;
    }

    GmdSubscriptionRequest &putSymbol(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 80, src, 24);
        return *this;
    }

    static const int feedIdId(void)
    {
        return 7;
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
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 104)));
    }

    GmdSubscriptionRequest &feedId(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 104)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int marketCenterIdId(void)
    {
        return 8;
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
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 106)));
    }

    GmdSubscriptionRequest &marketCenterId(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 106)) = (value);
        return *this;
    }

    static const int isRangeId(void)
    {
        return 9;
    }

    static const int isRangeSinceVersion(void)
    {
         return 0;
    }

    bool isRangeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *isRangeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint8_t isRangeNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t isRangeMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t isRangeMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t isRange(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 107)));
    }

    GmdSubscriptionRequest &isRange(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 107)) = (value);
        return *this;
    }

    static const int messageTypeMaskId(void)
    {
        return 10;
    }

    static const int messageTypeMaskSinceVersion(void)
    {
         return 0;
    }

    bool messageTypeMaskInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *messageTypeMaskMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t messageTypeMaskNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t messageTypeMaskMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t messageTypeMaskMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t messageTypeMask(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 108)));
    }

    GmdSubscriptionRequest &messageTypeMask(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 108)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int additionalBitMaskId(void)
    {
        return 11;
    }

    static const int additionalBitMaskSinceVersion(void)
    {
         return 0;
    }

    bool additionalBitMaskInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *additionalBitMaskMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t additionalBitMaskNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t additionalBitMaskMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t additionalBitMaskMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t additionalBitMask(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 110)));
    }

    GmdSubscriptionRequest &additionalBitMask(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 110)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int keepSubActiveId(void)
    {
        return 12;
    }

    static const int keepSubActiveSinceVersion(void)
    {
         return 0;
    }

    bool keepSubActiveInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *keepSubActiveMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint8_t keepSubActiveNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t keepSubActiveMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t keepSubActiveMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t keepSubActive(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 112)));
    }

    GmdSubscriptionRequest &keepSubActive(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 112)) = (value);
        return *this;
    }

    static const int subscriptionTypeId(void)
    {
        return 13;
    }

    static const int subscriptionTypeSinceVersion(void)
    {
         return 0;
    }

    bool subscriptionTypeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *subscriptionTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint8_t subscriptionTypeNullValue()
    {
        return UCHAR_MAX;
    }

    static const sbe_uint8_t subscriptionTypeMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t subscriptionTypeMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t subscriptionType(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 113)));
    }

    GmdSubscriptionRequest &subscriptionType(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 113)) = (value);
        return *this;
    }

    static const int numberOfLevelsId(void)
    {
        return 14;
    }

    static const int numberOfLevelsSinceVersion(void)
    {
         return 0;
    }

    bool numberOfLevelsInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *numberOfLevelsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t numberOfLevelsNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t numberOfLevelsMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t numberOfLevelsMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t numberOfLevels(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 114)));
    }

    GmdSubscriptionRequest &numberOfLevels(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 114)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int conflationFactorId(void)
    {
        return 15;
    }

    static const int conflationFactorSinceVersion(void)
    {
         return 0;
    }

    bool conflationFactorInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *conflationFactorMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t conflationFactorNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t conflationFactorMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t conflationFactorMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t conflationFactor(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 116)));
    }

    GmdSubscriptionRequest &conflationFactor(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 116)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int reserved2Id(void)
    {
        return 16;
    }

    static const int reserved2SinceVersion(void)
    {
         return 0;
    }

    bool reserved2InActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *reserved2MetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t reserved2NullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t reserved2MinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t reserved2MaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int reserved2Length(void)
    {
        return 2;
    }

    const char *reserved2(void) const
    {
        return (buffer_ + offset_ + 118);
    }

    sbe_char_t reserved2(const int index) const
    {
        if (index < 0 || index >= 2)
        {
            throw std::runtime_error("index out of range for reserved2 [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 118 + (index * 1))));
    }

    void reserved2(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 2)
        {
            throw std::runtime_error("index out of range for reserved2 [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 118 + (index * 1))) = (value);
    }

    int getReserved2(char *dst, const int length) const
    {
        if (length > 2)
        {
             throw std::runtime_error("length too large for getReserved2 [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 118, length);
        return length;
    }

    GmdSubscriptionRequest &putReserved2(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 118, src, 2);
        return *this;
    }

    static const int turnKeyId(void)
    {
        return 17;
    }

    static const int turnKeySinceVersion(void)
    {
         return 0;
    }

    bool turnKeyInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *turnKeyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 120)));
    }

    GmdSubscriptionRequest &turnKey(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 120)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
#endif
