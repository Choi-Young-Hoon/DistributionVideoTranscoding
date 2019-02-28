#include "libvideo/Error.hpp"
#include "libvideo/ErrorDefine.hpp"

extern "C" {
    #include "libavutil/error.h"
}

using namespace av;


std::string Error::avStrError(int errorCode) {
    char errorMessage[1024] = {0, };
    
    av_strerror(errorCode, errorMessage, 1024);

    return errorMessage;
}

std::string Error::getErrorStr(VIDEO_ERROR errorCode)  {
    std::string retStr;
    
    switch (errorCode) {
    case SUCCESS:         retStr = "Success";         break;
    case FILE_NOT_OPENED: retStr = "File not opened"; break;
    case FILE_EOF:        retStr = "File EOF";        break;
    
    default:
        retStr = "Unknown";
    }

    return retStr;
}


Error::Error() {
    this->success();
}

Error::Error(int errorCode, std::string errorMessage, bool isSuccess) {
    this->error(errorCode, errorMessage, isSuccess);
}

Error::~Error() 
{}


void Error::success() {
    this->success(0);
}

void Error::success(int returnCode) {
    this->m_returnCode   = returnCode;
    this->m_errorMessage = "";
    this->m_isSuccess    = true;
}

void Error::error(int errorCode, std::string errorMessage, bool isSuccess) {
    this->m_returnCode   = errorCode;
    this->m_errorMessage = errorMessage;
    this->m_isSuccess    = isSuccess;
}

int Error::returnCode() {
    return this->m_returnCode;
}

std::string Error::errorMessage() {
    return this->m_errorMessage;
}

bool Error::isSuccess() {
    return this->m_isSuccess;
}