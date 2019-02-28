#include "libvideo/CodecManager.hpp"
#include "libvideo/DecodeCodec.hpp"
#include "libvideo/EncodeCodec.hpp"

extern "C" {
    #include "libavcodec/avcodec.h"
}

using namespace vd;

CodecManager::CodecManager()
{}

CodecManager::~CodecManager()
{}


Codec* CodecManager::CreateCodec(CODEC_TYPE codecType, CODEC_ID codecID, CodecParameter& codecParamter, Error* error) {
    Codec* codec = CodecManager::CreateCodec(codecType, error);
    if (error->isSuccess() == false) {
        return NULL;
    }

	codec->initializeCodec(codecID, codecParamter, error);
	if (error->isSuccess() == false) {
		return NULL;
	}

    return codec;
}

Codec* CodecManager::CreateCodec(CODEC_TYPE codecType, Error* error) {
    Codec* codec = NULL;

    switch (codecType) {
    case DECODE: codec = CodecManager::CreateDecodeCodec(error); break;
    case ENCODE: codec = CodecManager::CreateEncodeCodec(error); break;
    default:
        error->error(AV_CODEC_ID_NONE, "Invalid codec type");
        return NULL;
    }

	if (error->isSuccess() == false) {
		return NULL;
	}

    error->success();
    return codec;
}

Codec* CodecManager::CreateEncodeCodec(Error* error) {
    Codec* codec = new EncodeCodec();
	if (codec == NULL) {
		error->error(MEMORY_ALLOC_FAILED, "Memory alloc failed to VideoEncodeCodec (NULL)");
		return NULL;
	}

    error->success();
    return codec;
}   

Codec* CodecManager::CreateDecodeCodec(Error* error) {
    Codec* codec = new DecodeCodec();
	if (codec == NULL) {
		error->error(MEMORY_ALLOC_FAILED, "Memory alloc failed to VideoDecodeCodec (NULL)");
		return NULL;
	}

    error->success();
    return codec;
}
