#include "libvideo/CodecParameter.hpp"

#include <iostream>

extern "C" {
	#include "libavformat/avformat.h"
}

using namespace av;

CodecParameter::CodecParameter()
: m_codecParameter(NULL)
, m_pixelFormat(AV_PIX_FMT_YUV420P)
{}

CodecParameter::~CodecParameter()
{}


int64_t CodecParameter::bitRate() {
	return this->m_bitRate;
}

void CodecParameter::bitRate(int64_t bitRate) {
	this->m_bitRate = bitRate;
}

Rational CodecParameter::timeBase() {
	return this->m_timeBase;
}

Rational CodecParameter::frameRate() {
	return this->m_frameRate;
}

void CodecParameter::timeBase(Rational timeBase) {
	this->m_timeBase = timeBase;
}

void CodecParameter::frameRate(Rational frameRate) {
	this->m_frameRate = frameRate;
}

int CodecParameter::width() {
	return this->m_width;
}

int CodecParameter::height() {
	return this->m_height;
}

void CodecParameter::width(int width) {
	this->m_width = width;
}

void CodecParameter::height(int height) {
	this->m_height = height;
}

int CodecParameter::gopSize() {
	return this->m_gopSize;
}

int CodecParameter::maxBFrames() {
	return this->m_maxBFrames;
}

void CodecParameter::gopSize(int gopSize) {
	this->m_gopSize = gopSize;
}

void CodecParameter::maxBFrames(int maxBFrame) {
	this->m_maxBFrames = maxBFrame;
}

int CodecParameter::pixelFormat() {
	return this->m_pixelFormat;
}

void CodecParameter::pixelFormat(int pixelFormat) {
	this->m_pixelFormat = pixelFormat;
}

