#include "libvideo/VideoCodecManager.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace vd;

VideoCodecManager::VideoCodecManager() 
{}

VideoCodecManager::~VideoCodecManager()
{}


VideoCodec* VideoCodecManager::CreateCodec(CODEC_TYPE codecType, CODEC_ID codecID, VideoCodecParameter& codecParamter, VideoError* error) {
    VideoCodec* codec = VideoCodecManager::CreateCodec(codecType, error);
    if (error->isSuccess() == false) {
        return NULL;
    }


    return codec;
}

VideoCodec* VideoCodecManager::CreateCodec(CODEC_TYPE codecType, VideoError* error) {
    VideoCodec* codec = NULL;

    switch (codecType) {
    case DECODE: CreateDecodeCodec(error); break;
    case ENCODE: CreateEncodeCodec(error); break;
    default:
        error->error(AV_CODEC_ID_NONE, "Invalid codec type");
        return NULL;
    }

    error->success();
    return codec;
}

VideoCodec* VideoCodecManager::CreateEncodeCodec(VideoError* error) {
    VideoCodec* codec = NULL;

    error->success();
    return codec;
}   

VideoCodec* VideoCodecManager::CreateDecodeCodec(VideoError* error) {
    VideoCodec* codec = NULL;

    error->success();
    return codec;
}