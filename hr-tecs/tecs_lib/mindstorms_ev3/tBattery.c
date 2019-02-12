/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tBattery_template.c => src/tBattery.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tBattery_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBattery
 * entry port: eBattery
 * signature:  sBattery
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBattery_current_mA
 * name:         eBattery_current_mA
 * global_name:  tBattery_eBattery_current_mA
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int
eBattery_current_mA(CELLIDX idx)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	return ev3_battery_current_mA();
}

/* #[<ENTRY_FUNC>]# eBattery_voltage_mV
 * name:         eBattery_voltage_mV
 * global_name:  tBattery_eBattery_voltage_mV
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int
eBattery_voltage_mV(CELLIDX idx)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	return ev3_battery_voltage_mV();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
