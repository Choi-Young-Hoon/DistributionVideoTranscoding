#include "libvideo/StreamIndex.hpp"

using namespace vd;

StreamIndex::StreamIndex()
: m_videoStreamIndex(0), m_audioStreamIndex(0)
{}

StreamIndex::StreamIndex(int videoStreamIndex, int audioStreamIndex)
: m_videoStreamIndex(videoStreamIndex), m_audioStreamIndex(audioStreamIndex)
{}

StreamIndex::~StreamIndex()
{}


int StreamIndex::videoStreamIndex() {
    return this->m_videoStreamIndex;
}

void StreamIndex::videoStreamIndex(int videoStreamIndex) {
    this->m_videoStreamIndex = videoStreamIndex;
}

int StreamIndex::audioStreamIndex() {
    return this->m_audioStreamIndex;
}

void StreamIndex::audioStreamIndex(int audioStreamIndex) {
    this->m_audioStreamIndex = audioStreamIndex;
}