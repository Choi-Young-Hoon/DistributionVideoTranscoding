#include "libvideo/Video.hpp"

#include "libavformat/avformat.h"

Video::Video() 
{
    AVFormatContext* formatCtx = NULL;
    avformat_open_input(&formatCtx, NULL, NULL, NULL);
}

Video::~Video()
{}