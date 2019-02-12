/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCt1_template.c => src/tCt1.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * allocator port for call port: eEnt func: func param: a
 *   ER             eEnt_func_a_alloc( int32_t sz, void** p );
 *   ER             eEnt_func_a_dealloc( const void* p );
 * allocator port for call port: eEnt func: func2 param: buf
 *   ER             eEnt_func2_buf_alloc( int32_t sz, void** p );
 *   ER             eEnt_func2_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

#include "tCt1_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func
 * name:         eEnt_func
 * global_name:  tCt1_eEnt_func
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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

	/* ここに処理本体を記述します */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_func2
 * name:         eEnt_func2
 * global_name:  tCt1_eEnt_func2
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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

	/* ここに処理本体を記述します */
	printf( "tCt1_eEnt_func2: %d:", ATTR_num );
	puts( buf );
	eEnt_func2_buf_dealloc( (void *)buf );
 
	return(ercd);
}

