# 初めに
コマンドについて，特に記載がない場合はプロジェクトのルートを基底とする
# 担当
|               | aka | natsu | sere |
| ------------- | --- | --- | ---- |


# toto  
* [x] フォルダの生理
* [ ] テストの作成

# ツール
## 必要ツール
* cmake  
  ビルドツール

* googletest  
  テスター

* ~clang~  
~コンパイラ~

* LLVM  
コンパイラ

* vscode  
  * live share
  * WSL
 
* windows
  WLS 

## 推奨つーる
* doxygen  
ドキュメント生成ツール

* ~clang-format~  
~フォーマッター~

* ~clang-tidy~  
~規約チェック~

* Cursor
  AIと連携できるエディタ
   vscodeと同期可能
  > 変なコード生成するので要レビュー及び修正


# vscodeの設定
## 拡張機能の追加
1. vscodeでwsl(linuxのエミュレータ)のインストール
1. wlsの起動(コントロール+シフト+P)で表示されるガイドにそって起動
1. 拡張機能のインストール
>  * cmake
>  * live share
>  * cmake
>  * clang-format

## 設定ファイルの追加
1. 次のコマンドを実行1
~~~sh
mkdir .vscode
touch .vscode/settings.json .vscode/c_cpp_properties.json
~~~

## フォーマッタの使用
1. setting.jsonに次の内容を追加
~~~json
{
    "clang-format.executable": "/Program Files/LLVM/bin/clang-format.exe", #LLVMのインストール先
    "editor.formatOnSave": true,
    "backgroundCover.autoStatus": true,
}
~~~

## 保管機能の修正
1. c_cpp_properties.jsonに次の内容を追加
~~~json
{
    "configurations": [
        {
            "includePath": [
                "${workspaceFolder}/include"
            ],
            "compilerPath": "cl.exe", #もっと正しい方法があるはず．募集中
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
~~~

# buildについて
## コンパイル方法

~~~sh
mkdir {ビルド用ディレクトリ}
cd {ビルド用ディレクトリ}
cmake ..
make
~~~
もしくは

シェルに権限をあたえる．
~~~sh
chmod +x *.sh #権限を与える．二回目以降は不要
~~~

ビルド
~~~sh
./build.sh コンパイルするファイル名，拡張子不要(空欄だとsrc内のメイン.cpp)
~~~

リビルド．ビルドがうまくいかないとき．
~~~sh
./rebuild.sh コンパイルするファイル名，拡張子不要(空欄だとメイン.cpp)
~~~

コンパイルチェック．コンパイラー通るかさえ確認できればいい時に．
~~~sh
./compilecheck.sh
~~~

## 実行方法
~~~sh
cd build
./{実行ファイル}
~~~

## 静的検査
これはよくないよ，といった内容がtydycheck.txtに書いてあります．  
ファイルはシェルを使ったビルドの際，buildフォルダに生成されます．  

# directry
testフォルダにテスト関連のもの入れていってください。  
頭にCmakeと付いたテキストファイルで編集できます。  

# その他
