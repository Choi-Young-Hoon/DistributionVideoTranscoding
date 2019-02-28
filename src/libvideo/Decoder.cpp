#include "libvideo/Decoder.hpp"
#include "libvideo/Codec.hpp"

extern "C" {
	#include "libavcodec/avcodec.h"
}

using namespace av;

Decoder::Decoder(StreamIndex& streamIndex, Codec* videoCodec, Codec* audioCodec)
: m_videoCodec(videoCodec), m_audioCodec(audioCodec) {
	m_streamIndex = streamIndex;
}

Decoder::~Decoder()
{}


void Decoder::Decode(Codec& codec, EncodedFrame& encodedFrame, RawFrame* rawFrame, Error* error) {
	int ret = avcodec_send_packet(codec.m_codecContext, encodedFrame.m_packet);
	if (ret < 0) {
		error->error(ret, Error::avStrError(ret));
		return;
	}

	ret = 0;
	while (ret >= 0) {
		ret = avcodec_receive_frame(codec.m_codecContext, rawFrame->m_frame);
		if ((ret == AVERROR(EAGAIN)) || (ret == AVERROR_EOF)) {
			break;
		} else if (ret < 0) {
			error->error(ret, Error::avStrError(ret));
			return;
		}
	}

	error->success();
}

void Decoder::Decode(EncodedFrame& encodedFrame, RawFrame* rawFrame, Error* error) {
	if ((encodedFrame.m_packet->stream_index == this->m_streamIndex.videoStreamIndex()) && (this->m_videoCodec != NULL)) {
		rawFrame->isAudio(false);
		Decode(*this->m_videoCodec, encodedFrame, rawFrame, error);
	} else if ((encodedFrame.m_packet->stream_index == this->m_streamIndex.audioStreamIndex()) && (this->m_audioCodec != NULL)) {
		rawFrame->isAudio(true);
		Decode(*this->m_audioCodec, encodedFrame, rawFrame, error);	
	}

	return;
}

void Decoder::setVideoCodec(Codec* codec) {
	this->m_videoCodec = codec;
}

void Decoder::setAudioCodec(Codec* codec) {
	this->m_audioCodec = codec;
}

void Decoder::setStreamIndex(StreamIndex& streamIndex) {
	this->m_streamIndex = streamIndex;
}
