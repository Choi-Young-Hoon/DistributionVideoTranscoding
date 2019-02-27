#ifndef __LIB_VIDEO_ERROR_HEADER__
#define __LIB_VIDEO_ERROR_HEADER__

#include <iostream>
#include <string>

namespace vd {

    class VideoError {
    public:
        static std::string avStrError(int error);

    public:
        explicit VideoError();
        explicit VideoError(int error_code, std::string error_message, bool is_success = false);
        virtual ~VideoError();

    public:
        void success();
        void success(int return_code);
        void error(int return_code, std::string error_message, bool is_success = false);
        
    public:
        bool isSuccess();

        int         returnCode();
        std::string errorMessage();

    private:
        int return_code_;
        std::string error_message_;

        bool is_success_;
    };
    
};

#endif