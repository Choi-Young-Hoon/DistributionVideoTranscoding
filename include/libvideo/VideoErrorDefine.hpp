#ifndef __LIB_VIDEO_ERROR_DEFINE_HEADER__
#define __LIB_VIDEO_ERROR_DEFINE_HEADER__

#include <string>


#define VIDEO_ALLOC_EXCEPTION(mem)                            \
if ((mem) == NULL) {                                          \
    std::cout << "temp error message - NULL..." << std::endl; \
}


namespace vd {

    enum _VIDEO_ERROR {
        SUCCESS = 0,

        FILE_NOT_OPENED = 1000,
        FILE_EOF,
    };
    typedef enum _VIDEO_ERROR VIDEO_ERROR;
};

#endif