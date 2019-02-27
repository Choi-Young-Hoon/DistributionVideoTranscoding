#ifndef __LIB_VIDEO_CODEC_MANAGER_HEADER__
#define __LIB_VIDEO_CODEC_MANAGER_HEADER__

#include "libvideo/VideoError.hpp"
#include "libvideo/VideoType.hpp"
#include "libvideo/VideoCodec.hpp"
#include "libvideo/VideoCodecParameter.hpp"

namespace vd {

    class VideoCodecManager {
    public:
        static VideoCodec* CreateCodec(CODEC_TYPE codecType, CODEC_ID codecID, VideoCodecParameter& codecParamter, VideoError* error);

    private:
        static VideoCodec* CreateCodec(CODEC_TYPE codecType, VideoError* error);
        
        static VideoCodec* CreateEncodeCodec(VideoError* error);
        static VideoCodec* CreateDecodeCodec(VideoError* error);

    private:
        explicit VideoCodecManager();
        virtual ~VideoCodecManager();
    };

};

#endif