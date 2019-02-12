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
/* #[<ENTRY_PORT>]# eGetFixedSizeMemoryPool
 * entry port: eGetFixedSizeMemoryPool
 * signature:  sGetFixedSizeMemoryPool
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eGetFixedSizeMemoryPool_get
 * name:         eGetFixedSizeMemoryPool_get
 * global_name:  tFixedSizeMemoryPool_eGetFixedSizeMemoryPool_get
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eGetFixedSizeMemoryPool_get(CELLIDX idx, void** p_block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(get_mpf( ATTR_id, p_block));
}

/* #[<ENTRY_FUNC>]# eGetFixedSizeMemoryPool_getPolling
 * name:         eGetFixedSizeMemoryPool_getPolling
 * global_name:  tFixedSizeMemoryPool_eGetFixedSizeMemoryPool_getPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eGetFixedSizeMemoryPool_getPolling(CELLIDX idx, void** p_block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(pget_mpf(ATTR_id, p_block));
}

/* #[<ENTRY_FUNC>]# eGetFixedSizeMemoryPool_getTimeout
 * name:         eGetFixedSizeMemoryPool_getTimeout
 * global_name:  tFixedSizeMemoryPool_eGetFixedSizeMemoryPool_getTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eGetFixedSizeMemoryPool_getTimeout(CELLIDX idx, void** p_block, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tget_mpf(ATTR_id, p_block, timeout));
}

/* #[<ENTRY_PORT>]# eReleaseFixedSizeMemoryPool
 * entry port: eReleaseFixedSizeMemoryPool
 * signature:  sReleaseFixedSizeMemoryPool
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReleaseFixedSizeMemoryPool_release
 * name:         eReleaseFixedSizeMemoryPool_release
 * global_name:  tFixedSizeMemoryPool_eReleaseFixedSizeMemoryPool_release
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReleaseFixedSizeMemoryPool_release(CELLIDX idx, const void* block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rel_mpf(ATTR_id, (void *)block));
}

/* #[<ENTRY_PORT>]# eManageFixedSizeMemoryPool
 * entry port: eManageFixedSizeMemoryPool
 * signature:  sManageFixedSizeMemoryPool
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManageFixedSizeMemoryPool_initialize
 * name:         eManageFixedSizeMemoryPool_initialize
 * global_name:  tFixedSizeMemoryPool_eManageFixedSizeMemoryPool_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eManageFixedSizeMemoryPool_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_mpf(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferFixedSizeMemoryPool
 * entry port: eReferFixedSizeMemoryPool
 * signature:  sReferFixedSizeMemoryPool
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferFixedSizeMemoryPool_refer
 * name:         eReferFixedSizeMemoryPool_refer
 * global_name:  tFixedSizeMemoryPool_eReferFixedSizeMemoryPool_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferFixedSizeMemoryPool_refer(CELLIDX idx, T_RMPF* pk_memoryPoolFixedSizeStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_mpf(ATTR_id, pk_memoryPoolFixedSizeStatus));
}
