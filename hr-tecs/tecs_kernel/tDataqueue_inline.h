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
 *  @(#) $Id: tDataqueue_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 */
/* 受け口関数 #_TEPF_# */
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
