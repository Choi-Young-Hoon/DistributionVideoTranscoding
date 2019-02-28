#ifndef __LIB_VIDEO_DECODE_CODEC_HEADER__
#define __LIB_VIDEO_DECODE_CODEC_HEADER__

#include "libvideo/Type.hpp"
#include "libvideo/Codec.hpp"

namespace vd {

	class DecodeCodec : public Codec {
	public:
		explicit DecodeCodec();
		virtual ~DecodeCodec();

	protected:
		virtual AVCodec* createCodec(CODEC_ID codecID);

	private:

	};

};

#endif

