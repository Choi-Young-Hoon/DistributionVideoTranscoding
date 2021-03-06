#ifndef __LIB_VIDEO_ENCODED_FRAME_HEADER__
#define __LIB_VIDEO_ENCODED_FRAME_HEADER__

#include <iostream>
#include <memory>

#include "libvideo/Type.hpp"

struct AVPacket;
namespace av {

    class EncodedFrame {
    public:
        explicit EncodedFrame();
        virtual ~EncodedFrame();

        friend class VideoReader;
		friend class Encoder;
		friend class Decoder;

    public:
        bool isEmpty();
        void clear();

    private:
        AVPacket* m_packet;
    };

};

#endif
