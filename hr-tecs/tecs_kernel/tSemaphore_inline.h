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
 *  @(#) $Id: tSemaphore_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 */
/* 受け口関数 #_TEPF_# */
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
