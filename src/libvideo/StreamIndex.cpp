#include "libvideo/StreamIndex.hpp"

using namespace vd;

StreamIndex::StreamIndex()
: video_stream_index_(0), audio_stream_index_(0)
{}

StreamIndex::StreamIndex(int video_stream_index, int audio_stream_index)
: video_stream_index_(video_stream_index), audio_stream_index_(audio_stream_index)
{}

StreamIndex::~StreamIndex()
{}


int StreamIndex::videoStreamIndex() {
    return this->video_stream_index_;
}

void StreamIndex::videoStreamIndex(int video_stream_index) {
    this->video_stream_index_ = video_stream_index;
}

int StreamIndex::audioStreamIndex() {
    return this->audio_stream_index_;
}

void StreamIndex::audioStreamIndex(int audio_stream_index) {
    this->audio_stream_index_ = audio_stream_index;
}