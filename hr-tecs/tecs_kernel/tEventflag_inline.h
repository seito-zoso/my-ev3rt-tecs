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
 *  @(#) $Id: tFixedSizeMemoryPool_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* 
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id
 */
/* 受け口関数 #_TEPF_# */
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

