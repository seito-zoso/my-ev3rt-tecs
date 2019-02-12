【名前】
  C2TECSBridgePlugin
    --- C 言語から TECS の受け口関数を直接呼び出すセルタイプを生成する
        シグニチャプラグイン

【使用方法】

  // signature sSignature, cell CellToBeCalledFromC は定義済みとします
    
  generate(C2TECSBridgePlugin, sSignature, "prefix='Sig'" );  // nC2TECS::tsSignature セルタイプを生成
  cell nC2TECS::tsSignature C2TECSBridge {                    // ブリッジセルを生成 (目的セルに結合)
     cCall = CellToBeCalledFromC.eEntry;
  };


【オプション】

  header_name=name 生成されるヘッダファイルの名前を name.h にします
  prefix=PREFIX    PREFIX を各関数名の前に付加します
  suffix=SUFFIX    SUFFIX を各関数名の後ろに付加します

【説明】

C 言語から直接呼び出せるようなブリッジセルタイプを生成します。ブリッジ
セルタイプはネームスペース nC2TECS の下に置かれます。

利用する C 言語では gen ディレクトリの下に生成される sSignature.h を
inlude するとシグニチャの関数を呼び出すことができます。
ヘッダ名は header オプションで変更できます。

TECS ジェネレータの実行に成功した場合でも、コンパイル時、リンク時に名
前衝突が発生する可能性があります。prefix または postfix オプションを指
定して、関数名をユニークなものにします。

C2TECSBridgePlugin では、別々にジェネレートされた cdl ファイルのコンポー
ネントを結合させるのに使用できます。この場合、両方の cdl ファイルで用
いられているセルタイプにかかわる .o (リロケータブルオブジェクト) を二
重にリンクしないように注意が必要です。

【関連】

TECS2CBridgePlugin
test/signatureBridge/generate.cdl

