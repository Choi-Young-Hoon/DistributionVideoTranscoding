#include "libvideo/VideoReader.hpp"

extern "C" {
    #include "libavformat/avformat.h"
}

using namespace vd;

VideoReader::VideoReader()
: m_formatContext(NULL)
{}

VideoReader::~VideoReader() {
    this->close();
}


void VideoReader::open(const std::string fileName, VideoError* error) {
    int ret = 0;

    ret = avformat_open_input(&this->m_formatContext, fileName.c_str(), NULL, NULL);
    if (ret < 0) {
        error->error(ret, VideoError::avStrError(ret));
        return;
    }
    int videoStreamIndex = av_find_best_stream(this->m_formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    int audioStreamIndex = av_find_best_stream(this->m_formatContext, AVMEDIA_TYPE_AUDIO, -1, audioStreamIndex, NULL, 0);
    this->m_streamIndex.videoStreamIndex(videoStreamIndex);
    this->m_streamIndex.audioStreamIndex(audioStreamIndex);

    error->success();
}

void VideoReader::close() {
    if (this->isOpen() == true) {
        avformat_close_input(&this->m_formatContext);
    }
    this->m_formatContext = NULL;
}

bool VideoReader::isOpen() {
    if (this->m_formatContext == NULL) {
        return false;
    }
    return true;
}

void VideoReader::readFrame(VideoEncodedFrame* encodedFrame, VideoError* error) {
    if (this->isOpen() == false) {
        error->error(FILE_NOT_OPENED, VideoError::getErrorStr(FILE_NOT_OPENED));
        return;
    }
    encodedFrame->clear();

    int ret = av_read_frame(this->m_formatContext, encodedFrame->m_packet);
    if (ret == AVERROR_EOF) {
        error->error(FILE_EOF, VideoError::getErrorStr(FILE_EOF), true);
        return;
    } else if (ret < 0) {
        error->error(ret, VideoError::avStrError(ret));
        return;
    }
    
    error->success();
}

void VideoReader::printInfo() {
    if (this->isOpen() == false) {
        return;
    }
    av_dump_format(this->m_formatContext, 0, NULL, 0);
}