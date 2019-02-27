include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/GTestProperty.cmake)
include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/FFmpegProperty.cmake)
include (${TRANSCODING_SERVER_PROJECT_SOURCE_DIR}/cmake/GlobalProperty.cmake)

# target
set (OUTPUT test.out)

# sources
set (SOURCES main.cpp
             Video_TEST.cpp
             ByteBuffer_TEST.cpp
)


#compile options
include_directories (${GTEST_INCLUDE_DIR} ${FFMPEG_INCLUDE_DIR} ${GLOBAL_TRANSCODING_SERVER_PROJECT_INCLUDE_DIR})
link_directories    (${GTEST_LIBRARY_DIR} ${FFMPEG_LIBRARY_DIR} ${GLOBAL_TRANSCODING_SERVER_PROJECT_LIBRARY_DIR})


add_executable(${OUTPUT} ${SOURCES})
target_link_libraries(${OUTPUT} ${GTEST_LIBRARYS} ${VIDEO_LIBRARY} ${FFMPEG_LIBRARYS} ${FFMPEG_DEPENDENCY_LIBRARYS})


install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT} DESTINATION ${GLOBAL_TRANSCODING_SERVER_PROJECT_BIN_DIR})
message (${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT})