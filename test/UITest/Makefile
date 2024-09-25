# Makefile for UI test

# コンパイラ設定
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I../../include

# ライブラリ設定
LIBS = -lncurses

# ソースファイル
SOURCES = ../UItest.cpp ../../src/UI.cpp

# オブジェクトファイル
OBJECTS = $(notdir $(SOURCES:.cpp=.o))

# 実行ファイル名
TARGET = UItest

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルの生成
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# オブジェクトファイルの生成
%.o: ../%.cpp
	$(CXX) $(CXXFLAGS) -c $<

%.o: ../../src/%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# テストの実行
run: $(TARGET)
	./$(TARGET)

# クリーンアップ
clean:
	rm -f $(OBJECTS) $(TARGET)

# ヘッダファイルの依存関係
UItest.o: ../../include/UI.hpp
UI.o: ../../include/UI.hpp

.PHONY: all run clean