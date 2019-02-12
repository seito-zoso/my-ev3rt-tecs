SimpleSample
						2009.6.7 初版
						2009.6.9 再アップ

《超簡易パッケージの概要》

「3 分でわかる TECS」ということで、cygwin だけで動作する SimpleSample 
を作ってみました。TECS コンポーネントの要素を理解することができます。

  公式リリースのパッケージに入っているものは TOPPERS/ASP カーネル上で
  動かすサンプルで、skyeye のシミュレーション環境により PC 上で動作さ
  せることができる本格的なものです。ちょっと動かしてみるには、ややハー
  ドルが高いかもしれません。

この超簡易パッケージは cygwin のネイティブな gcc でビルドするようにし
ていますので、cygwin がインストールされていれば、他には特に必要ありま
せん。ruby, racc もインストールの必要ありません。

ビルドの仕方：

  % make tecs
  % make all

  場合によっては、make tecs の前に、以下のようにパスを入れる必要がある
  かもしれません。

  % PATH=.:$PATH

実行の仕方：

  % ./SimpleSample.exe

《SimpleSample の概要》

hello の表示など、ごく簡単な例です。
TECS の本来機能を理解しやすいように、cygwin だけで動作します。
この例では、簡単のために printf を呼び出しますが、実際の RTOS 環境であ
れば、出力用コンポーネントを用いた方がよいです。

コンポーネント図：

  SimpleSample.png

コンポーネント記述：

SimpleSmaple.cdl に TECS CDL で記述。文字コードには EUC を使用していま
す。

・シグニチャ記述

  sSample … 関数インタフェースの定義
             慣習として接頭文字 s を付加する

シグニチャ sSampleには 2 つの関数 sayHello と howAreYou がある。
セルタイプ tSample の提供する機能となるので、sSample という名前にした。

・セルタイプ記述

  tSimple … 呼び元のセルタイプ
  tSample … 呼び先のセルタイプ
             慣習として接頭文字 t を付加する

・組上げ記述

  Simple … 呼び元のセル
  Sample … 呼び先のセル

セルタイプコード：

  src/tSimple.c  … 呼び元のセルタイプコード
  src/tSample.c  … 呼び先のセルタイプコード

【作成環境】

 OS: Windows XP SP3
 Ruby: V1.8.7p72 (mswin32)
 Racc: 1.4.5
 exerb: 4.8.0

《ライセンス》

【TECSジェネレータ】

TECS ジェネレータ tecsgen.exe の内部に含まれるコードについては TOPPERS 
ライセンスに従います。TOPPERS ライセンスについては以下のホームページで
確認できます。

  http://www.toppers.jp/license.html

【Ruby関係】

tecsgen.exe は Ruby, Racc, Exerb を使用して構築されています。
それらについては、それらのライセンスに従います。

Ruby のインタプリタのソースは、以下の URL のホームページからダウンロー
ドできます。

  http://www.ruby-lang.org/

Racc のソースは、以下の URL のホームページからダウンロードできます。

  http://i.loveruby.net/ja/projects/racc/

Exerb のソースは以下の URL のホームページからダウンロードできます。

  http://exerb.sourceforge.jp/
