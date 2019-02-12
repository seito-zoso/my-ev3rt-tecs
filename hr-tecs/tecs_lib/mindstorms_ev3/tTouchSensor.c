/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTouchSensor_template.c => src/tTouchSensor.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * port             int32_t          ATTR_port
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTouchSensor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTouchSensor
 * entry port: eTouchSensor
 * signature:  sTouchSensor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTouchSensor_isPressed
 * name:         eTouchSensor_isPressed
 * global_name:  tTouchSensor_eTouchSensor_isPressed
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eTouchSensor_isPressed(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_touch_sensor_is_pressed(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eTouchSensor_initializePort
 * name:         eTouchSensor_initializePort
 * global_name:  tTouchSensor_eTouchSensor_initializePort
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTouchSensor_initializePort(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	ev3_sensor_config(ATTR_port, TOUCH_SENSOR);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
