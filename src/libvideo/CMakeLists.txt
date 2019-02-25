include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/GlobalProperty.cmake)
include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/FFmpegProperty.cmake)


# sources
set (SOURCES Video.cpp)


# target name
set (LIBVIDEO video)

# compile options
set (CMAKE_CXX_STANDARD ${CPP_VERSION})
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")
add_compile_options (-W -Wall)
link_directories    (${FFMPEG_LIBRARY_DIR})
include_directories (${FFMPEG_INCLUDE_DIR} ${GLOBAL_TRANSCODING_SERVER_PROJECT_INCLUDE_DIR})


# build
add_library (${LIBVIDEO} ${SOURCES})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${LIBVIDEO}.a DESTINATION ${GLOBAL_TRANSCODING_SERVER_PROJECT_LIBRARY_DIR})

