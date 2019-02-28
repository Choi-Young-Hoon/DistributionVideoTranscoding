#include "libvideo/CodecID.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace av;

CodecID::CodecID()
: m_videoCodecID(AV_CODEC_ID_NONE), m_audioCodecID(AV_CODEC_ID_NONE)
{}

CodecID::CodecID(CODEC_ID videoCodecID, CODEC_ID audioCodecID)
: m_videoCodecID(videoCodecID), m_audioCodecID(audioCodecID)
{}

CodecID::~CodecID()
{}


CODEC_ID CodecID::videoCodecID() {
    return this->m_videoCodecID;
}

void CodecID::videoCodecID(CODEC_ID codecID) {
    this->m_videoCodecID = codecID;
}

CODEC_ID CodecID::audioCodecID() {
    return this->m_audioCodecID;
}

void CodecID::audioCodecID(CODEC_ID codecID) {
    this->m_audioCodecID = codecID;
}