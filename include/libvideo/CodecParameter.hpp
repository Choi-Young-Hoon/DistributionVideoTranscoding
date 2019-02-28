#ifndef __LIB_VIDEO_CODEC_PARAMETER_HEADER__
#define __LIB_VIDEO_CODEC_PARAMETER_HEADER__

#include <iostream>

#include "libvideo/Rational.hpp"

struct AVCodecParameters;
namespace av {
    
    class CodecParameter {
    public:
        explicit CodecParameter();
        virtual ~CodecParameter();

		friend class VideoReader;
		friend class Codec;
	
	public:
		int64_t bitRate();
		void	bitRate(int64_t bitRate);

		Rational timeBase();
		Rational frameRate();
		void timeBase (Rational timeBase);
		void frameRate(Rational frameRate);

		int  width();
		int  height();
		void width (int width);
		void height(int height);
		
		int  gopSize();
		int  maxBFrames();
		void gopSize(int gopSize);
		void maxBFrames(int maxBFrames);

		int  pixelFormat();
		void pixelFormat(int pixelFormat);

    private:
        AVCodecParameters* m_codecParameter;

		// Encoding
		int64_t m_bitRate;
		
		Rational m_frameRate;
		Rational m_timeBase;

		int m_width;
		int m_height;

		int m_gopSize;
		int m_maxBFrames;
		
		int m_pixelFormat;
    };

};

#endif
