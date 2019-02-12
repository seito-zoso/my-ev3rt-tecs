/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tLED_template.c => src/tLED.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tLED_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eLED
 * entry port: eLED
 * signature:  sLED
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLED_setColor
 * name:         eLED_setColor
 * global_name:  tLED_eLED_setColor
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLED_setColor(CELLIDX idx, ledcolor_t color)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	return ev3_led_set_color(color);
}

/* #[<ENTRY_FUNC>]# eLED_off
 * name:         eLED_off
 * global_name:  tLED_eLED_off
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLED_off(CELLIDX idx)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	return ev3_led_set_color(LED_OFF);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
