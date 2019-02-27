#include "gtest/gtest.h"

#include "libvideo/ByteBuffer.hpp"
#include "libvideo/VideoReader.hpp"

#define TEST_FILE "./test.mp4"

TEST(Video_TEST, OPEN_CLOSE_TEST) {
    vd::VideoError error;
    vd::VideoReader videoReader;

    videoReader.open(TEST_FILE, &error);
    ASSERT_TRUE(error.isSuccess());
    ASSERT_TRUE(videoReader.isOpen());
    
    videoReader.close();
}

TEST(Video_TEST, READ_FRAME_TEST) {
    vd::VideoError error;
    vd::VideoReader videoReader;

    videoReader.open(TEST_FILE, &error);
    ASSERT_TRUE(error.isSuccess());

    int frameCount = 0;
    vd::VideoEncodedFrame frame;
    while (true) {
        videoReader.readFrame(&frame, &error);
        if (error.returnCode() == vd::FILE_EOF) {
            break;
        }
        ASSERT_TRUE(error.isSuccess());
    }
}