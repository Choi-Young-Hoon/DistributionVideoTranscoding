#include "libvideo/VideoEncodedFrame.hpp"
#include "libvideo/VideoErrorDefine.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace vd;

VideoEncodedFrame::VideoEncodedFrame() {
    VIDEO_ALLOC_EXCEPTION(this->packet_ = new AVPacket);
    av_init_packet(this->packet_);
}

VideoEncodedFrame::~VideoEncodedFrame() {
    if (this->packet_->data != NULL) {
        delete[] this->packet_->data;
    }

    if (this->packet_ != NULL) {
        delete this->packet_;
    }
}


void VideoEncodedFrame::clear() {
    av_packet_unref(this->packet_);
}

