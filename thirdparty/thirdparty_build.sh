#!/bin/bash

root_path=$(pwd)

function gtest_build() {
    mkdir ./gtest/build
    cd ./gtest/build && cmake ..
    make -j$(grep -c processor /proc/cpuinfo)
    cd $root_path
}

function ffmpeg_depend_package_install() {
    sudo apt-get -y install libx264-dev libx265-dev libmp3lame-dev libvpx-dev libfdk-aac-dev  \
                            autoconf nasm automake build-essential pkg-config zlib1g-dev      \
                            libvdpau-dev libva-dev libx11-dev libgnutls28-dev libssh-dev libbluray-dev libva-dev
}

function ffmpeg_build() {
    ffmpeg_depend_packet_install
    cd ./ffmpeg && ./configure --prefix=./build --enable-gpl --enable-static --disable-shared --enable-pthreads         \
                               --enable-debug --enable-libmp3lame \
                               --enable-libvpx --enable-libx264 --enable-libx265                     
    make -j$(grep -c processor /proc/cpuinfo)
	make install
    cd $root_path
}


ffmpeg_depend_package_install

gtest_build
ffmpeg_build
