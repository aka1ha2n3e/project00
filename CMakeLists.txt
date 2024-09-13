cmake_minimum_required(VERSION 3.10)

# プロジェクト名とバージョン
project(TextEditor VERSION 1.0)

# C++の標準を設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# インクルードディレクトリを設定
include_directories(${PROJECT_SOURCE_DIR}/include)

# Google Testをサブモジュールから追加
add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)

# cursesの読み込み
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

# ソースファイルを指定
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# テストソースファイルを指定
file(GLOB_RECURSE TEST_SOURCES
    "${PROJECT_SOURCE_DIR}/test/*.cpp"
)

# main.cpp をSOURCESから除外
list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/src/main.cpp")

# ソースファイルが見つからなかった場合のチェック
if (SOURCES STREQUAL "")
    message(FATAL_ERROR "No source files found in src directory")
endif()

# 実行ファイルを作成
add_executable(TextEditor "${PROJECT_SOURCE_DIR}/src/main.cpp" ${SOURCES}
        src/common.cpp)
add_executable(Test ${TEST_SOURCES} ${SOURCES}
        src/common.cpp)

# cursesのリンクをTextEditorターゲットにも追加
target_link_libraries(TextEditor ${CURSES_LIBRARIES})

# Google Testライブラリのリンク方法を修正
target_link_libraries(Test PRIVATE gtest gtest_main pthread ${CURSES_LIBRARIES})

# テストファイルのためのインクルードディレクトリを追加
target_include_directories(Test PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Clang-tidyを有効にする
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*,-llvm-header-guard,-clang-analyzer-*")
endif()

# コンパイルオプションの設定
target_compile_options(TextEditor PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(Test PRIVATE -Wall -Wextra -Wpedantic)
