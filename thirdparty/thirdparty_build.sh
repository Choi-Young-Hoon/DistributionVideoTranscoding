#!/bin/bash

root_path=$(pwd)

function gtest_build() {
    mkdir ./googletest/build
    cd ./googletest/build && cmake ..
    make -j$(grep -c processor /proc/cpuinfo)
    cd $root_path
}

function ffmpeg_depend_packet_install() {
    sudo apt-get -y install libx264-dev libx265-dev libmp3lame-dev libvpx-dev libfdk-aac-dev  \
                            autoconf nasm automake build-essential pkg-config zlib1g-dev              
}

function ffmpeg_build() {
    ffmpeg_depend_packet_install
    cd ./ffmpeg && ./configure --prefix=./build --enable-gpl --enable-static --disable-shared --enable-pthreads         \
                               --enable-debug --enable-gpl --enable-libfdk-aac --enable-libfreetype --enable-libmp3lame \
                               --enable-libvpx --enable-libx264 --enable-libx265 --enable-nonfree                       \
                               --enable-libvmaf
    make -j$(grep -c processor /proc/cpuinfo)
	make install
    cd $root_path
}

gtest_build

ffmpeg_depend_packet_install
ffmpeg_build
