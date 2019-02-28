#ifndef __LIB_VIDEO_CODEC_ID_HEADER__
#define __LIB_VIDEO_CODEC_ID_HEADER__

#include "libvideo/Type.hpp"

namespace av {
    
    class CodecID {
    public:
        explicit CodecID();
        explicit CodecID(CODEC_ID videoCodecID, CODEC_ID audioCodecID);
        virtual ~CodecID();

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
