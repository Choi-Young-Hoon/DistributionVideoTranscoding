#ifndef __LIB_VIDEO_STREAM_INDEX_HEADER__
#define __LIB_VIDEO_STREAM_INDEX_HEADER__

namespace vd {
    class StreamIndex {
    public:
        explicit StreamIndex();
        explicit StreamIndex(int video_stream_index, int audio_stream_index);
        virtual ~StreamIndex();

    public:
        int  videoStreamIndex();
        void videoStreamIndex(int video_stream_index);

        int  audioStreamIndex();
        void audioStreamIndex(int audio_stream_index);

    private:
        int video_stream_index_;
        int audio_stream_index_;
    };
};

#endif