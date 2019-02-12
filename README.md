# 「mruby on EV3RT + TECS」 作成したrubyアプリケーションをLCD上に一覧表示させ実行する。さらに、メニューからBluetoothモードの選択も可能に。
---
「[mruby on EV3RT + TECS](http://dev.toppers.jp/trac_user/contrib/wiki/tecs)」で
1. 作成したrubyアプリケーションをSDに保存することで、EV3のLCD上に一覧表示させ選択実行ができる
1. さらにメニューからBluetoothの受信モードを選べばBluetoothで飛んできたバイトコードの実行・保存ができる

というものを作成しましたので、ここに使い方をまとめます。

## ０．EV3RT+TECSのダウンロードや環境構築
「mruby on EV3RT+TECS」はここからダウンロードできます[[ダウンロード](http://dev.toppers.jp/trac_user/contrib/wiki/tecs)]。
また初期環境構築等の方法についてはダウンロードしたファイルの doc/mruby_on_ev3rt+tecs_build.pdf を参考にしてください。


## １．LCD上でアプリケーションを選択実行する

### 1-1. 選択実行するためのアプリをEV3に取り込む。
cygwinで hr_tecs/workspace/menu+BT ディレクトリに移動してください。そこで

  % make tecs

と打ち込んでください。GNU Makeがtecsgenを実行し、TECSコンポーネント記述言語（CDLファイル）に基づいたインターフェースコードなどを作成してくれます。
次に

  % make

でアプリケーションを選択実行するためのアプリがSDカードに取り込まれます。
エラーとなる場合はSDの指定ディレクトリが間違っている可能性があります。hr_tecs/workspace/menu+BT/Makefileにおいて以下の「e」の部分を自身のSDのドライブ名に変更してください。

  # SDのドライブ文字を指定
  SD_DIR = /cygdrive/e

### 1-2. mrubyバイトコード（.mrb）をSDに保存する
次にrubyコードをSDに保存する方法を紹介します。
作成したrubyコードを hr_tecs/workspace/cp_mrb_app/ に保存してください（作成しなくても最初からいくつかサンプルコードが用意されています）。
Makefileでコメントアウト（＃）を用いてアプリケーションの指定をしてください。rubyコードを自分で作成した場合はそのファイル名をここに追加します。（※ファイル名は拡張子を除いて８文字以内にしてください。）

  #  mrubyのアプリケーションファイル名
  # APP_NAME = battery.rb
  APP_NAME = button.rb
  # APP_NAME = menu.rb
  # APP_NAME = color.rb
  # APP_NAME = color2.rb
  # APP_NAME = color3.rb
  # APP_NAME = ev3way.rb

Makefileの準備ができたら

  % make

でバイトコード（.mrb）の作成とSDへのコピーが実行されます。ここでもSDの指定ディレクトリに注意してください。
その他にも実行したいアプリがあれば同様にしてSDにコピーしておいてください。

### 1-3. EV3上でアプリケーションを選択実行する
SDカードをEV3に差し込んでください。
先ほどSDにコピーしたバイトコードがLCD上に一覧表示されています。
上下ボタンで選択、Enterボタンで実行することができます。
**TODO**
画像
UseCaseの追加

## ２．Bluetoothモードについて
hr_tecs/workspace/cp_mrb_app/ にてアプリケーションの指定を「bluetooth.rb」にし make します。
SDカードをEV3に差し込み、表示されたLCDの一覧から「bluetooth.mrb」を選択すれば Bluetooth での受信モードとなります。
doc/mruby_on_ev3rt+tecs_build.pdf の手順に従って「PCとのペアリング」、「TeraTermからバイトコードの転送」を行えばアプリケーションの実行が可能です。
また転送されたバイトコードは「receive.mrb」として保存され、再起動時LCD上で選択実行可能です。
