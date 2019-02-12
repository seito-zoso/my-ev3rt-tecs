/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: tSemaphore_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 */

/*
 * #include "tSemaphore_tecsgen.h"
 */
#include <unistd.h>
#include "errno.h"
#include "tecs_pthread_adaptor.h"

Inline ER Semaphore_errno_conv( int err_no )
{
	ER  err;

	switch(err_no){
	case 0:
		err = E_OK;
		break;
	case EINVAL:
		err = E_ID;
		break;
	case EBUSY:
		err = E_TMOUT;
		break;
	case EDEADLK:
		err = E_RLWAI;
		break;
//	case EPERM:
//		err = E_;  // 他のスレッドが解放しようとした場合が想定されていない（起こらないし）
//		break;
	default:
		err = E_CTX;  // よくわからないものは、とりあえずコンテキストエラー
	}
	return err;		
}

Inline void Semapore_once(void)
{
}


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSemaphore
 * entry port: eSemaphore
 * signature:  sSemaphore
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSemaphore_signal
 * name:         eSemaphore_signal
 * global_name:  tSemaphore_eSemaphore_signal
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_signal(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(sig_sem(ATTR_id));
	return(Semaphore_errno_conv(pthread_mutex_unlock(&VAR_mutex)));
}

/* #[<ENTRY_FUNC>]# eSemaphore_wait
 * name:         eSemaphore_wait
 * global_name:  tSemaphore_eSemaphore_wait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_wait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(wai_sem(ATTR_id));
	return(Semaphore_errno_conv(pthread_mutex_lock(&VAR_mutex)));
}

/* #[<ENTRY_FUNC>]# eSemaphore_waitPolling
 * name:         eSemaphore_waitPolling
 * global_name:  tSemaphore_eSemaphore_waitPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_waitPolling(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	errno=pthread_mutex_trylock(&VAR_mutex);
	return(Semaphore_errno_conv(errno));
}

/* #[<ENTRY_FUNC>]# eSemaphore_waitTimeout
 * name:         eSemaphore_waitTimeout
 * global_name:  tSemaphore_eSemaphore_waitTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_waitTimeout(CELLIDX idx, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	int     errno;

//	return(twai_sem(ATTR_id, timeout));
	while((errno=pthread_mutex_trylock(&VAR_mutex))==EBUSY)
		usleep(1000);
	return(Semaphore_errno_conv(errno));
}

/* #[<ENTRY_FUNC>]# eSemaphore_initialize
 * name:         eSemaphore_initialize
 * global_name:  tSemaphore_eSemaphore_initialize
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_sem(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eSemaphore_refer
 * name:         eSemaphore_refer
 * global_name:  tSemaphore_eSemaphore_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eSemaphore_refer(CELLIDX idx, T_RSEM* pk_semaphore_status)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_sem(ATTR_id, pk_semaphore_status));
}

/* #[<ENTRY_PORT>]# eiSemaphore
 * entry port: eiSemaphore
 * signature:  siSemaphore
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiSemaphore_signal
 * name:         eiSemaphore_signal
 * global_name:  tSemaphore_eiSemaphore_signal
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiSemaphore_signal(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(isig_sem(ATTR_id));
}
