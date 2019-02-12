/*
 *  TOPPERS/HSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2008-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: tSemaphore_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id         
 */
/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eSignalSemaphore
 * entry port: eSignalSemaphore
 * signature:  sSignalSemaphore
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSignalSemaphore_signal
 * name:         eSignalSemaphore_signal
 * global_name:  tSemaphore_eSignalSemaphore_signal
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_signal(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(sig_sem(ATTR_id));
}

/* #[<ENTRY_PORT>]# eWaitSemaphore
 * entry port: eWaitSemaphore
 * signature:  sWaitSemaphore
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eWaitSemaphore_wait
 * name:         eWaitSemaphore_wait
 * global_name:  tSemaphore_eWaitSemaphore_wait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_wait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(wai_sem(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eWaitSemaphore_waitPolling
 * name:         eWaitSemaphore_waitPolling
 * global_name:  tSemaphore_eWaitSemaphore_waitPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_waitPolling(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(pol_sem(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eWaitSemaphore_waitTimeout
 * name:         eWaitSemaphore_waitTimeout
 * global_name:  tSemaphore_eWaitSemaphore_waitTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_waitTimeout(CELLIDX idx, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(twai_sem(ATTR_id, timeout));
}

/* #[<ENTRY_PORT>]# eManageSemaphore
 * entry port: eManageSemaphore
 * signature:  sManageSemaphore
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManageSemaphore_initialize
 * name:         eManageSemaphore_initialize
 * global_name:  tSemaphore_eManageSemaphore_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_sem(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferSemaphore
 * entry port: eReferSemaphore
 * signature:  sReferSemaphore
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferSemaphore_refer
 * name:         eReferSemaphore_refer
 * global_name:  tSemaphore_eReferSemaphore_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSemaphore_refer(CELLIDX idx, T_RSEM* pk_semaphoreStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_sem(ATTR_id, pk_semaphoreStatus));
}

/* #[<ENTRY_PORT>]# eiSemaphore
 * entry port: eiSemaphore
 * signature:  siSemaphore
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiSemaphore_signal
 * name:         eiSemaphore_signal
 * global_name:  tSemaphore_eiSemaphore_signal
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiSemaphore_signal(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(isig_sem(ATTR_id));
}
