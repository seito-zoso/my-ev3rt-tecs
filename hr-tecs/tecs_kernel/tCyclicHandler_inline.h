/*
 *  TOPPERS/HSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2008-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: tCyclicHandler_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eCyclic
 * entry port: eCyclic
 * signature:  sCyclic
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCyclic_start
 * name:         eCyclic_start
 * global_name:  tCyclicHandler_eCyclic_start
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eCyclic_start(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(sta_cyc(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eCyclic_stop
 * name:         eCyclic_stop
 * global_name:  tCyclicHandler_eCyclic_stop
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eCyclic_stop(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(stp_cyc(ATTR_id));
}
/* #[<ENTRY_FUNC>]# eCyclic_refer
 * name:         eCyclic_refer
 * global_name:  tCyclicHandler_eCyclic_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eCyclic_refer(CELLIDX idx, T_RCYC* pk_cyclicHandlerStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_cyc(ATTR_id, pk_cyclicHandlerStatus));
}

/* #[<ENTRY_PORT>]# eStartCyclic
 * entry port: eStartCyclic
 * signature:  sStartCyclic
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eStartCyclic_start
 * name:         eStartCyclic_start
 * global_name:  tCyclicHandler_eStartCyclic_start
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eStartCyclic_start(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(sta_cyc(ATTR_id));

	return(ercd);
}

/* #[<ENTRY_PORT>]# eStopCyclic
 * entry port: eStopCyclic
 * signature:  sStopCyclic
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eStopCyclic_stop
 * name:         eStopCyclic_stop
 * global_name:  tCyclicHandler_eStopCyclic_stop
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eStopCyclic_stop(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(stp_cyc(ATTR_id));

	return(ercd);
}

/* #[<ENTRY_PORT>]# eReferCyclic
 * entry port: eReferCyclic
 * signature:  sReferCyclic
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferCyclic_refer
 * name:         eReferCyclic_refer
 * global_name:  tCyclicHandler_eReferCyclic_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferCyclic_refer(CELLIDX idx, T_RCYC* pk_cyclicHandlerStatus)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	return(ref_cyc(ATTR_id, pk_cyclicHandlerStatus));

	return(ercd);
}

