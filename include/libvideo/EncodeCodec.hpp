#ifndef __LIB_VIDEO_ENCODE_CODEC_HEADER__
#define __LIB_VIDEO_ENCODE_CODEC_HEADER__

#include "libvideo/Type.hpp"
#include "libvideo/Codec.hpp"

namespace vd {
	
	class EncodeCodec : public Codec {
	public:
		explicit EncodeCodec();
		virtual ~EncodeCodec();

	protected:
		virtual AVCodec* createCodec(CODEC_ID codecID);

	private:
	
	};

};

#endif
