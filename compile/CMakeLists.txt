cmake_minimum_required(VERSION 3.10)

# プロジェクト名とバージョン
project(TextEditor VERSION 1.0)

# C++の標準を設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# コンパイルフラグを設定（-O0 で最適化なし）
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# インクルードディレクトリを設定
include_directories(${PROJECT_SOURCE_DIR}/../include)

# ソースファイルを指定
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/../src/*.cpp"
)

list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/compch.cpp")

# ソースファイルが見つからなかった場合のチェック
if (SOURCES STREQUAL "")
    message(FATAL_ERROR "No source files found in src directory")
endif()

# objectファイルとしてのみビルド
add_library(core_object OBJECT ${SOURCES})

# Clang-tidyを有効にする
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*,-llvm-header-guard,-clang-analyzer-*")
endif()

# コンパイルオプションの設定
target_compile_options(core_object PRIVATE -Wall -Wextra -Wpedantic)