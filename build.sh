#!/bin/sh

if [ -d $"build/" ]; then
    cd build
    if [ ! -f .debug ];then
        cd ..
        rm -r build
        mkdir build
        cd build
        cmake ..
    fi
else
    mkdir build
    cd build
    cmake ..
fi
make
touch .debug
cd ..