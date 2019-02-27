#include "libvideo/VideoStreamIndex.hpp"

using namespace vd;

VideoStreamIndex::VideoStreamIndex()
: m_videoStreamIndex(0), m_audioStreamIndex(0)
{}

VideoStreamIndex::VideoStreamIndex(STREAM_INDEX videoStreamIndex, STREAM_INDEX audioStreamIndex)
: m_videoStreamIndex(videoStreamIndex), m_audioStreamIndex(audioStreamIndex)
{}

VideoStreamIndex::~VideoStreamIndex()
{}


CODEC_ID VideoStreamIndex::videoStreamIndex() {
    return this->m_videoStreamIndex;
}

void VideoStreamIndex::videoStreamIndex(STREAM_INDEX videoStreamIndex) {
    this->m_videoStreamIndex = videoStreamIndex;
}

CODEC_ID VideoStreamIndex::audioStreamIndex() {
    return this->m_audioStreamIndex;
}

void VideoStreamIndex::audioStreamIndex(STREAM_INDEX audioStreamIndex) {
    this->m_audioStreamIndex = audioStreamIndex;
}