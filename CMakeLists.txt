cmake_minimum_required (VERSION 3.6)

project (DistributionVideoTranscodingServer)
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 0)

set (CMAKE_BUILD_TYPE Debug)


add_subdirectory(thirdparty)
add_subdirectory(src)