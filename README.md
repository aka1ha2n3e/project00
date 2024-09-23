# ツール
## 必要ツール
* cmake  
  ビルドツール

* googletest  
  テスター

* clang  
コンパイラ

* vscode
  * live share

## 推奨つーる
* doxygen  
ドキュメント生成ツール

* clang-format  
フォーマッター

* clang-tidy  
規約チェック

* Cursor
  AIと連携できるエディタ
   vscodeと同期可能
  > 変なコード生成するので要レビュー及び修正


# buildについて
## コンパイル方法
プロジェクトのルート

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
./build.sh
~~~

リビルド．ビルドがうまくいかないとき．
~~~sh
./rebuild.sh
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

# directry
testフォルダにテスト関連のもの入れていってください。  
頭にCmakeと付いたテキストファイルで編集できます。  

# toto  
* [ ] フォルダの生理
* [ ] テストの作成

# その他
