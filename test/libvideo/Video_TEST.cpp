#include "gtest/gtest.h"

#include "libvideo/VideoReader.hpp"

TEST(Video_TEST, OPEN_CLOSE_TEST) {
    vd::VideoError error;
    vd::VideoReader videoReader;

    videoReader.open("test.mp4", &error);
    ASSERT_TRUE(error.isSuccess());
    ASSERT_TRUE(videoReader.isOpen());
    
    videoReader.printInfo();
    videoReader.close();
}