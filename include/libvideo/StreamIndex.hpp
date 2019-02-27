#ifndef __LIB_VIDEO_STREAM_INDEX_HEADER__
#define __LIB_VIDEO_STREAM_INDEX_HEADER__

namespace vd {

    class StreamIndex {
    public:
        explicit StreamIndex();
        explicit StreamIndex(int videoStreamIndex, int audioStreamIndex);
        virtual ~StreamIndex();

    public:
        int  videoStreamIndex();
        void videoStreamIndex(int videoStreamIndex);

        int  audioStreamIndex();
        void audioStreamIndex(int audioStreamIndex);

    private:
        int m_videoStreamIndex;
        int m_audioStreamIndex;
    };
    
};

#endif