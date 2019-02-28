#ifndef __LIB_VIDEO_HEADER__
#define __LIB_VIDEO_HEADER__

#include <iostream>
#include <string>

#include "libvideo/ErrorDefine.hpp"
#include "libvideo/Error.hpp"
#include "libvideo/Type.hpp"
#include "libvideo/StreamIndex.hpp"
#include "libvideo/CodecID.hpp"
#include "libvideo/EncodedFrame.hpp"

struct AVFormatContext;
namespace vd {

    class VideoReader {
    public:
        explicit VideoReader();
        virtual ~VideoReader();

    public:
        void open (const std::string fileName, Error* error);
        void close();

        void readFrame(EncodedFrame* encodedFrame, Error* error);

    public:
        bool isOpen();
        void printInfo();

        StreamIndex streamIndex();
        STREAM_INDEX getVideoStreamIndex();
        STREAM_INDEX getAudioStreamIndex();

        CodecID codecID();
        CODEC_ID getVideoCodecID();
        CODEC_ID getAudioCodecID();

    private:
        void getStreamIndex();
        void getCodecID();

        CODEC_ID getCodecID(STREAM_INDEX streamIndex);

    private:
        CodecID     m_codecID;
        StreamIndex m_streamIndex;

        AVFormatContext* m_formatContext;
    };

};

#endif