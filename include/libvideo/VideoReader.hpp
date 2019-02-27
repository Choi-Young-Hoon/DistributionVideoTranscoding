#ifndef __LIB_VIDEO_HEADER__
#define __LIB_VIDEO_HEADER__

#include <iostream>
#include <string>

#include "libvideo/VideoErrorDefine.hpp"
#include "libvideo/VideoError.hpp"
#include "libvideo/VideoType.hpp"
#include "libvideo/VideoStreamIndex.hpp"
#include "libvideo/VideoCodecID.hpp"
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

        VideoStreamIndex streamIndex();
        STREAM_INDEX getVideoStreamIndex();
        STREAM_INDEX getAudioStreamIndex();

        VideoCodecID codecID();
        CODEC_ID getVideoCodecID();
        CODEC_ID getAudioCodecID();

    private:
        void getStreamIndex();
        void getCodecID();

        CODEC_ID getCodecID(STREAM_INDEX streamIndex);

    private:
        VideoCodecID     m_codecID;
        VideoStreamIndex m_streamIndex;

        AVFormatContext* m_formatContext;
    };

};

#endif