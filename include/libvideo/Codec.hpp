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
namespace av {
    
    class Codec {
    public:
        explicit Codec(CODEC_TYPE codecType);
        virtual ~Codec();
		
		friend class Encoder;
		friend class Decoder;

	public:
		void initializeCodec(CODEC_ID codecID, CodecParameter& codecParameter, Error* error);
	
	public:
		CODEC_TYPE codecType();
		void	   codecType(CODEC_TYPE codecType);

	protected:
		virtual AVCodec* createCodec(CODEC_ID codecID);

	private:
		void openCodec(CodecParameter& codecParameter, Error* error);

    private:
		CODEC_TYPE m_codecType;

		AVCodec* m_codec;

		AVCodecContext* m_codecContext;
    };
	
};

#endif
