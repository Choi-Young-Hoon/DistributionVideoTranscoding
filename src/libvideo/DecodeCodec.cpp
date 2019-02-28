#include "libvideo/DecodeCodec.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
};

using namespace av;

DecodeCodec::DecodeCodec()
: Codec(DECODE)
{}

DecodeCodec::~DecodeCodec()
{}


AVCodec* DecodeCodec::createCodec(CODEC_ID codecID) {
    if (codecID < 0) {
        return NULL;
    }

    AVCodec* codec = avcodec_find_decoder((AVCodecID)codecID);
    if (codec == NULL) {
        return NULL;
    }
    
    return codec;
}
