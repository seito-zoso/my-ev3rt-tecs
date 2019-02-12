/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tMotor_template.c => src/tMotor.c
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
#include "tMotor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eMotor
 * entry port: eMotor
 * signature:  sMotor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMotor_getType
 * name:         eMotor_getType
 * global_name:  tMotor_eMotor_getType
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eMotor_getType(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_get_type(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eMotor_getCounts
 * name:         eMotor_getCounts
 * global_name:  tMotor_eMotor_getCounts
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eMotor_getCounts(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_get_counts(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eMotor_getPower
 * name:         eMotor_getPower
 * global_name:  tMotor_eMotor_getPower
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int
eMotor_getPower(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_get_power(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eMotor_resetCounts
 * name:         eMotor_resetCounts
 * global_name:  tMotor_eMotor_resetCounts
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMotor_resetCounts(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_reset_counts(ATTR_port);
}

/* #[<ENTRY_FUNC>]# eMotor_setPower
 * name:         eMotor_setPower
 * global_name:  tMotor_eMotor_setPower
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMotor_setPower(CELLIDX idx, int power)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_set_power(ATTR_port, power);
}

/* #[<ENTRY_FUNC>]# eMotor_stop
 * name:         eMotor_stop
 * global_name:  tMotor_eMotor_stop
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMotor_stop(CELLIDX idx, bool_t brake)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_stop(ATTR_port, brake);
}

/* #[<ENTRY_FUNC>]# eMotor_rotate
 * name:         eMotor_rotate
 * global_name:  tMotor_eMotor_rotate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMotor_rotate(CELLIDX idx, int degrees, uint32_t speed_abs, bool_t blocking)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	return ev3_motor_rotate(ATTR_port, degrees, speed_abs, blocking);
}

/* #[<ENTRY_FUNC>]# eMotor_initializePort
 * name:         eMotor_initializePort
 * global_name:  tMotor_eMotor_initializePort
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMotor_initializePort(CELLIDX idx, int32_t type)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	ev3_motor_config(ATTR_port, type);
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
