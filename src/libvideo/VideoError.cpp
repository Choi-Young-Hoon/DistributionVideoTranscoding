#include "libvideo/VideoError.hpp"

extern "C" {
    #include "libavutil/error.h"
}

using namespace vd;


std::string VideoError::avStrError(int error_code) {
    char error_message[1024] = {0, };
    
    av_strerror(error_code, error_message, 1024);

    return error_message;
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
    this->error_code_ = 0;
    this->error_message_ = "";
    this->is_success_ = true;
}

void VideoError::error(int error_code, std::string error_message, bool is_success) {
    this->error_code_ = error_code;
    this->error_message_ = error_message;
    this->is_success_ = is_success;
}

int VideoError::errorCode() {
    return this->error_code_;
}

std::string VideoError::errorMessage() {
    return this->error_message_;
}

bool VideoError::isSuccess() {
    return this->is_success_;
}