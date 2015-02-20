/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _GMDLOGONREQUEST_HPP_
#define _GMDLOGONREQUEST_HPP_

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

class GmdLogonRequest
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    GmdLogonRequest(const GmdLogonRequest&) {}

public:

    GmdLogonRequest(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)228;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)1;
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

    GmdLogonRequest &wrapForEncode(char *buffer, const int offset, const int bufferLength)
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

    GmdLogonRequest &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion,
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

    static const int accountTypeId(void)
    {
        return 3;
    }

    static const int accountTypeSinceVersion(void)
    {
         return 0;
    }

    bool accountTypeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *accountTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t accountTypeNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t accountTypeMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t accountTypeMaxValue()
    {
        return (sbe_char_t)126;
    }

    sbe_char_t accountType(void) const
    {
        return (*((sbe_char_t *)(buffer_ + offset_ + 72)));
    }

    GmdLogonRequest &accountType(const sbe_char_t value)
    {
        *((sbe_char_t *)(buffer_ + offset_ + 72)) = (value);
        return *this;
    }

    static const int reservedId(void)
    {
        return 4;
    }

    static const int reservedSinceVersion(void)
    {
         return 0;
    }

    bool reservedInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *reservedMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
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
        return (*((sbe_char_t *)(buffer_ + offset_ + 73)));
    }

    GmdLogonRequest &reserved(const sbe_char_t value)
    {
        *((sbe_char_t *)(buffer_ + offset_ + 73)) = (value);
        return *this;
    }

    static const int clientInterfaceVersionId(void)
    {
        return 5;
    }

    static const int clientInterfaceVersionSinceVersion(void)
    {
         return 0;
    }

    bool clientInterfaceVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *clientInterfaceVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint16_t clientInterfaceVersionNullValue()
    {
        return USHRT_MAX;
    }

    static const sbe_uint16_t clientInterfaceVersionMinValue()
    {
        return (sbe_uint16_t)0;
    }

    static const sbe_uint16_t clientInterfaceVersionMaxValue()
    {
        return (sbe_uint16_t)65534;
    }

    sbe_uint16_t clientInterfaceVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((sbe_uint16_t *)(buffer_ + offset_ + 74)));
    }

    GmdLogonRequest &clientInterfaceVersion(const sbe_uint16_t value)
    {
        *((sbe_uint16_t *)(buffer_ + offset_ + 74)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static const int clientIdId(void)
    {
        return 6;
    }

    static const int clientIdSinceVersion(void)
    {
         return 0;
    }

    bool clientIdInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *clientIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t clientIdNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t clientIdMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t clientIdMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int clientIdLength(void)
    {
        return 24;
    }

    const char *clientId(void) const
    {
        return (buffer_ + offset_ + 76);
    }

    sbe_char_t clientId(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for clientId [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 76 + (index * 1))));
    }

    void clientId(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for clientId [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 76 + (index * 1))) = (value);
    }

    int getClientId(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getClientId [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 76, length);
        return length;
    }

    GmdLogonRequest &putClientId(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 76, src, 24);
        return *this;
    }

    static const int passwordId(void)
    {
        return 7;
    }

    static const int passwordSinceVersion(void)
    {
         return 0;
    }

    bool passwordInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *passwordMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t passwordNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t passwordMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t passwordMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int passwordLength(void)
    {
        return 24;
    }

    const char *password(void) const
    {
        return (buffer_ + offset_ + 100);
    }

    sbe_char_t password(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for password [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 100 + (index * 1))));
    }

    void password(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for password [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 100 + (index * 1))) = (value);
    }

    int getPassword(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getPassword [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 100, length);
        return length;
    }

    GmdLogonRequest &putPassword(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 100, src, 24);
        return *this;
    }

    static const int deskIdId(void)
    {
        return 8;
    }

    static const int deskIdSinceVersion(void)
    {
         return 0;
    }

    bool deskIdInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *deskIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t deskIdNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t deskIdMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t deskIdMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int deskIdLength(void)
    {
        return 24;
    }

    const char *deskId(void) const
    {
        return (buffer_ + offset_ + 124);
    }

    sbe_char_t deskId(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for deskId [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 124 + (index * 1))));
    }

    void deskId(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for deskId [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 124 + (index * 1))) = (value);
    }

    int getDeskId(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getDeskId [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 124, length);
        return length;
    }

    GmdLogonRequest &putDeskId(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 124, src, 24);
        return *this;
    }

    static const int firmIdId(void)
    {
        return 9;
    }

    static const int firmIdSinceVersion(void)
    {
         return 0;
    }

    bool firmIdInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *firmIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t firmIdNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t firmIdMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t firmIdMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int firmIdLength(void)
    {
        return 24;
    }

    const char *firmId(void) const
    {
        return (buffer_ + offset_ + 148);
    }

    sbe_char_t firmId(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for firmId [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 148 + (index * 1))));
    }

    void firmId(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for firmId [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 148 + (index * 1))) = (value);
    }

    int getFirmId(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getFirmId [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 148, length);
        return length;
    }

    GmdLogonRequest &putFirmId(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 148, src, 24);
        return *this;
    }

    static const int clientVersionId(void)
    {
        return 10;
    }

    static const int clientVersionSinceVersion(void)
    {
         return 0;
    }

    bool clientVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *clientVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t clientVersionNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t clientVersionMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t clientVersionMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int clientVersionLength(void)
    {
        return 24;
    }

    const char *clientVersion(void) const
    {
        return (buffer_ + offset_ + 172);
    }

    sbe_char_t clientVersion(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for clientVersion [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 172 + (index * 1))));
    }

    void clientVersion(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for clientVersion [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 172 + (index * 1))) = (value);
    }

    int getClientVersion(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getClientVersion [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 172, length);
        return length;
    }

    GmdLogonRequest &putClientVersion(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 172, src, 24);
        return *this;
    }

    static const int usageTypeId(void)
    {
        return 11;
    }

    static const int usageTypeSinceVersion(void)
    {
         return 0;
    }

    bool usageTypeInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *usageTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_char_t usageTypeNullValue()
    {
        return (sbe_char_t)0;
    }

    static const sbe_char_t usageTypeMinValue()
    {
        return (sbe_char_t)32;
    }

    static const sbe_char_t usageTypeMaxValue()
    {
        return (sbe_char_t)126;
    }

    static const int usageTypeLength(void)
    {
        return 24;
    }

    const char *usageType(void) const
    {
        return (buffer_ + offset_ + 196);
    }

    sbe_char_t usageType(const int index) const
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for usageType [E104]");
        }

        return (*((sbe_char_t *)(buffer_ + offset_ + 196 + (index * 1))));
    }

    void usageType(const int index, const sbe_char_t value)
    {
        if (index < 0 || index >= 24)
        {
            throw std::runtime_error("index out of range for usageType [E105]");
        }

        *((sbe_char_t *)(buffer_ + offset_ + 196 + (index * 1))) = (value);
    }

    int getUsageType(char *dst, const int length) const
    {
        if (length > 24)
        {
             throw std::runtime_error("length too large for getUsageType [E106]");
        }

        ::memcpy(dst, buffer_ + offset_ + 196, length);
        return length;
    }

    GmdLogonRequest &putUsageType(const char *src)
    {
        ::memcpy(buffer_ + offset_ + 196, src, 24);
        return *this;
    }

    static const int sequenceRequestId(void)
    {
        return 12;
    }

    static const int sequenceRequestSinceVersion(void)
    {
         return 0;
    }

    bool sequenceRequestInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *sequenceRequestMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint64_t sequenceRequestNullValue()
    {
        return ULLONG_MAX;
    }

    static const sbe_uint64_t sequenceRequestMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t sequenceRequestMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t sequenceRequest(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 220)));
    }

    GmdLogonRequest &sequenceRequest(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 220)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
#endif
