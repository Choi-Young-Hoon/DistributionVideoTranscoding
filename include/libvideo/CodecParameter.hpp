#ifndef __LIB_VIDEO_CODEC_PARAMETER_HEADER__
#define __LIB_VIDEO_CODEC_PARAMETER_HEADER__

struct AVCodecParameters;
namespace vd {
    
    class CodecParameter {
    public:
        explicit CodecParameter();
        virtual ~CodecParameter();
	
		friend class Codec;
	
    private:
        AVCodecParameters* m_codecParameter;
    };

};

#endif
