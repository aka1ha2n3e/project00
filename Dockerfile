FROM ubuntu:20.04

WORKDIR /workspace

# -y 自動で承認するコマンド clean コンテナ内でインストール済みのアプリを削除
RUN apt install -y cmake git doxygen graphviz openjdk-11-jdk && apt clean