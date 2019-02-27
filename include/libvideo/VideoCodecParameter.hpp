#ifndef __LIB_VIDEO_CODEC_PARAMETER_HEADER__
#define __LIB_VIDEO_CODEC_PARAMETER_HEADER__

struct AVCodecParameter;
namespace vd {
    
    class VideoCodecParameter {
    public:
        explicit VideoCodecParameter();
        virtual ~VideoCodecParameter();
    
    private:
        AVCodecParameter* m_codecParameter;
    };

};

#endif