#!/bin/bash

root_path=$(pwd)

function third_party_build() {
    cd $root_path/thirdparty && ./thirdparty_build.sh
}

third_party_build
