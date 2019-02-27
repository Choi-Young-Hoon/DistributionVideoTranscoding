#include "gtest/gtest.h"

#include "libvideo/ByteBuffer.hpp"

const unsigned char* g_data   = (unsigned char*)"OOOO111122223333";
const int            g_length = 16;

TEST(ByteBuffer_TEST, BYTE_BUFFER_INIT) {
    vd::ByteBuffer buffer(g_data, g_length);
    ASSERT_EQ(buffer.getLength(), g_length);

    for (int i = 0; i < buffer.getLength(); i++) {
        ASSERT_EQ(buffer[i], g_data[i]);
    }
}

TEST(ByteBuffer_TEST, REFER_TEST) {
    vd::ByteBuffer buffer(g_data, g_length);
    ASSERT_EQ(buffer.getLength(), g_length);

    {
        vd::ByteBuffer referBuffer_1;
        referBuffer_1 = buffer;
        ASSERT_EQ(buffer.getLength(), referBuffer_1.getLength());
        
        vd::ByteBuffer referBuffer_2(buffer);
        ASSERT_EQ(buffer.getLength(), referBuffer_2.getLength());

        vd::ByteBuffer referBuffer_3;
        referBuffer_3.setData(buffer);
        ASSERT_EQ(buffer.getLength(), referBuffer_3.getLength());

        referBuffer_1[0] = (unsigned char)'1';
        referBuffer_2[1] = (unsigned char)'1';
        referBuffer_3[2] = (unsigned char)'1';
    }

    ASSERT_EQ(buffer[0], (unsigned char)'1');
    ASSERT_EQ(buffer[1], (unsigned char)'1');
    ASSERT_EQ(buffer[2], (unsigned char)'1');
}

TEST(ByteBuffer_TEST, CLONE_TEST) {
    vd::ByteBuffer buffer(g_data, g_length);
    ASSERT_EQ(buffer.getLength(), g_length);

    {
        vd::ByteBuffer referBuffer;
        referBuffer = buffer.clone();
        ASSERT_EQ(buffer.getLength(), referBuffer.getLength());

        referBuffer[0] = (unsigned char)'1';    
    }

    ASSERT_EQ(buffer[0], g_data[0]);
}

TEST(ByteBuffer_TEST, APPEND_TEST) {
    vd::ByteBuffer buffer_1(g_data, g_length);
    ASSERT_EQ(buffer_1.getLength(), g_length);

    vd::ByteBuffer buffer_2(g_data, g_length);
    ASSERT_EQ(buffer_2.getLength(), g_length);

    int tempBuffer1Length = buffer_1.getLength();
    buffer_1.append(buffer_2);
    ASSERT_EQ(buffer_1.getLength(), g_length * 2);
    ASSERT_EQ(buffer_2.getLength(), g_length);

    for (int i = 0; i < tempBuffer1Length; i++) {
        ASSERT_EQ(buffer_1[i], g_data[i]);
    }

    for (int i = tempBuffer1Length; i < buffer_1.getLength(); i++) {
        ASSERT_EQ(buffer_1[i], g_data[i - tempBuffer1Length]);
    }
}

TEST(ByteBuffer_TEST, SUB_TEST) {
    vd::ByteBuffer buffer(g_data, g_length);
    ASSERT_EQ(buffer.getLength(), g_length);

    vd::ByteBuffer subBuffer_1 = buffer.sub(0, 4);
    vd::ByteBuffer subBuffer_2 = buffer.sub(4, 8);
    vd::ByteBuffer subBuffer_3 = buffer.sub(8, 12);

    for (int i = 0; i < subBuffer_1.getLength(); i++) {
        ASSERT_EQ(subBuffer_1[i], g_data[i]);
        ASSERT_EQ(subBuffer_2[i], g_data[i + 4]);
        ASSERT_EQ(subBuffer_3[i], g_data[i + 8]);
    }
}