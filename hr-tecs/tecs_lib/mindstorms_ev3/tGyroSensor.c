/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tGyroSensor_template.c => src/tGyroSensor.c
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
#include "tGyroSensor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eGyroSensor
 * entry port: eGyroSensor
 * signature:  sGyroSensor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eGyroSensor_getAngle
 * name:         eGyroSensor_getAngle
 * global_name:  tGyroSensor_eGyroSensor_getAngle
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int16_t
eGyroSensor_getAngle(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return  ev3_gyro_sensor_get_angle(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eGyroSensor_getRate
 * name:         eGyroSensor_getRate
 * global_name:  tGyroSensor_eGyroSensor_getRate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int16_t
eGyroSensor_getRate(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_gyro_sensor_get_rate(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eGyroSensor_reset
 * name:         eGyroSensor_reset
 * global_name:  tGyroSensor_eGyroSensor_reset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eGyroSensor_reset(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_gyro_sensor_reset(ATTR_port);
}
#include <t_syslog.h>
/* #[<ENTRY_FUNC>]# eGyroSensor_calibrate
 * name:         eGyroSensor_calibrate
 * global_name:  tGyroSensor_eGyroSensor_calibrate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
float32_t
eGyroSensor_calibrate(CELLIDX idx, int32_t times)
{
	CELLCB	*p_cellcb;
	int min = 1000, max = -100, sum = 0;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	for (int i = 0; i < times; ++i) {
		int gyro = ev3_gyro_sensor_get_rate(ATTR_port);
		sum += gyro;
		if (gyro > max)
		  max = gyro;
		if (gyro < min)
		  min = gyro;
		tslp_tsk(4);
	}
	syslog(LOG_EMERG,"max::%d, min::%d",max, min);
	if((max - min < 5)) { // TODO: recheck the condition, '!(max - min < 2)' or '(max - min < 2)'
		return sum / (float32_t)times;
	} else {
		return E_OBJ;
    }
}
/* #[<ENTRY_FUNC>]# eGyroSensor_initializePort
 * name:         eGyroSensor_initializePort
 * global_name:  tGyroSensor_eGyroSensor_initializePort
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eGyroSensor_initializePort(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	ev3_sensor_config(ATTR_port, GYRO_SENSOR);
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
