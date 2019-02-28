#include "libvideo/EncodedFrame.hpp"
#include "libvideo/ErrorDefine.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace av;

EncodedFrame::EncodedFrame() {
    AV_ALLOC_EXCEPTION(this->m_packet = new AVPacket);
    av_init_packet(this->m_packet);
}

EncodedFrame::~EncodedFrame() {
    if (this->m_packet->data != NULL) {
        delete[] this->m_packet->data;
    }

    if (this->m_packet != NULL) {
        delete this->m_packet;
    }
}

bool EncodedFrame::isEmpty() {
    if (this->m_packet->data != NULL) {
        return false;
    }
    return true;
}

void EncodedFrame::clear() {
    av_packet_unref(this->m_packet);
}
