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
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: tPriorityDataqueue_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id
 */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSendPriorityDataqueue
 * entry port: eSendPriorityDataqueue
 * signature:  sSendPriorityDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSendPriorityDataqueue_send
 * name:         eSendPriorityDataqueue_send
 * global_name:  tPriorityDataqueue_eSendPriorityDataqueue_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendPriorityDataqueue_send(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(snd_pdq(ATTR_id, data, dataPriority));
}

/* #[<ENTRY_FUNC>]# eSendPriorityDataqueue_sendPolling
 * name:         eSendPriorityDataqueue_sendPolling
 * global_name:  tPriorityDataqueue_eSendPriorityDataqueue_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendPriorityDataqueue_sendPolling(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_pdq(ATTR_id, data, dataPriority));
}

/* #[<ENTRY_FUNC>]# eSendPriorityDataqueue_sendTimeout
 * name:         eSendPriorityDataqueue_sendTimeout
 * global_name:  tPriorityDataqueue_eSendPriorityDataqueue_sendTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eSendPriorityDataqueue_sendTimeout(CELLIDX idx, intptr_t data, PRI dataPriority, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tsnd_pdq(ATTR_id, data, dataPriority, timeout));
}

/* #[<ENTRY_PORT>]# eReceivePriorityDataqueue
 * entry port: eReceivePriorityDataqueue
 * signature:  sReceivePriorityDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReceivePriorityDataqueue_receive
 * name:         eReceivePriorityDataqueue_receive
 * global_name:  tPriorityDataqueue_eReceivePriorityDataqueue_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceivePriorityDataqueue_receive(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rcv_pdq(ATTR_id, p_data, p_dataPriority));
}

/* #[<ENTRY_FUNC>]# eReceivePriorityDataqueue_receivePolling
 * name:         eReceivePriorityDataqueue_receivePolling
 * global_name:  tPriorityDataqueue_eReceivePriorityDataqueue_receivePolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceivePriorityDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(prcv_pdq(ATTR_id, p_data, p_dataPriority));
}

/* #[<ENTRY_FUNC>]# eReceivePriorityDataqueue_receiveTimeout
 * name:         eReceivePriorityDataqueue_receiveTimeout
 * global_name:  tPriorityDataqueue_eReceivePriorityDataqueue_receiveTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReceivePriorityDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(trcv_pdq(ATTR_id, p_data, p_dataPriority, timeout));
}

/* #[<ENTRY_PORT>]# eManagePriorityDataqueue
 * entry port: eManagePriorityDataqueue
 * signature:  sManagePriorityDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManagePriorityDataqueue_initialize
 * name:         eManagePriorityDataqueue_initialize
 * global_name:  tPriorityDataqueue_eManagePriorityDataqueue_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eManagePriorityDataqueue_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_pdq(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferPriorityDataqueue
 * entry port: eReferPriorityDataqueue
 * signature:  sReferPriorityDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferPriorityDataqueue_refer
 * name:         eReferPriorityDataqueue_refer
 * global_name:  tPriorityDataqueue_eReferPriorityDataqueue_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferPriorityDataqueue_refer(CELLIDX idx, T_RPDQ* pk_priorityDataqueueStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_pdq(ATTR_id, pk_priorityDataqueueStatus));
}

/* #[<ENTRY_PORT>]# eiPriorityDataqueue
 * entry port: eiPriorityDataqueue
 * signature:  siPriorityDataqueue
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiPriorityDataqueue_sendPolling
 * name:         eiPriorityDataqueue_sendPolling
 * global_name:  tPriorityDataqueue_eiPriorityDataqueue_sendPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiPriorityDataqueue_sendPolling(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ipsnd_pdq(ATTR_id, data, dataPriority));
}

