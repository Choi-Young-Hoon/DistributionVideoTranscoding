#include "libvideo/VideoCodecID.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace vd;

VideoCodecID::VideoCodecID()
: m_videoCodecID(AV_CODEC_ID_NONE), m_audioCodecID(AV_CODEC_ID_NONE)
{}

VideoCodecID::VideoCodecID(CODEC_ID videoCodecID, CODEC_ID audioCodecID)
: m_videoCodecID(videoCodecID), m_audioCodecID(audioCodecID)
{}

VideoCodecID::~VideoCodecID()
{}


CODEC_ID VideoCodecID::videoCodecID() {
    return this->m_videoCodecID;
}

void VideoCodecID::videoCodecID(CODEC_ID codecID) {
    this->m_videoCodecID = codecID;
}

CODEC_ID VideoCodecID::audioCodecID() {
    return this->m_audioCodecID;
}

void VideoCodecID::audioCodecID(CODEC_ID codecID) {
    this->m_audioCodecID = codecID;
}