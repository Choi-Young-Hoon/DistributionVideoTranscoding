#include "libvideo/VideoReader.hpp"

extern "C" {
    #include "libavformat/avformat.h"
}

using namespace vd;

VideoReader::VideoReader()
: format_ctx_(NULL)
{}

VideoReader::~VideoReader() {
    this->close();
}


void VideoReader::open(const std::string file_name, VideoError* error) {
    int ret = 0;

    ret = avformat_open_input(&this->format_ctx_, file_name.c_str(), NULL, NULL);
    if (ret < 0) {
        error->error(ret, VideoError::avStrError(ret));
        return;
    }
    int video_stream_index = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    int audio_stream_index = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_AUDIO, -1, video_stream_index, NULL, 0);
    this->stream_index_.videoStreamIndex(video_stream_index);
    this->stream_index_.audioStreamIndex(audio_stream_index);

    error->success();
}

void VideoReader::close() {
    if (this->isOpen() == true) {
        avformat_close_input(&this->format_ctx_);
    }
    this->format_ctx_ = NULL;
}

bool VideoReader::isOpen() {
    if (this->format_ctx_ == NULL) {
        return false;
    }
    return true;
}

void VideoReader::readFrame(VideoEncodedFrame* encoded_frame, VideoError* error) {
    if (this->isOpen() == false) {
        error->error(FILE_NOT_OPENED, getErrorStr(FILE_NOT_OPENED));
        return;
    }
    encoded_frame->clear();
    int ret = 0;
    
    error->success(ret);
}

void VideoReader::printInfo() {
    if (this->isOpen() == false) {
        return;
    }
    av_dump_format(this->format_ctx_, 0, NULL, 0);
}