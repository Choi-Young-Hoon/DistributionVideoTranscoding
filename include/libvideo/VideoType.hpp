#ifndef __LIB_VIDEO_TYPE_HEADER__
#define __LIB_VIDEO_TYPE_HEADER__

#include <iostream>
#include <cstring>

namespace vd {

    enum _FRAME_TYPE {
        VIDEO = 0,
        AUDIO,
    };
    typedef enum _FRAME_TYPE FRAME_TYPE;

    enum _CODEC_TYPE {
        ENCODE = 0,
        DECODE,
    };
    typedef enum _CODEC_TYPE CODEC_TYPE;

};


typedef int STREAM_INDEX;
typedef int CODEC_ID;
#endif