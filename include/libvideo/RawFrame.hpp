#ifndef __LIB_VIDEO_RAW_FRAME_HEADER__
#define __LIB_VIDEO_RAW_FRAME_HEADER__

#include "libvideo/CodecParameter.hpp"

struct AVFrame;
namespace av {
	
	class RawFrame {
	public:
		explicit RawFrame();
		virtual ~RawFrame();
		
		friend class Decoder;
		friend class Encoder;

	public:
		bool isAudio();
		void isAudio(bool isAudio);

		void setCodecParameter(CodecParameter& codecParameter);

	private:
		bool m_isAudio;

		AVFrame* m_frame;
	};
};

#endif
