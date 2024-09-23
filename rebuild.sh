#!/bin/sh

if [ -d $"build/" ]; then
    echo "rebuild"
    rm -r build
fi
mkdir build
cd build
cmake ..
make
cd ..