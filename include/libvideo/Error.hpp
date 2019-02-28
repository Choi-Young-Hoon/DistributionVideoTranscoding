#ifndef __LIB_VIDEO_ERROR_HEADER__
#define __LIB_VIDEO_ERROR_HEADER__

#include <iostream>
#include <string>

#include "libvideo/ErrorDefine.hpp"

namespace vd {

    class Error {
    public:
        static std::string avStrError (int errorCode);
        static std::string getErrorStr(VIDEO_ERROR errorCode);

    public:
        explicit Error();
        explicit Error(int errorCode, std::string errorMessage, bool isSuccess = false);
        virtual ~Error();

    public:
        void success();
        void success(int returnCode);
        void error(int returnCode, std::string errorMessage, bool isSuccess = false);
        
    public:
        bool isSuccess();

        int         returnCode();
        std::string errorMessage();

    private:
        int m_returnCode;
        std::string m_errorMessage;

        bool m_isSuccess;
    };
    
};

#endif