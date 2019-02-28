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
#include "libvideo/Rational.hpp"
#include "libvideo/CodecParameter.hpp"

struct AVFormatContext;
namespace av {

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

		CodecParameter videoCodecParameter();
		CodecParameter audioCodecParameter();

        StreamIndex streamIndex();
        STREAM_INDEX videoStreamIndex();
        STREAM_INDEX audioStreamIndex();

        CodecID codecID();
        CODEC_ID videoCodecID();
        CODEC_ID audioCodecID();

        int64_t  bitRate();
        Rational frameRate();

        int width();
        int height();

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
