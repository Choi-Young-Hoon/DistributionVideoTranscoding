#include "libvideo/Encoder.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}

using namespace av;

Encoder::Encoder(Codec* videoCodec, Codec* audioCodec)
: m_videoCodec(videoCodec), m_audioCodec(audioCodec)
{}

Encoder::~Encoder()
{}


void Encoder::Encode(Codec& codec, RawFrame& rawFrame, EncodedFrame* encodedFrame, Error* error) {
	int ret = avcodec_send_frame(codec.m_codecContext, rawFrame.m_frame);
	if (ret < 0) {
		error->error(ret, Error::avStrError(ret));
		return;
	}
	
	ret = 0;
	while (ret >= 0) {
		ret = avcodec_receive_packet(codec.m_codecContext, encodedFrame->m_packet);
		if ((ret == AVERROR(EAGAIN)) || (ret == AVERROR_EOF)) {
			break;
		} else if (ret < 0) {
			error->error(ret, Error::avStrError(ret));
			return;
		}
	}

	error->success();
}


void Encoder::Encode(RawFrame& rawFrame, EncodedFrame* encodedFrame, Error* error) {
	if ((rawFrame.isAudio() == true) && (m_audioCodec != NULL)) {
		Encode(*this->m_audioCodec, rawFrame, encodedFrame, error);
	} else if ((rawFrame.isAudio() == false) && (m_videoCodec != NULL)) {
		Encode(*this->m_videoCodec, rawFrame, encodedFrame, error);	
	} else {
	
	}	
}


void Encoder::setVideoCodec(Codec* codec) {
	this->m_videoCodec = codec;
}

void Encoder::setAudioCodec(Codec* codec) {
	this->m_audioCodec = codec;
}
