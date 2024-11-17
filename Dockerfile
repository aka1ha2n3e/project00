FROM ubuntu:20.04

WORKDIR /workspace

ENV TZ=Asia/Tokyo

# シンボリックリンクを作成 -s シンボリックリンク -f 既存のシンボリックリンクを削除 -n リンク先を参照しない 
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime 
RUN apt update 
# -y 自動で承認するコマンド clean コンテナ内でインストール済みのアプリを削除
RUN apt install -y cmake git doxygen graphviz openjdk-11-jdk && apt clean