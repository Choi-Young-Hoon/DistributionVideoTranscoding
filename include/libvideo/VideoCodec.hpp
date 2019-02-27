#ifndef __LIB_VIDEO_CODEC_HEADER__
#define __LIB_VIDEO_CODEC_HEADER__

#include <iostream>
#include <string>

struct AVCodec;
namespace vd {
    
    class VideoCodec {
    public:
        explicit VideoCodec();
        virtual ~VideoCodec();

    private:
        AVCodec* m_codec;
    };
    
};

#endif