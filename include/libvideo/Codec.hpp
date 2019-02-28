#ifndef __LIB_VIDEO_CODEC_HEADER__
#define __LIB_VIDEO_CODEC_HEADER__

#include <iostream>
#include <string>

#include "libvideo/Error.hpp"
#include "libvideo/Type.hpp"
#include "libvideo/CodecID.hpp"
#include "libvideo/CodecParameter.hpp"

struct AVCodec;
struct AVCodecContext;
namespace vd {
    
    class Codec {
    public:
        explicit Codec();
        virtual ~Codec();
	
	public:
		void initializeCodec(CODEC_ID codecID, CodecParameter& codecParameter, Error* error);

	protected:
		virtual AVCodec* createCodec(CODEC_ID codecID);

    private:
		AVCodec* m_codec;

		AVCodecContext* m_codecContext;
    };
	
};

#endif
