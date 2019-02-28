#ifndef __LIB_VIDEO_CODEC_MANAGER_HEADER__
#define __LIB_VIDEO_CODEC_MANAGER_HEADER__

#include "libvideo/Error.hpp"
#include "libvideo/Type.hpp"
#include "libvideo/Codec.hpp"
#include "libvideo/CodecParameter.hpp"

namespace av {

    class CodecManager {
    public:
        static Codec* CreateCodec(CODEC_TYPE codecType, CODEC_ID codecID, CodecParameter codecParamter, Error* error);

    private:
        static Codec* CreateCodec(CODEC_TYPE codecType, Error* error);
        
        static Codec* CreateEncodeCodec(Error* error);
        static Codec* CreateDecodeCodec(Error* error);

    private:
        explicit CodecManager();
        virtual ~CodecManager();
    };

};

#endif
