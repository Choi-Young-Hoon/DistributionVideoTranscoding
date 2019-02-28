#include "libvideo/Codec.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}
using namespace vd;

Codec::Codec() 
: m_codec(NULL)
, m_codecContext(NULL)
{}

Codec::~Codec() {
	if (this->m_codecContext != NULL) {
		avcodec_free_context(&this->m_codecContext);
	}
}


AVCodec* Codec::createCodec(CODEC_ID codecID) {
	VD_UNUSED(codecID);

	return NULL;
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
	if (codecParameters != NULL) {
		avcodec_parameters_to_context(this->m_codecContext, codecParameters);
	}

	avcodec_open2(this->m_codecContext, this->m_codec, NULL);

	error->success();
}


