#ifndef __LIB_VIDEO_ENCODER_HEADER__
#define __LIB_VIDEO_ENCODER_HEADER__

#include "libvideo/Codec.hpp"
#include "libvideo/EncodedFrame.hpp"
#include "libvideo/RawFrame.hpp"

namespace av {
	
	class Encoder {
	public:
		explicit Encoder(Codec* videoCodec, Codec* audioCodec);
		virtual ~Encoder();

	public:
		void Encode(Codec& codec, RawFrame& rawFrame, EncodedFrame* encodedFrame, Error* error);
		void Encode(RawFrame& rawFrame, EncodedFrame* encodedFrame, Error* error);

	public:
		void setVideoCodec(Codec* codec);
		void setAudioCodec(Codec* codec);

	private:
		Codec* m_videoCodec;
		Codec* m_audioCodec;
	};

};

#endif
