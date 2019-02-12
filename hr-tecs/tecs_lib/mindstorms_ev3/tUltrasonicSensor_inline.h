/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUltrasonicSensor_inline_template.h => src/tUltrasonicSensor_inline.h
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

#include "ev3api.h"

#include <t_stddef.h>
#include <t_syslog.h>
#include <string.h>
#include "platform_interface_layer.h"
#include "api_common.h"

/**
 * Check whether a port number is valid
 */
#define CHECK_PORT(port) CHECK_COND((port) >= EV3_PORT_1 && (port) <= EV3_PORT_4, E_ID)


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eUltrasonicSensor
 * entry port: eUltrasonicSensor
 * signature:  sUltrasonicSensor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eUltrasonicSensor_getDistance
 * name:         eUltrasonicSensor_getDistance
 * global_name:  tUltrasonicSensor_eUltrasonicSensor_getDistance
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline int16_t
eUltrasonicSensor_getDistance(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_ultrasonic_sensor_get_distance(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eUltrasonicSensor_initializePort
 * name:         eUltrasonicSensor_initializePort
 * global_name:  tUltrasonicSensor_eUltrasonicSensor_initializePort
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eUltrasonicSensor_initializePort(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	ev3_sensor_config(ATTR_port, ULTRASONIC_SENSOR);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
