/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tColorSensor_template.c => src/tColorSensor.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * port             int32_t          ATTR_port       
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tColorSensor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
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
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
 