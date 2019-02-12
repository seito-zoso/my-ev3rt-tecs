/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tButton_template.c => src/tButton.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tButton_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eButton
 * entry port: eButton
 * signature:  sButton
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eButton_isPressed
 * name:         eButton_isPressed
 * global_name:  tButton_eButton_isPressed
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eButton_isPressed(CELLIDX idx, button_t button)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	return ev3_button_is_pressed(button);
}
/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
