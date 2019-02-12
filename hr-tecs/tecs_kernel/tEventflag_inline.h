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
 *  @(#) $Id: tFixedSizeMemoryPool_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* 
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id
 */
/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eSetEventflag
 * entry port: eSetEventflag
 * signature:  sSetEventflag
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSetEventflag_set
 * name:         eSetEventflag_set
 * global_name:  tEventflag_eSetEventflag_set
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_set(CELLIDX idx, FLGPTN setPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(set_flg(ATTR_id, setPattern));
}

/* #[<ENTRY_FUNC>]# eSetEventflag_clear
 * name:         eSetEventflag_clear
 * global_name:  tEventflag_eSetEventflag_clear
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_clear(CELLIDX idx, FLGPTN clearPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(clr_flg(ATTR_id, clearPattern));
}

/* #[<ENTRY_PORT>]# eWaitEventflag
 * entry port: eWaitEventflag
 * signature:  sWaitEventflag
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eWaitEventflag_wait
 * name:         eWaitEventflag_wait
 * global_name:  tEventflag_eWaitEventflag_wait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_wait(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(wai_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern));
}

/* #[<ENTRY_FUNC>]# eWaitEventflag_waitPolling
 * name:         eWaitEventflag_waitPolling
 * global_name:  tEventflag_eWaitEventflag_waitPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_waitPolling(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(pol_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern));
}

/* #[<ENTRY_FUNC>]# eWaitEventflag_waitTimeout
 * name:         eWaitEventflag_waitTimeout
 * global_name:  tEventflag_eWaitEventflag_waitTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_waitTimeout(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(twai_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern, timeout));
}

/* #[<ENTRY_PORT>]# eManageEventflag
 * entry port: eManageEventflag
 * signature:  sManageEventflag
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManageEventflag_initialize
 * name:         eManageEventflag_initialize
 * global_name:  tEventflag_eManageEventflag_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_flg(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferEventflag
 * entry port: eReferEventflag
 * signature:  sReferEventflag
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferEventflag_refer
 * name:         eReferEventflag_refer
 * global_name:  tEventflag_eReferEventflag_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_refer(CELLIDX idx, T_RFLG* pk_eventflagStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_flg(ATTR_id, pk_eventflagStatus));
}
/* #[<ENTRY_PORT>]# eiEventflag
 * entry port: eiEventflag
 * signature:  siEventflag
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiEventflag_set
 * name:         eiEventflag_set
 * global_name:  tEventflag_eiEventflag_set
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiEventflag_set(CELLIDX idx, FLGPTN setPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iset_flg(ATTR_id, setPattern));
}

