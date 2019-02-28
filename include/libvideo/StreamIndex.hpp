#ifndef __LIB_VIDEO_STREAM_INDEX_HEADER__
#define __LIB_VIDEO_STREAM_INDEX_HEADER__

#include "libvideo/Type.hpp"

namespace vd {

    class StreamIndex {
    public:
        explicit StreamIndex();
        explicit StreamIndex(STREAM_INDEX videoStreamIndex, STREAM_INDEX audioStreamIndex);
        virtual ~StreamIndex();

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