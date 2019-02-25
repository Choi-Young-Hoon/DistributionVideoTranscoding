#include "libvideo/Video.hpp"

extern "C" {
    #include "libavformat/avformat.h"
};

Video::Video() {
    AVFormatContext* formatCtx = NULL;
    avformat_open_input(&formatCtx, "./test.jpg", NULL, NULL);
}

Video::~Video()
{}