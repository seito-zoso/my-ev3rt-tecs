# 「mruby on EV3RT + TECS」 rubyアプリケーションをLCD上に一覧表示させ選択実行。さらに、Bluetooth受信モードに切り替え可能。
---
「[mruby on EV3RT + TECS](https://www.toppers.jp/tecs.html)」で
- わざわざ何度もSDを抜き差ししなくても複数のrubyアプリケーションを実行したい。
- Bluetoothで飛んできたバイトコードは保存して次回以降も使用したい。

という要望があったので以下の３つのモードを持つアプリを作成しました。

1. [Run] SDに保存されたバイトコードをLCD上で選択し実行
1. [Delete] SDに保存されたバイトコードをLCD上で選択し削除
1. [Bluetooh] Bluetooth経由で飛んできたバイトコードを実行し、保存

以下に使い方をまとめます。

## ０．EV3RT+TECSのダウンロードや環境構築

このレポジトリのmasterブランチをGitクローンしてください。

    % git clone https://github.com/seito-zoso/my-ev3rt-tecs.git

初期環境構築等の方法については doc/mruby_on_ev3rt+tecs_build.pdf を参考にしてください。
（本家「mruby on EV3RT+TECS」はここからダウンロードできます[[ダウンロード](https://www.toppers.jp/tecs.html)]）

## １．前準備

### 1-1. アプリをEV3に取り込む。
cygwinで hr_tecs/workspace/menu+bluetooth ディレクトリに移動してください。そこで

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
hr_tecs/workspace/cp_mrb_app/ にrubyコードを作成し保存してください（作成しなくても最初からいくつかサンプルコードが用意されています）。
コメントアウト（＃）を用いてMakefileでアプリケーションの指定をしてください。rubyコードを自分で作成した場合はファイル名をここに追加します。（※ファイル名は拡張子を除いて８文字以内にしてください。）

    \#  mrubyのアプリケーションファイル名
    \# APP_NAME = battery.rb
    APP_NAME = button.rb
    \# APP_NAME = menu.rb
    \# APP_NAME = color.rb
    \# APP_NAME = color2.rb
    \# APP_NAME = color3.rb
    \# APP_NAME = ev3way.rb

Makefileの準備ができたら

    % make

バイトコード（.mrb）の作成とSDへのコピーが実行されます。ここでもSDの指定ディレクトリに注意してください。
その他にも実行したいアプリがあれば同様にしてSDにコピーしておいてください。


## ２．実行
まずはじめにEV3RTのメニュー画面が表示されるのでEnterを押してください。
各モードの切り替えはEV3の左右ボタンで行います。

![モード選択](https://github.com/seito-zoso/my-ev3rt-tecs/blob/images/1_mode.PNG)

### 2-1. Runモード
保存されたバイトコードを実行します。
hr_tecs/workspace/cp_mrb_app/での make によりSDに保存されたバイトコードがLCD上に一覧で表示されます。
上下ボタンで実行したいアプリを選択してください。

<img src="https://github.com/seito-zoso/my-ev3rt-tecs/blob/images/2_run.PNG" width=60%>

### 2-2. Deleteモード
保存されたバイトコードを削除します。
削除対象を選択し、確認画面でYesを押してください。

![Deleteモード](https://github.com/seito-zoso/my-ev3rt-tecs/blob/images/3_delete.PNG)

### 2-3．Bluetoothモード
Bluetooth 経由でバイトコードを受信します。
doc/mruby_on_ev3rt+tecs_build.pdf の手順に従ってEV3をPCに接続してからEnterを押下します。

<img src="https://github.com/seito-zoso/my-ev3rt-tecs/blob/images/4_bluetooth.PNG" width=60%>


TeraTermからバイトコードの転送を行えばアプリケーションの実行が可能です。
また転送されたバイトコードは「recv#.mrb」として保存され、再起動時LCD上で選択実行可能です。
（#には１から順に使用されていないファイル名の番号が入ります）

    　例：SDにrecv1、recv3が保存されている場合recv2が作成されます


![TeraTermでのバイトコード送信](https://github.com/seito-zoso/my-ev3rt-tecs/blob/images/5_teraterm.PNG)

<!-- ### Bluetoohにおいての注意
私の試した環境では、ファイル送信が成功するバイトコードとできないバイトコードがありました。
hr_tecs/workspace/mruby_app/led_sample.mrb であれば成功することを確認しています。 -->