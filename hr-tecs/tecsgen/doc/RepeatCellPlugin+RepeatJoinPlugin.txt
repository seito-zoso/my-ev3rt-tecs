【名前】RepeatCellPlugin --- セルを繰り返すセルプラグイン

【使用方法】

	[generate(RepeatCellPlugin,"count=5")]
	cell tCelltype Cell_000 {             --- (1)
		cCall  = Cell.eEntry;
		cCall2 = Cell_010.eEntry;         --- (2)
		cCall3 = CellA.eEntryArray[50];   --- (3)
		size   = SIZE_000;				  --- (4)
	};

【説明】

セルを count 個数繰り返します。
使用方法の (1), (2), (3) がカウントアップの対象となります。

(1) セル名の末尾は1桁以上の数字終わっている必要があります。末尾の数字
    はカウント番号に置き換えられます。数字はカウントアップされます。
(2) 右辺のセル名が1桁以上の数字で終わっている場合、数字はカウントアッ
    プされます。
(3) 右辺の受け口が配列の場合、添数はカウントアップされます。
(4) 右辺が単一の識別子で、末尾が1桁以上の数字で終わっている場合、数字
    はカウントアップされます。

【オプション】

    count=N   N:整数リテラル（1...n)
              または、単一の定数名

【制限】

・セルのアロケータ指定子や、結合の through 指定子などの指定子には対応しません。
・count の右辺は整数リテラルまたは単一の識別子（定数名）に限られます。

【補足説明】

RepeatCellPlugin により gen/tmp_RepeatCellPlugin_N.cdl (N:出現順) に繰
り返し生成されて、import されます。

=====

【名前】RepeatJoinPlugin --- セル内部の結合を繰り返すセルプラグイン

【使用方法】

	[generate(RepeatJoinPlugin,"count=5")]
	cell tCelltype Cell_000 {
		cCall[0] = Cell000.eEntry;   /* cCall[1] = Cell001.eEntry; ... */
		cCallX[0] = CellX.eEntry[0]; /* cCallX[1] = CellX.eEntry[1]; ... */
	};

【説明】

呼び口配列の添数が 0 となっている呼び口配列の結合を count 個数繰り返し
ます。添数が 0 以外の結合は、繰り返されません。
右辺のセルの名前が 1 個以上の 0 の繰り返しで終わっている場合、これをカウント番号に置き換えます。
右辺の受け口が配列になっていて、添数が 0 である場合、これをカウント番号に置き換えます。

【オプション】

    count=N   N:整数リテラル（1...n)
              または、単一の定数名

【制限】

・count の右辺は整数リテラルまたは単一の識別子（定数名）に限られます。

【補足説明】

RepeatJoinPlugin はファイルを生成しません。ジェネレータの既定動作とし
て gen/tmp_RepeatJoinPlugin_N.cdl ファイルを作成しますが、空になります。
上記の例では Cell_000 がジェネレータの内部にセルが生成された後で、その
セルに対して Join を追加するため、CDL ファイルを生成して import する方
法を用いることができません。

