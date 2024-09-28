cmake_minimum_required(VERSION 3.10)
project(TextEditor VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# インクルードディレクトリを設定
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)

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

list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/src/main.cpp")

if (SOURCES STREQUAL "")
    message(FATAL_ERROR "ソースファイルが見つかりません")
endif()

# メインの実行ファイルを作成
add_executable(TextEditor "${PROJECT_SOURCE_DIR}/src/main.cpp" ${SOURCES})

# テスト実行ファイルを作成
add_executable(Test ${TEST_SOURCES} ${SOURCES})


# cursesのリンクをTextEditorターゲットに追加
target_link_libraries(TextEditor ${CURSES_LIBRARIES})

# Google Testライブラリのリンク
target_link_libraries(Test PRIVATE gtest gtest_main pthread ${CURSES_LIBRARIES})

# テストファイルのためのインクルードディレクトリを追加
target_link_libraries(Test PRIVATE gtest gmock gtest_main gmock_main)

# Clang-tidyを有効にする
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CLANG_TIDY_PATH "${CMAKE_SOURCE_DIR}/.clang-tidy")
    if(EXISTS ${CLANG_TIDY_PATH})
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_PATH};-checks=*,-llvm-header-guard,-clang-analyzer-*")
    else()
        message(WARNING "指定されたclang-tidyが見つかりません: ${CLANG_TIDY_PATH}")
    endif()
endif()

# コンパイルオプションの設定
target_compile_options(TextEditor PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(Test PRIVATE -Wall -Wextra -Wpedantic)