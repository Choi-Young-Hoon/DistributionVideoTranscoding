#ifndef __LIB_VIDEO_HEADER__
#define __LIB_VIDEO_HEADER__

#include <iostream>
#include <string>

#include "libvideo/VideoErrorDefine.hpp"
#include "libvideo/VideoError.hpp"
#include "libvideo/StreamIndex.hpp"
#include "libvideo/VideoEncodedFrame.hpp"

struct AVFormatContext;
namespace vd {

    class VideoReader {
    public:
        explicit VideoReader();
        virtual ~VideoReader();

    public:
        void open (const std::string fileName, VideoError* error);
        void close();

        void readFrame(VideoEncodedFrame* encodedFrame, VideoError* error);

    public:
        bool isOpen();
        
        void printInfo();

    private:
        StreamIndex m_streamIndex;

        AVFormatContext* m_formatContext;
    };

};

#endif