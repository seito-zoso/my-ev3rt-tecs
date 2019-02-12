/*
 *  TOPPERS/HSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2008-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: tAlarmHandler_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */
/*
 * id               ID               ATTR_id
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eAlarm
 * entry port: eAlarm
 * signature:  sAlarm
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAlarm_start
 * name:         eAlarm_start
 * global_name:  tAlarmHandler_eAlarm_start
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eAlarm_start(CELLIDX idx, RELTIM alarmTime)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(sta_alm(ATTR_id, alarmTime));
}

/* #[<ENTRY_FUNC>]# eAlarm_stop
 * name:         eAlarm_stop
 * global_name:  tAlarmHandler_eAlarm_stop
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eAlarm_stop(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(stp_alm(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eAlarm_refer
 * name:         eAlarm_refer
 * global_name:  tAlarmHandler_eAlarm_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eAlarm_refer(CELLIDX idx, T_RALM* pk_alarmStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_alm(ATTR_id, pk_alarmStatus));
}

/* #[<ENTRY_PORT>]# eStartAlarm
 * entry port: eStartAlarm
 * signature:  sStartAlarm
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eStartAlarm_start
 * name:         eStartAlarm_start
 * global_name:  tAlarmHandler_eStartAlarm_start
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eStartAlarm_start(CELLIDX idx, RELTIM alarmTime)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(sta_alm(ATTR_id, alarmTime));

	return(ercd);
}

/* #[<ENTRY_PORT>]# eStopAlarm
 * entry port: eStopAlarm
 * signature:  sStopAlarm
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eStopAlarm_stop
 * name:         eStopAlarm_stop
 * global_name:  tAlarmHandler_eStopAlarm_stop
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eStopAlarm_stop(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(stp_alm(ATTR_id));

	return(ercd);
}

/* #[<ENTRY_PORT>]# eReferAlarm
 * entry port: eReferAlarm
 * signature:  sReferAlarm
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferAlarm_refer
 * name:         eReferAlarm_refer
 * global_name:  tAlarmHandler_eReferAlarm_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferAlarm_refer(CELLIDX idx, T_RALM* pk_alarmStatus)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(ref_alm(ATTR_id, pk_alarmStatus));

	return(ercd);
}


/* #[<ENTRY_PORT>]# eiAlarm
 * entry port: eiAlarm
 * signature:  siAlarm
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiAlarm_start
 * name:         eiAlarm_start
 * global_name:  tAlarmHandler_eiAlarm_start
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiAlarm_start(CELLIDX idx, RELTIM alarmTime)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ista_alm(ATTR_id, alarmTime));
}

/* #[<ENTRY_FUNC>]# eiAlarm_stop
 * name:         eiAlarm_stop
 * global_name:  tAlarmHandler_eiAlarm_stop
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiAlarm_stop(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(istp_alm(ATTR_id));
}

