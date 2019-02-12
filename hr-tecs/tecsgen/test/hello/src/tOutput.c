/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/_template.c => src/.c
 * のように名前, フォルダを変更してから修正します
 *
 * #[</PREAMBLE>]# */

#include "tOutput_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* <<< */
/* このファイルは gen/tOutput_templ.c を src/tOutput.c に移して使用します */
/* <<< */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# ePrint
 * entry port: ePrint
 * signature:  sPrint
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# ePrint_print
 * name:         ePrint_print
 * global_name:  tOutput_ePrint_print
 * #[/ENTRY_FUNC>]# */
void
ePrint_print(CELLIDX idx, const char_t* str)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	printf( str );      /* <<< 追記 */
}

