#include "libvideo/RawFrame.hpp"
#include "libvideo/Error.hpp"
#include "libvideo/ErrorDefine.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}

using namespace av;

RawFrame::RawFrame() {
	AV_ALLOC_EXCEPTION(this->m_frame = av_frame_alloc());
}

RawFrame::~RawFrame() {
	if (this->m_frame != NULL) {
		av_frame_free(&this->m_frame);
		this->m_frame = NULL;
	}
}

bool RawFrame::isAudio() {
	return this->m_isAudio;
}

void RawFrame::isAudio(bool isAudio) {
	this->m_isAudio = isAudio;
}

void RawFrame::setCodecParameter(CodecParameter& codecParameter) {
	this->m_frame->format = (enum AVPixelFormat)codecParameter.pixelFormat();
	this->m_frame->width  = codecParameter.width();
	this->m_frame->height = codecParameter.height();

	this->m_frame->linesize[0] = codecParameter.width();
	this->m_frame->linesize[1] = codecParameter.width() / 2;
	this->m_frame->linesize[2] = codecParameter.width() / 2;

	// 임시
	av_frame_get_buffer(this->m_frame, 32);
}
