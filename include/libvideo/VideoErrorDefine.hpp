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
    };
    typedef enum _VIDEO_ERROR VIDEO_ERROR;


    static std::string getErrorStr(VIDEO_ERROR error_code) {
        std::string ret_str;
        
        switch (error_code) {
        case SUCCESS:         ret_str = "Success";         break;
        case FILE_NOT_OPENED: ret_str = "File not opened"; break;

        default:
            ret_str = "Unknown";
        }

        return ret_str;
    }

};

#endif