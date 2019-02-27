#include "libvideo/VideoError.hpp"
#include "libvideo/VideoErrorDefine.hpp"

extern "C" {
    #include "libavutil/error.h"
}

using namespace vd;


std::string VideoError::avStrError(int errorCode) {
    char errorMessage[1024] = {0, };
    
    av_strerror(errorCode, errorMessage, 1024);

    return errorMessage;
}

std::string VideoError::getErrorStr(VIDEO_ERROR errorCode)  {
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


VideoError::VideoError() {
    this->success();
}

VideoError::VideoError(int errorCode, std::string errorMessage, bool isSuccess) {
    this->error(errorCode, errorMessage, isSuccess);
}

VideoError::~VideoError() 
{}


void VideoError::success() {
    this->success(0);
}

void VideoError::success(int returnCode) {
    this->m_returnCode   = returnCode;
    this->m_errorMessage = "";
    this->m_isSuccess    = true;
}

void VideoError::error(int errorCode, std::string errorMessage, bool isSuccess) {
    this->m_returnCode   = errorCode;
    this->m_errorMessage = errorMessage;
    this->m_isSuccess    = isSuccess;
}

int VideoError::returnCode() {
    return this->m_returnCode;
}

std::string VideoError::errorMessage() {
    return this->m_errorMessage;
}

bool VideoError::isSuccess() {
    return this->m_isSuccess;
}