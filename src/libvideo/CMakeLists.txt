include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/GlobalProperty.cmake)
include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/FFmpegProperty.cmake)


# sources
set (SOURCES VideoReader.cpp
             VideoError.cpp
             VideoEncodedFrame.cpp
             StreamIndex.cpp
             ByteBuffer.cpp)


# target name
set (LIBVIDEO ${VIDEO_LIBRARY})

# compile options
link_directories    (${FFMPEG_LIBRARY_DIR})
include_directories (${FFMPEG_INCLUDE_DIR} ${GLOBAL_TRANSCODING_SERVER_PROJECT_INCLUDE_DIR})


# build
add_library (${LIBVIDEO} ${SOURCES})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${LIBVIDEO}.a DESTINATION ${GLOBAL_TRANSCODING_SERVER_PROJECT_LIBRARY_DIR})

