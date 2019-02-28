#include "gtest/gtest.h"

#include "libvideo/ByteBuffer.hpp"
#include "libvideo/VideoReader.hpp"
#include "libvideo/Codec.hpp"
#include "libvideo/CodecManager.hpp"
#include "libvideo/CodecParameter.hpp"
#include "libvideo/EncodedFrame.hpp"
#include "libvideo/RawFrame.hpp"
#include "libvideo/Encoder.hpp"
#include "libvideo/Decoder.hpp"
#include "libvideo/Rational.hpp"

#define TEST_FILE "./test.mp4"

TEST(Video_TEST, OPEN_CLOSE_TEST) {
    av::Error error;
    av::VideoReader videoReader;

    videoReader.open(TEST_FILE, &error);
    ASSERT_TRUE(error.isSuccess());
    ASSERT_TRUE(videoReader.isOpen());
    
    videoReader.close();
}

TEST(Video_TEST, READ_FRAME_TEST) {
    av::Error error;
    av::VideoReader videoReader;

    videoReader.open(TEST_FILE, &error);
    ASSERT_TRUE(error.isSuccess());

    av::EncodedFrame frame;
    while (true) {
        videoReader.readFrame(&frame, &error);
        if (error.returnCode() == av::FILE_EOF) {
            break;
        }
        ASSERT_TRUE(error.isSuccess());
    }
}

TEST(Video_TEST, CREATE_DECODE_CODEC_TEST) {
    av::Error error;
    av::VideoReader videoReader;
    videoReader.open(TEST_FILE, &error);
    ASSERT_TRUE(error.isSuccess());

	av::Codec* videoCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.videoCodecID(), videoReader.videoCodecParameter(), &error);
    ASSERT_TRUE(error.isSuccess());

    av::Codec* audioCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.audioCodecID(), videoReader.audioCodecParameter(), &error);
    ASSERT_TRUE(error.isSuccess());

    delete videoCodec;    
    delete audioCodec;
}

TEST(Video_TEST, DECODE_FRAME_TEST) {
	av::Error error;
	av::VideoReader videoReader;
	videoReader.open(TEST_FILE, &error);
	ASSERT_TRUE(error.isSuccess());

	av::Codec* videoCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.videoCodecID(), videoReader.videoCodecParameter(), &error);
	ASSERT_TRUE(error.isSuccess());

	av::Codec* audioCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.audioCodecID(), videoReader.audioCodecParameter(), &error);
	ASSERT_TRUE(error.isSuccess());

	av::StreamIndex streamIndex = videoReader.streamIndex();
	av::Decoder decoder(streamIndex, videoCodec, audioCodec);
	av::RawFrame rawFrame;
	av::EncodedFrame encodedFrame;
	while (true) {
		videoReader.readFrame(&encodedFrame, &error);
		ASSERT_TRUE(error.isSuccess());
		if (error.returnCode() == av::FILE_EOF) {
			break;
		}

		decoder.Decode(encodedFrame, &rawFrame, &error);
		ASSERT_TRUE(error.isSuccess());
	}

	delete videoCodec;
	delete audioCodec;
}

TEST(Video_TEST, CREATE_ENCODE_CODEC_TEST) {
	av::Error error;
	av::VideoReader videoReader;
	videoReader.open(TEST_FILE, &error);
	ASSERT_TRUE(error.isSuccess());

	av::Codec* videoDecodeCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.videoCodecID(), videoReader.videoCodecParameter(), &error);
	ASSERT_TRUE(error.isSuccess());
	av::Codec* audioDecodeCodec = av::CodecManager::CreateCodec(av::DECODE, videoReader.audioCodecID(), videoReader.audioCodecParameter(), &error);
	ASSERT_TRUE(error.isSuccess());

	av::CodecParameter videoEncodeCodecParameter = videoReader.videoCodecParameter();
	videoEncodeCodecParameter.bitRate(videoReader.bitRate());
	videoEncodeCodecParameter.frameRate(av::Rational(25, 1));
	videoEncodeCodecParameter.timeBase(av::Rational(1, 25));
	videoEncodeCodecParameter.width(640);
	videoEncodeCodecParameter.height(480);
	videoEncodeCodecParameter.maxBFrames(1);
	videoEncodeCodecParameter.gopSize(3);

	av::Codec* videoEncodeCodec = av::CodecManager::CreateCodec(av::ENCODE, videoReader.videoCodecID(), videoEncodeCodecParameter, &error);
	ASSERT_TRUE(error.isSuccess());

	av::StreamIndex streamIndex = videoReader.streamIndex();

	av::Decoder decoder(streamIndex, videoDecodeCodec, audioDecodeCodec);;
	av::Encoder encoder(videoEncodeCodec, NULL);

	av::RawFrame rawFrame;
	av::EncodedFrame encodedFrame;
	av::EncodedFrame encodingFrame;
	while (true) {
		videoReader.readFrame(&encodedFrame, &error);
		ASSERT_TRUE(error.isSuccess());
		if (error.returnCode() == av::FILE_EOF) {
			break;
		}

		decoder.Decode(encodedFrame, &rawFrame, &error);
		ASSERT_TRUE(error.isSuccess());
		
		rawFrame.setCodecParameter(videoEncodeCodecParameter);
		encoder.Encode(rawFrame, &encodingFrame, &error);
		ASSERT_TRUE(error.isSuccess());
	}
	
	delete videoDecodeCodec;
	delete audioDecodeCodec;
	delete videoEncodeCodec;
}
