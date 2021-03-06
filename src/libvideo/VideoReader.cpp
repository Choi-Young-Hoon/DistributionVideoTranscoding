#include "libvideo/VideoReader.hpp"

extern "C" {
    #include "libavformat/avformat.h"
}

using namespace av;

VideoReader::VideoReader()
: m_formatContext(NULL)
{}

VideoReader::~VideoReader() {
    this->close();
}


void VideoReader::open(const std::string fileName, Error* error) {
    int ret = 0;

    ret = avformat_open_input(&this->m_formatContext, fileName.c_str(), NULL, NULL);
    if (ret < 0) {
        error->error(ret, Error::avStrError(ret));
        return;
    }
    this->getStreamIndex();
    this->getCodecID();

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

void VideoReader::readFrame(EncodedFrame* encodedFrame, Error* error) {
    if (this->isOpen() == false) {
        error->error(FILE_NOT_OPENED, Error::getErrorStr(FILE_NOT_OPENED));
        return;
    }
    encodedFrame->clear();

    int ret = av_read_frame(this->m_formatContext, encodedFrame->m_packet);
    if (ret == AVERROR_EOF) {
        error->error(FILE_EOF, Error::getErrorStr(FILE_EOF), true);
        return;
    } else if (ret < 0) {
        error->error(ret, Error::avStrError(ret));
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

CodecParameter VideoReader::videoCodecParameter() {
	CodecParameter codecParameter;
	
	if (this->isOpen() == true) {
		codecParameter.m_codecParameter = this->m_formatContext->streams[this->m_streamIndex.videoStreamIndex()]->codecpar;
	} else {
		codecParameter.m_codecParameter = NULL;
	}
	
	return codecParameter;
}

CodecParameter VideoReader::audioCodecParameter() {
	CodecParameter codecParameter;

	if (this->isOpen() == true) {
		codecParameter.m_codecParameter = this->m_formatContext->streams[this->m_streamIndex.audioStreamIndex()]->codecpar;
	} else {
		codecParameter.m_codecParameter = NULL;
	}
	
	return codecParameter;
}

StreamIndex VideoReader::streamIndex() {
    return this->m_streamIndex;
}

STREAM_INDEX VideoReader::videoStreamIndex() {
    return this->m_streamIndex.videoStreamIndex();
}

STREAM_INDEX VideoReader::audioStreamIndex() {
    return this->m_streamIndex.audioStreamIndex();
}


CodecID VideoReader::codecID() {
    return this->m_codecID;
}

CODEC_ID VideoReader::videoCodecID() {
    return this->m_codecID.videoCodecID();
}

CODEC_ID VideoReader::audioCodecID() {
    return this->m_codecID.audioCodecID();
}

int64_t VideoReader::bitRate() {
    if (this->isOpen() == false) {
        return -1;
    }

    return this->m_formatContext->bit_rate;
}

Rational VideoReader::frameRate() {
    if (this->isOpen() == false) {
        return Rational(-1, -1);
    }

    AVRational rational = this->m_formatContext->streams[this->m_streamIndex.videoStreamIndex()]->r_frame_rate;
    return Rational(rational.num, rational.den);
}

int VideoReader::width() {
    if (this->isOpen() == false) {
        return -1;
    }
    return this->m_formatContext->streams[this->m_streamIndex.videoStreamIndex()]->codecpar->width;
}

int VideoReader::height() {
    if (this->isOpen() == false) {
        return -1;
    }
    return this->m_formatContext->streams[this->m_streamIndex.videoStreamIndex()]->codecpar->height;
}

void VideoReader::getStreamIndex() {
    STREAM_INDEX videoStreamIndex = av_find_best_stream(this->m_formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    STREAM_INDEX audioStreamIndex = av_find_best_stream(this->m_formatContext, AVMEDIA_TYPE_AUDIO, -1, videoStreamIndex, NULL, 0);

    this->m_streamIndex.videoStreamIndex(videoStreamIndex);
    this->m_streamIndex.audioStreamIndex(audioStreamIndex);
}

void VideoReader::getCodecID() {
    CODEC_ID videoCodecID = this->getCodecID(this->videoStreamIndex());
    CODEC_ID audioCodecID = this->getCodecID(this->audioStreamIndex());

    this->m_codecID.videoCodecID(videoCodecID);
    this->m_codecID.audioCodecID(audioCodecID);
}

CODEC_ID VideoReader::getCodecID(STREAM_INDEX streamIndex) {
    if (streamIndex < 0) {
        return AV_CODEC_ID_NONE;
    }

    return this->m_formatContext->streams[streamIndex]->codecpar->codec_id;
}
