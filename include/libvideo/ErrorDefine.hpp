#ifndef __LIB_VIDEO_ERROR_DEFINE_HEADER__
#define __LIB_VIDEO_ERROR_DEFINE_HEADER__

#include <string>


#define AV_ALLOC_EXCEPTION(mem)                            \
if ((mem) == NULL) {                                          \
    std::cout << "temp error message - NULL..." << std::endl; \
}


namespace av {

    enum _VIDEO_ERROR {
        SUCCESS = 0,

        FILE_NOT_OPENED = 1000,
        FILE_EOF,

		MEMORY_ALLOC_FAILED = 1000,
    };
    typedef enum _VIDEO_ERROR VIDEO_ERROR;
};

#endif
