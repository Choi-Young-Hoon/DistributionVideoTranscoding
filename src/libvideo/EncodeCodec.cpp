#include "libvideo/EncodeCodec.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}

using namespace vd;

EncodeCodec::EncodeCodec()
{}

EncodeCodec::~EncodeCodec()
{}


AVCodec* EncodeCodec::createCodec(CODEC_ID codecID) {
	if (codecID < 0) {
		return NULL;
	}

	AVCodec* codec = avcodec_find_encoder((AVCodecID)codecID);
	if (codec == NULL) {
		return NULL;
	}

	return codec;
}
