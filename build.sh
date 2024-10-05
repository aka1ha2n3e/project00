#!/bin/sh

if [ -d $"build/" ]; then
    cd build
    if [ ! -f .debug ];then
        cd ..
        rm -r build
        mkdir build
        cd build
        if [ -n "$1" ]; then
            cmake .. -DMAIN_FILE="$1"
        else
            cmake ..
        fi
        touch .debug
    fi
else
    mkdir build
    cd build
    if [ -n "$1" ]; then
        cmake .. -DMAIN_FILE="$1"
    else
        cmake ..
    fi
    touch .debug
fi
make
clang-tidy ../src/main.cpp --config-file=../.clang-tidy > tidycheck.txt 2>> tidy-error.txt
cd ..