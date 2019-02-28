#ifndef __LIB_VIDEO_DECODER_HEADER__
#define __LIB_VIDEO_DECODER_HEADER__

#include "libvideo/Type.hpp"
#include "libvideo/Error.hpp"
#include "libvideo/Codec.hpp"
#include "libvideo/StreamIndex.hpp"
#include "libvideo/EncodedFrame.hpp"
#include "libvideo/RawFrame.hpp"

namespace av {
	
	class Decoder {
	public:
		explicit Decoder(StreamIndex& streamIndex, Codec* videoCodec, Codec* audioCodec);
		virtual ~Decoder();

	public:
		void Decode(Codec& codec, EncodedFrame& encodedFrame, RawFrame* rawFrame, Error* error);
		void Decode(EncodedFrame& encodedFrame, RawFrame* rawFrame, Error* error);
		
	public:
		void setVideoCodec(Codec* codec);
		void setAudioCodec(Codec* codec);
		void setStreamIndex(StreamIndex& streamIndex);

	private:
		Codec* m_videoCodec;
		Codec* m_audioCodec;
	
		StreamIndex m_streamIndex;
	};

};

#endif
