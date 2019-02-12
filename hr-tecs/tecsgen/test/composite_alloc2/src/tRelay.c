/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRelay_template.c => src/tRelay.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   ER             cCall_func( int32_t* a );
 *   ER             cCall_func2( int8_t* buf, int32_t sz );
 * allocator port for call port: eEnt func: func param: a
 *   ER             eEnt_func_a_alloc( int32_t sz, void** p );
 *   ER             eEnt_func_a_dealloc( const void* p );
 * allocator port for call port: eEnt func: func2 param: buf
 *   ER             eEnt_func2_buf_alloc( int32_t sz, void** p );
 *   ER             eEnt_func2_buf_dealloc( const void* p );
 * allocator port for call port: cCall func: func param: a
 *   ER             cCall_func_a_alloc( int32_t sz, void** p );
 *   ER             cCall_func_a_dealloc( const void* p );
 * allocator port for call port: cCall func: func2 param: buf
 *   ER             cCall_func2_buf_alloc( int32_t sz, void** p );
 *   ER             cCall_func2_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tRelay_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func
 * name:         eEnt_func
 * global_name:  tRelay_eEnt_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_func(CELLIDX idx, int32_t* a)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_func2
 * name:         eEnt_func2
 * global_name:  tRelay_eEnt_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_func2(CELLIDX idx, int8_t* buf, int32_t sz)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
