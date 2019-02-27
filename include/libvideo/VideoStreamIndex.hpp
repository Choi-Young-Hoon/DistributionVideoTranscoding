#ifndef __LIB_VIDEO_STREAM_INDEX_HEADER__
#define __LIB_VIDEO_STREAM_INDEX_HEADER__

#include "libvideo/VideoType.hpp"

namespace vd {

    class VideoStreamIndex {
    public:
        explicit VideoStreamIndex();
        explicit VideoStreamIndex(STREAM_INDEX videoStreamIndex, STREAM_INDEX audioStreamIndex);
        virtual ~VideoStreamIndex();

    public:
        STREAM_INDEX videoStreamIndex();
        void         videoStreamIndex(STREAM_INDEX videoStreamIndex);

        STREAM_INDEX audioStreamIndex();
        void         audioStreamIndex(STREAM_INDEX audioStreamIndex);

    private:
        STREAM_INDEX m_videoStreamIndex;
        STREAM_INDEX m_audioStreamIndex;
    };
    
};

#endif