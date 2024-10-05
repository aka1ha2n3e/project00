#!/bin/sh

if [ -d "build/" ]; then
    rm -r build
fi

mkdir build
cd build

if [ -n "$1" ]; then
    cmake .. -DMAIN_FILE="$1"
else
    cmake ..
fi
make

clang-tidy ../src/main.cpp --config-file=../.clang-tidy > tidycheck.txt 2>> tidy-error.txt

cd ..