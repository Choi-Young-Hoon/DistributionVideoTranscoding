#ifndef __LIB_VIDEO_CODEC_ID_HEADER__
#define __LIB_VIDEO_CODEC_ID_HEADER__

#include "libvideo/VideoType.hpp"

namespace vd {
    
    class VideoCodecID {
    public:
        explicit VideoCodecID();
        explicit VideoCodecID(CODEC_ID videoCodecID, CODEC_ID audioCodecID);
        virtual ~VideoCodecID();

    public:
        CODEC_ID videoCodecID();
        void     videoCodecID(CODEC_ID codecID);

        CODEC_ID audioCodecID();
        void     audioCodecID(CODEC_ID codecID);

    private:
        CODEC_ID m_videoCodecID;
        CODEC_ID m_audioCodecID;
    };

};

#endif