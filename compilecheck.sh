
#!/bin/sh


if [ -d $"build/" ]; then
    cd build
    if [ ! -f .comp ];then
        cd ..
        rm -r build
        mkdir build
        cd build
        cmake ../compile/
    fi
else
    mkdir build
    cd build
    cmake ../compile/
fi
touch .comp
make
cd ..
echo "リンクエラーは認識しないので注意してください"