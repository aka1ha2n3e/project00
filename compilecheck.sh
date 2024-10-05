
#!/bin/sh


if [ -d $"build/" ]; then
    cd build
    if [ ! -f .comp ];then
        cd ..
        rm -r build

        mkdir build
        cd build

        if [ -n "$1" ]; then
            cmake ../compile/ -DMAIN_FILE="$1"
        else
            cmake ../compile/
        fi
        make
        touch .comp
    else
        make
    fi
else
    mkdir build
    cd build

    if [ -n "$1" ]; then
        cmake ../compile/ -DMAIN_FILE="$1"
    else
        cmake ../compile/
    fi

    make
    touch .comp
fi

clang-tidy ../src/main.cpp --config-file=../.clang-tidy > tidycheck.txt 2>> tidy-error.txt

cd ..
echo "リンクエラーは認識しないので注意してください"