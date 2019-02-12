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
