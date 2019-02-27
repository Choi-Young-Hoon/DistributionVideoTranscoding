#include "libvideo/VideoError.hpp"
#include "libvideo/VideoErrorDefine.hpp"

extern "C" {
    #include "libavutil/error.h"
}

using namespace vd;


std::string VideoError::avStrError(int error_code) {
    char error_message[1024] = {0, };
    
    av_strerror(error_code, error_message, 1024);

    return error_message;
}

std::string VideoError::getErrorStr(VIDEO_ERROR error_code)  {
    std::string ret_str;
    
    switch (error_code) {
    case SUCCESS:         ret_str = "Success";         break;
    case FILE_NOT_OPENED: ret_str = "File not opened"; break;
    case FILE_EOF:        ret_str = "File EOF";        break;
    
    default:
        ret_str = "Unknown";
    }

    return ret_str;
}


VideoError::VideoError() {
    this->success();
}

VideoError::VideoError(int error_code, std::string error_message, bool is_success) {
    this->error(error_code, error_message, is_success);
}

VideoError::~VideoError() 
{}


void VideoError::success() {
    this->success(0);
}

void VideoError::success(int return_code) {
    this->return_code_ = return_code;
    this->error_message_ = "";
    this->is_success_ = true;
}

void VideoError::error(int error_code, std::string error_message, bool is_success) {
    this->return_code_ = error_code;
    this->error_message_ = error_message;
    this->is_success_ = is_success;
}

int VideoError::returnCode() {
    return this->return_code_;
}

std::string VideoError::errorMessage() {
    return this->error_message_;
}

bool VideoError::isSuccess() {
    return this->is_success_;
}