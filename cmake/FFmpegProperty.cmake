set (FFMPEG_DIR ${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/thirdparty/ffmpeg/build)
set (FFMPEG_INCLUDE_DIR ${FFMPEG_DIR}/include)
set (FFMPEG_LIBRARY_DIR ${FFMPEG_DIR}/lib)


find_library (FFMPEG_AVCODEC_LIB    NAMES libavcodec.a    HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_AVDEVICE_LIB   NAMES libavdevice.a   HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_AVFILTER_LIB   NAMES libavfilter.a   HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_AVFORMAT_LIB   NAMES libavformat.a   HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_AVUTIL_LIB     NAMES libavutil.a     HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_POSTPROC_LIB   NAMES libpostproc.a   HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_SWRESAMPLE_LIB NAMES libswresample.a HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)
find_library (FFMPEG_SWSCALE_LIB    NAMES libswscale.a    HINTS ${FFMPEG_LIBRARY_DIR} REQUIRED)


set (FFMPEG_LIBRARYS ${FFMPEG_AVFORMAT_LIB}
                     ${FFMPEG_AVCODEC_LIB}
                     ${FFMPEG_SWSCALE_LIB}
                     ${FFMPEG_AVUTIL_LIB}
                     ${FFMPEG_AVFILTER_LIB}
                     ${FFMPEG_SWRESAMPLE_LIB}
                     ${FFMPEG_AVDEVICE_LIB}
                     ${FFMPEG_POSTPROC_LIB}
                     
                     # Other
                     -lpthread
                     -lX11
                     -lvpx
                     -lva
                     -lva-drm
                     -lva-x11
                     -lx264
                     -lx265
                     -lz 
                     -lrt
                     -lssh
                     -lbluray
                     -lfdk-aac
                     -lmp3lame
                     -lvdpau
                     -lgnutls
                     )