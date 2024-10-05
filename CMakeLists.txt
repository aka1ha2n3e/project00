cmake_minimum_required(VERSION 3.10)
project(TextEditor VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

option(BUILD_PURPOSE "メインファイル.デフォルトではリリースファイル" "exe")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# インクルードディレクトリ
include_directories(${PROJECT_SOURCE_DIR}/include)

if("${BUILD_PURPOSE}" MATCHES ".*Test")
    add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)
endif()


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

# ソースファイルを指定
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/src/main.cpp")

if("${BUILD_PURPOSE}" MATCHES "exe")
    # メインの実行ファイルを作成
    add_executable(TextEditor "${PROJECT_SOURCE_DIR}/src/main.cpp" ${SOURCES})
    # cursesのリンクをTextEditorターゲットに追加
    target_link_libraries(TextEditor ${CURSES_LIBRARIES})
    # コンパイルオプションの設定
    target_compile_options(TextEditor PRIVATE -Wall -Wextra -Wpedantic)
endif()


if("${BUILD_PURPOSE}" MATCHES "UITest")
    # テストソースファイルを指定
    file(GLOB_RECURSE UI_TEST_SOURCES
        "${PROJECT_SOURCE_DIR}/test/UITest.cpp"
    )
    # テスト実行ファイルを作成
    add_executable(UITest ${UI_TEST_SOURCES} ${SOURCES})

endif()

if("${BUILD_PURPOSE}" MATCHES ".*Test")
    # Google Testライブラリのリンク
    target_link_libraries(UITest PRIVATE gtest gtest_main pthread ${CURSES_LIBRARIES})
    # テストファイルのためのインクルードディレクトリを追加
    target_link_libraries(UITest PRIVATE gtest gmock gtest_main gmock_main)
    target_compile_options(UITest PRIVATE -Wall -Wextra -Wpedantic)
endif()

message(STATUS "BUILD_PURPOSE=${BUILD_PURPOSE}")

if (SOURCES STREQUAL "")
    message(FATAL_ERROR "ソースファイルが見つかりません")
endif()


