#include "libvideo/StreamIndex.hpp"

using namespace vd;

StreamIndex::StreamIndex()
: m_videoStreamIndex(0), m_audioStreamIndex(0)
{}

StreamIndex::StreamIndex(STREAM_INDEX videoStreamIndex, STREAM_INDEX audioStreamIndex)
: m_videoStreamIndex(videoStreamIndex), m_audioStreamIndex(audioStreamIndex)
{}

StreamIndex::~StreamIndex()
{}


CODEC_ID StreamIndex::videoStreamIndex() {
    return this->m_videoStreamIndex;
}

void StreamIndex::videoStreamIndex(STREAM_INDEX videoStreamIndex) {
    this->m_videoStreamIndex = videoStreamIndex;
}

CODEC_ID StreamIndex::audioStreamIndex() {
    return this->m_audioStreamIndex;
}

void StreamIndex::audioStreamIndex(STREAM_INDEX audioStreamIndex) {
    this->m_audioStreamIndex = audioStreamIndex;
}