/*
 *  TOPPERS/HSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2008-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2012 by Ubiquitous Computing and Networking Laboratory
 *                Ritsumeikan Univ., JAPAN
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
 *  @(#) $Id: tDataqueue_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id         
 */
/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eSendDataqueue
 * entry port: eSendDataqueue
 * signature:  sSendDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSendDataqueue_send
 * name:         eSendDataqueue_send
 * global_name:  tDataqueue_eSendDataqueue_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendDataqueue_send(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(snd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eSendDataqueue_sendPolling
 * name:         eSendDataqueue_sendPolling
 * global_name:  tDataqueue_eSendDataqueue_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eSendDataqueue_sendTimeout
 * name:         eSendDataqueue_sendTimeout
 * global_name:  tDataqueue_eSendDataqueue_sendTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendDataqueue_sendTimeout(CELLIDX idx, intptr_t data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tsnd_dtq(ATTR_id, data, timeout));
}

/* #[<ENTRY_FUNC>]# eSendDataqueue_sendForce
 * name:         eSendDataqueue_sendForce
 * global_name:  tDataqueue_eSendDataqueue_sendForce
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(fsnd_dtq(ATTR_id, data));
}

/* #[<ENTRY_PORT>]# eReceiveDataqueue
 * entry port: eReceiveDataqueue
 * signature:  sReceiveDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReceiveDataqueue_receive
 * name:         eReceiveDataqueue_receive
 * global_name:  tDataqueue_eReceiveDataqueue_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceiveDataqueue_receive(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rcv_dtq(ATTR_id, p_data));
}

/* #[<ENTRY_FUNC>]# eReceiveDataqueue_receivePolling
 * name:         eReceiveDataqueue_receivePolling
 * global_name:  tDataqueue_eReceiveDataqueue_receivePolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceiveDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(prcv_dtq(ATTR_id, p_data));
}

/* #[<ENTRY_FUNC>]# eReceiveDataqueue_receiveTimeout
 * name:         eReceiveDataqueue_receiveTimeout
 * global_name:  tDataqueue_eReceiveDataqueue_receiveTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceiveDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(trcv_dtq(ATTR_id, p_data, timeout));
}

/* #[<ENTRY_PORT>]# eManageDataqueue
 * entry port: eManageDataqueue
 * signature:  sManageDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManageDataqueue_initialize
 * name:         eManageDataqueue_initialize
 * global_name:  tDataqueue_eManageDataqueue_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eManageDataqueue_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_dtq(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferDataqueue
 * entry port: eReferDataqueue
 * signature:  sReferDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferDataqueue_refer
 * name:         eReferDataqueue_refer
 * global_name:  tDataqueue_eReferDataqueue_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferDataqueue_refer(CELLIDX idx, T_RDTQ* pk_dataqueueStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_dtq(ATTR_id, pk_dataqueueStatus));
}

/* #[<ENTRY_PORT>]# eiDataqueue
 * entry port: eiDataqueue
 * signature:  siDataqueue
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiDataqueue_sendPolling
 * name:         eiDataqueue_sendPolling
 * global_name:  tDataqueue_eiDataqueue_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ipsnd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eiDataqueue_sendForce
 * name:         eiDataqueue_sendForce
 * global_name:  tDataqueue_eiDataqueue_sendForce
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ifsnd_dtq(ATTR_id,  data));
}
