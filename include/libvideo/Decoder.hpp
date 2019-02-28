#ifndef __LIB_VIDEO_DECODER_HEADER__
#define __LIB_VIDEO_DECODER_HEADER__

#include "libvideo/Type.hpp"
#include "libvideo/Error.hpp"
#include "libvideo/Codec.hpp"
#include "libvideo/StreamIndex.hpp"

namespace vd {
	
	class Decoder {
	public:
		explicit Decoder();
		virtual ~Decoder();

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
