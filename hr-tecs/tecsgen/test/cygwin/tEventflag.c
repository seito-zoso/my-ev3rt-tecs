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
 *  @(#) $Id: tFixedSizeMemoryPool_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 * mutex            pthread_mutex_t  VAR_mutex       
 * cond             pthread_cond_t   VAR_cond        
 * pattern          FLGPTN           VAR_pattern     
 *
 * #[</PREAMBLE>]# */

#include "errno.h"
#include "tEventflag_tecsgen.h"

Inline ER Eventflag_errno_conv( int err_no )
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
	case ETIMEDOUT:
		err = E_TMOUT;
		break;
//	case EPERM:
//		err = E_;  // 他のスレッドが解放しようとした場合が想定されていない（起こらないし）
//		break;
	default:
		err = E_CTX;  // よくわからないものは、とりあえずコンテキストエラー
	}
	return err;		
}

#ifdef Inline
#undef Inline
#endif
#define Inline

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEventflag
 * entry port: eEventflag
 * signature:  sEventflag
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEventflag_set
 * name:         eEventflag_set
 * global_name:  tEventflag_eEventflag_set
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_set(CELLIDX idx, FLGPTN set_pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

// puts("flag_set");
	if( pthread_mutex_lock( &VAR_mutex ) != 0 ){
		printf( "eEventflag_set: fail to lock mutext\n" );
	}
	VAR_pattern |= set_pattern;
	if( pthread_mutex_unlock( &VAR_mutex ) != 0 ){
		printf( "eEventflag_set: fail to unlock mutext\n" );
	}
	if( pthread_cond_signal( &VAR_cond ) != 0 ){
		printf( "eEventflag_set: fail to signal cond\n" );
	}
	return E_OK;
}

/* #[<ENTRY_FUNC>]# eEventflag_clear
 * name:         eEventflag_clear
 * global_name:  tEventflag_eEventflag_clear
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_clear(CELLIDX idx, FLGPTN clear_pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

// puts("flag_clear");
	if( pthread_mutex_lock( &VAR_mutex ) != 0 ){
		printf( "eEventflag_clear: fail to lock mutext\n" );
	}
	VAR_pattern &= clear_pattern;
	if( pthread_mutex_unlock( &VAR_mutex ) != 0 ){
		printf( "eEventflag_clear: fail to unlock mutext\n" );
	}

	if( pthread_cond_signal( &VAR_cond ) != 0 ){
		printf( "eEventflag_clear: fail to signal cond\n" );
	}
	
	return E_OK;
}

/* #[<ENTRY_FUNC>]# eEventflag_wait
 * name:         eEventflag_wait
 * global_name:  tEventflag_eEventflag_wait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_wait(CELLIDX idx, FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	bool_t  b_condition = false;
	int		err;

	while(1){
		if( pthread_mutex_lock( &VAR_mutex ) != 0 ){
			printf( "eEventflag_wait: fail to lock mutext\n" );
		}

		if( ( wait_flag_mode == TWF_ANDW && ( wait_pattern & VAR_pattern ) == wait_pattern )
			|| ( wait_flag_mode == TWF_ORW && ( wait_pattern & VAR_pattern ) ) ){
			b_condition = true;
			err = 0;
		}

		if( b_condition == true ){
			if( (err=pthread_mutex_unlock( &VAR_mutex )) != 0 ){
				printf( "eEventflag_wait: fail to unlock mutext: errno = %d\n", err );
			}
			break;
		}

		if( pthread_cond_wait( &VAR_cond, &VAR_mutex ) != 0 ){
			printf( "eEventflag_wait: fail to wait cond\n" );
		}
		if( (pthread_mutex_unlock( &VAR_mutex )) != 0 ){
			printf( "eEventflag_waitTimeout: fail to unlock mutext\n" );
		}
	};

	return 	Eventflag_errno_conv( err );
}

/* #[<ENTRY_FUNC>]# eEventflag_waitPolling
 * name:         eEventflag_waitPolling
 * global_name:  tEventflag_eEventflag_waitPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_waitPolling(CELLIDX idx, FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(pol_flg(ATTR_id, wait_pattern, wait_flag_mode, p_flag_pattern));
}

/* #[<ENTRY_FUNC>]# eEventflag_waitTimeout
 * name:         eEventflag_waitTimeout
 * global_name:  tEventflag_eEventflag_waitTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_waitTimeout(CELLIDX idx, FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	bool_t  b_condition = false;
	int     err;

// puts("flg_waitTimedout");

	while(1){
		if( (err=pthread_mutex_lock( &VAR_mutex )) != 0 ){
			printf( "eEventflag_waitTimeout: fail to lock mutext: errno = %d\n", err );
		}
		if( ( wait_flag_mode == TWF_ANDW && ( wait_pattern & VAR_pattern ) == wait_pattern )
			|| ( wait_flag_mode == TWF_ORW && ( wait_pattern & VAR_pattern ) ) ){
			b_condition = true;
			err = 0;
		}
		if( b_condition == true ){
			if( (err=pthread_mutex_unlock( &VAR_mutex )) != 0 ){
				printf( "eEventflag_waitTimeout: fail to unlock mutext: errno = %d\n", err );
			}
			break;
		}
		if( timeout == TMO_POL ){
			if( (err=pthread_mutex_unlock( &VAR_mutex )) != 0 ){
				printf( "eEventflag_waitTimeout: fail to unlock mutext: errno = %d\n", err );
			}
			err = ETIMEDOUT;
			break;
		}

//		puts( "cond wait" );
		if( (err=pthread_cond_wait( &VAR_cond, &VAR_mutex )) != 0 ){
			printf( "eEventflag_waitTimeout: fail to wait cond: errno = %d\n", err );
		}
		if( (err=pthread_mutex_unlock( &VAR_mutex )) != 0 ){
			printf( "eEventflag_waitTimeout: fail to unlock mutext: errno = %d\n", err );
		}

	}

	return 	Eventflag_errno_conv( err );
}

/* #[<ENTRY_FUNC>]# eEventflag_initialize
 * name:         eEventflag_initialize
 * global_name:  tEventflag_eEventflag_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(ini_flg(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eEventflag_refer
 * name:         eEventflag_refer
 * global_name:  tEventflag_eEventflag_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eEventflag_refer(CELLIDX idx, T_RFLG* pk_eventflag_status)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(ref_flg(ATTR_id, pk_eventflag_status));
}

/* #[<ENTRY_PORT>]# eiEventflag
 * entry port: eiEventflag
 * signature:  siEventflag
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiEventflag_set
 * name:         eiEventflag_set
 * global_name:  tEventflag_eiEventflag_set
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiEventflag_set(CELLIDX idx, FLGPTN set_pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
//	return(iset_flg(ATTR_id, set_pattern));
}

