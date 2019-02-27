#ifndef __LIB_VIDEO_ENCODED_FRAME_HEADER__
#define __LIB_VIDEO_ENCODED_FRAME_HEADER__

#include <iostream>
#include <memory>

#include "libvideo/VideoType.hpp"

struct AVPacket;
namespace vd {

    class VideoEncodedFrame {
    public:
        explicit VideoEncodedFrame();
        virtual ~VideoEncodedFrame();

        friend class VideoReader;

    public:
        bool isEmpty();
        void clear();

    private:
        AVPacket* m_packet;
    };

};

#endif