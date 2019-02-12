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
 *  @(#) $Id: tTask_inline.h 428 2009-07-17 08:02:10Z ertl-takuya $
 */

#include "kernel.h"

/* 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTask
 * entry port: eTask
 * signature:  sTask
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTask_activate
 * name:         eTask_activate
 * global_name:  tTask_eTask_activate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_activate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(act_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_cancelActivate
 * name:         eTask_cancelActivate
 * global_name:  tTask_eTask_cancelActivate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER_UINT
eTask_cancelActivate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(can_act(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_terminate
 * name:         eTask_terminate
 * global_name:  tTask_eTask_terminate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_terminate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ter_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_changePriority
 * name:         eTask_changePriority
 * global_name:  tTask_eTask_changePriority
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_changePriority(CELLIDX idx, PRI priority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(chg_pri(ATTR_id, priority));
}

/* #[<ENTRY_FUNC>]# eTask_getPriority
 * name:         eTask_getPriority
 * global_name:  tTask_eTask_getPriority
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_getPriority(CELLIDX idx, PRI* p_priority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(get_pri(ATTR_id, p_priority));
}

/* #[<ENTRY_FUNC>]# eTask_refer
 * name:         eTask_refer
 * global_name:  tTask_eTask_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_refer(CELLIDX idx, T_RTSK* pk_taskStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_tsk(ATTR_id, pk_taskStatus));
}

/* #[<ENTRY_FUNC>]# eTask_wakeup
 * name:         eTask_wakeup
 * global_name:  tTask_eTask_wakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_wakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(wup_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_cancelWakeup
 * name:         eTask_cancelWakeup
 * global_name:  tTask_eTask_cancelWakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER_UINT
eTask_cancelWakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(can_wup(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_releaseWait
 * name:         eTask_releaseWait
 * global_name:  tTask_eTask_releaseWait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_releaseWait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rel_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_suspend
 * name:         eTask_suspend
 * global_name:  tTask_eTask_suspend
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_suspend(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(sus_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_resume
 * name:         eTask_resume
 * global_name:  tTask_eTask_resume
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_resume(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rsm_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_raiseException
 * name:         eTask_raiseException
 * global_name:  tTask_eTask_raiseException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_raiseException(CELLIDX idx, TEXPTN pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ras_tex(ATTR_id, pattern));
}

/* #[<ENTRY_PORT>]# eActivateTask
 * entry port: eActivateTask
 * signature:  sActivateTask
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eActivateTask_activate
 * name:         eActivateTask_activate
 * global_name:  tTask_eActivateTask_activate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eActivateTask_activate(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(act_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eActivateTask_cancelActivate
 * name:         eActivateTask_cancelActivate
 * global_name:  tTask_eActivateTask_cancelActivate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER_UINT
eActivateTask_cancelActivate(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(can_act(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eActivateTask_wakeup
 * name:         eActivateTask_wakeup
 * global_name:  tTask_eActivateTask_wakeup
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eActivateTask_wakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(wup_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eActivateTask_cancelWakeup
 * name:         eActivateTask_cancelWakeup
 * global_name:  tTask_eActivateTask_cancelWakeup
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER_UINT
eActivateTask_cancelWakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(can_wup(ATTR_id));
}

/* #[<ENTRY_PORT>]# eControlTask
 * entry port: eControlTask
 * signature:  sControlTask
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eControlTask_terminate
 * name:         eControlTask_terminate
 * global_name:  tTask_eControlTask_terminate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_terminate(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ter_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eControlTask_changePriority
 * name:         eControlTask_changePriority
 * global_name:  tTask_eControlTask_changePriority
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_changePriority(CELLIDX idx, PRI priority)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(chg_pri(ATTR_id, priority));
}

/* #[<ENTRY_FUNC>]# eControlTask_releaseWait
 * name:         eControlTask_releaseWait
 * global_name:  tTask_eControlTask_releaseWait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_releaseWait(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(rel_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eControlTask_suspend
 * name:         eControlTask_suspend
 * global_name:  tTask_eControlTask_suspend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_suspend(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(sus_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eControlTask_resume
 * name:         eControlTask_resume
 * global_name:  tTask_eControlTask_resume
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_resume(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(rsm_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eControlTask_raiseException
 * name:         eControlTask_raiseException
 * global_name:  tTask_eControlTask_raiseException
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_raiseException(CELLIDX idx, TEXPTN pattern)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ras_tex(ATTR_id, pattern));
}

/* #[<ENTRY_FUNC>]# eControlTask_disableWait
 * name:         eControlTask_disableWait
 * global_name:  tTask_eControlTask_disableWait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_disableWait(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(dis_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eControlTask_enableWait
 * name:         eControlTask_enableWait
 * global_name:  tTask_eControlTask_enableWait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eControlTask_enableWait(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ena_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_startOverRunHandler
 * name:         eTask_startOverRunHandler
 * global_name:  tTask_eTask_startOverRunHandler
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_startOverRunHandler(CELLIDX idx, OVRTIM ovrtim)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(sta_ovr(ATTR_id, ovrtim));
}

/* #[<ENTRY_FUNC>]# eTask_stopOverRunHandler
 * name:         eTask_stopOverRunHandler
 * global_name:  tTask_eTask_stopOverRunHandler
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_stopOverRunHandler(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(stp_ovr(ATTR_id));
}

/* #[<ENTRY_PORT>]# eReferTask
 * entry port: eReferTask
 * signature:  sReferTask
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferTask_getPriority
 * name:         eReferTask_getPriority
 * global_name:  tTask_eReferTask_getPriority
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferTask_getPriority(CELLIDX idx, PRI* p_priority)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(get_pri(ATTR_id, p_priority));
}

/* #[<ENTRY_FUNC>]# eReferTask_refer
 * name:         eReferTask_refer
 * global_name:  tTask_eReferTask_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eReferTask_refer(CELLIDX idx, T_RTSK* pk_taskStatus)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ref_tsk(ATTR_id, pk_taskStatus));
}

/* #[<ENTRY_FUNC>]# eTask_referException
 * name:         eTask_referException
 * global_name:  tTask_eTask_referException
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_referException(CELLIDX idx, T_RTEX* pk_rtex)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ref_tex(ATTR_id, pk_rtex));
}

/* #[<ENTRY_FUNC>]# eTask_referOverRunHandler
 * name:         eTask_referOverRunHandler
 * global_name:  tTask_eTask_referOverRunHandler
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_referOverRunHandler(CELLIDX idx, T_ROVR* pk_rovr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ref_ovr(ATTR_id, pk_rovr));
}

/* #[<ENTRY_PORT>]# eiTask
 * entry port: eiTask
 * signature:  siTask
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiTask_activate
 * name:         eiTask_activate
 * global_name:  tTask_eiTask_activate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_activate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iact_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_wakeup
 * name:         eiTask_wakeup
 * global_name:  tTask_eiTask_wakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_wakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb= GET_CELLCB(idx);
	return(iwup_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_releaseWait
 * name:         eiTask_releaseWait
 * global_name:  tTask_eiTask_releaseWait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_releaseWait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(irel_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_raiseException
 * name:         eiTask_raiseException
 * global_name:  tTask_eiTask_raiseException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_raiseException(CELLIDX idx, TEXPTN pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iras_tex(ATTR_id, pattern));
}

/* #[<ENTRY_FUNC>]# eiTask_disableWait
 * name:         eiTask_disableWait
 * global_name:  tTask_eiTask_disableWait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiTask_disableWait(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(idis_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_enableWait
 * name:         eiTask_enableWait
 * global_name:  tTask_eiTask_enableWait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiTask_enableWait(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(iena_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_startOverRunHandler
 * name:         eiTask_startOverRunHandler
 * global_name:  tTask_eiTask_startOverRunHandler
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiTask_startOverRunHandler(CELLIDX idx, OVRTIM ovrtim)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(ista_ovr(ATTR_id, ovrtim));
}

/* #[<ENTRY_FUNC>]# eiTask_stopOverRunHandler
 * name:         eiTask_stopOverRunHandler
 * global_name:  tTask_eiTask_stopOverRunHandler
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiTask_stopOverRunHandler(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return(istp_ovr(ATTR_id));
}

