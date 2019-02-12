/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tColorSensor_template.c => src/tColorSensor.c
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
#include "tColorSensor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eColorSensor
 * entry port: eColorSensor
 * signature:  sColorSensor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eColorSensor_getColor
 * name:         eColorSensor_getColor
 * global_name:  tColorSensor_eColorSensor_getColor
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
colorid_t
eColorSensor_getColor(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_color_sensor_get_color(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eColorSensor_getReflect
 * name:         eColorSensor_getReflect
 * global_name:  tColorSensor_eColorSensor_getReflect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint8_t
eColorSensor_getReflect(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_color_sensor_get_reflect(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eColorSensor_getAmbient
 * name:         eColorSensor_getAmbient
 * global_name:  tColorSensor_eColorSensor_getAmbient
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint8_t
eColorSensor_getAmbient(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_color_sensor_get_ambient(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eColorSensor_initializePort
 * name:         eColorSensor_initializePort
 * global_name:  tColorSensor_eColorSensor_initializePort
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eColorSensor_initializePort(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	ev3_sensor_config(ATTR_port, COLOR_SENSOR);
}

/* #[<ENTRY_FUNC>]# eColorSensor_getRGBRaw
 * name:         eColorSensor_getRGBRaw
 * global_name:  tColorSensor_eColorSensor_getRGBRaw
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eColorSensor_getRGBRaw(CELLIDX idx, uint16_t* r, uint16_t* g, uint16_t* b)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	rgb_raw_t val;
	ev3_color_sensor_get_rgb_raw(ATTR_port, &val);

	(*r) = val.r; (*g) = val.g; (*b) = val.b;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
 