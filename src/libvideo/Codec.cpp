#include "libvideo/Codec.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}

using namespace av;

Codec::Codec(CODEC_TYPE codecType) 
: m_codecType(codecType)
, m_codec(NULL), m_codecContext(NULL)
{}

Codec::~Codec() {
	if (this->m_codecContext != NULL) {
		avcodec_free_context(&this->m_codecContext);
	}
}

void Codec::initializeCodec(CODEC_ID codecID, CodecParameter& codecParameter, Error* error) {
	if (codecID == AV_CODEC_ID_NONE) {
		error->success();	
		return;
	}

	m_codec = this->createCodec(codecID);
	if (m_codec == NULL) {
		error->error(AV_CODEC_ID_NONE, "Codec not found");
		return;
	}

	m_codecContext = avcodec_alloc_context3(m_codec);
	if (m_codecContext == NULL) {
		error->error(MEMORY_ALLOC_FAILED, "Memory alloc failed to codec context (NULL)");
		return;
	}
	
	AVCodecParameters* codecParameters = codecParameter.m_codecParameter;
	if ((this->m_codecType == DECODE)&& (codecParameters != NULL)) {
		avcodec_parameters_to_context(this->m_codecContext, codecParameters);
	}
	
	openCodec(codecParameter, error);
	if (error->isSuccess() == false) {
		return;
	}

	error->success();
}

AVCodec* Codec::createCodec(CODEC_ID codecID) {
	AV_UNUSED(codecID);

	return NULL;
}

void Codec::openCodec(CodecParameter& codecParameter, Error* error) {
	if (this->m_codecType == ENCODE) {
		this->m_codecContext->bit_rate = codecParameter.bitRate();
		
		this->m_codecContext->width  = codecParameter.width();
		this->m_codecContext->height = codecParameter.height();
		
		Rational timeBase  = codecParameter.timeBase();
		Rational frameRate = codecParameter.frameRate();
		this->m_codecContext->time_base = (AVRational){timeBase.num(), timeBase.den()};
		this->m_codecContext->framerate = (AVRational){frameRate.num(), frameRate.den()};

		this->m_codecContext->gop_size = codecParameter.gopSize();
		this->m_codecContext->max_b_frames = codecParameter.maxBFrames();
		this->m_codecContext->pix_fmt = (enum AVPixelFormat)codecParameter.pixelFormat();
	}
	avcodec_open2(this->m_codecContext, this->m_codec, NULL);

	error->success();	
}

CODEC_TYPE Codec::codecType() {
	return this->m_codecType;
}

void Codec::codecType(CODEC_TYPE codecType) {
	this->m_codecType = codecType;
}
