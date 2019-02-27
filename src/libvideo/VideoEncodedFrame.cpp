#include "libvideo/VideoEncodedFrame.hpp"
#include "libvideo/VideoErrorDefine.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace vd;

VideoEncodedFrame::VideoEncodedFrame() {
    VIDEO_ALLOC_EXCEPTION(this->m_packet = new AVPacket);
    av_init_packet(this->m_packet);
}

VideoEncodedFrame::~VideoEncodedFrame() {
    if (this->m_packet->data != NULL) {
        delete[] this->m_packet->data;
    }

    if (this->m_packet != NULL) {
        delete this->m_packet;
    }
}

bool VideoEncodedFrame::isEmpty() {
    if (this->m_packet->data != NULL) {
        return false;
    }
    return true;
}

void VideoEncodedFrame::clear() {
    av_packet_unref(this->m_packet);
}