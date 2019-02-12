/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCelltypeCaller_template.c => src/tCelltypeCaller.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   struct tagStruct  cCall_func1( struct tagStruct  in, const struct tagStruct * in_p, struct tagStruct * inout_p, struct tagStruct * out_p );
 *   struct tagStruct  cCall_func2( struct tagStruct  in, const struct tagStruct * in_p, struct tagStruct * inout_p, struct tagStruct * out_p, int32_t len );
 *   struct tagStruct  cCall_func3( struct tagStruct2  in, const struct tagStruct2 * in_p, struct tagStruct2 * inout_p, struct tagStruct2 * out_p );
 *   struct tagStruct  cCall_func4( struct tagStruct2  in, const struct tagStruct2 * in_p, struct tagStruct2 * inout_p, struct tagStruct2 * out_p, int32_t len );
 *   struct tagStruct  cCall_func5( struct tagStruct * inp, struct tagStruct ** outp );
 *   struct tagStruct  cCall_func6( struct tagStruct2 * sendp, struct tagStruct2 ** receivep, char_t** strs, char_t*** strr, int32_t* len );
 * allocator port for call port: cCall func: func5 param: inp
 *   ER             cCall_func5_inp_alloc( int32_t size, void** p );
 *   ER             cCall_func5_inp_dealloc( const void* p );
 * allocator port for call port: cCall func: func5 param: outp
 *   ER             cCall_func5_outp_alloc( int32_t size, void** p );
 *   ER             cCall_func5_outp_dealloc( const void* p );
 * allocator port for call port: cCall func: func6 param: sendp
 *   ER             cCall_func6_sendp_alloc( int32_t size, void** p );
 *   ER             cCall_func6_sendp_dealloc( const void* p );
 * allocator port for call port: cCall func: func6 param: receivep
 *   ER             cCall_func6_receivep_alloc( int32_t size, void** p );
 *   ER             cCall_func6_receivep_dealloc( const void* p );
 * allocator port for call port: cCall func: func6 param: strs
 *   ER             cCall_func6_strs_alloc( int32_t size, void** p );
 *   ER             cCall_func6_strs_dealloc( const void* p );
 * allocator port for call port: cCall func: func6 param: strr
 *   ER             cCall_func6_strr_alloc( int32_t size, void** p );
 *   ER             cCall_func6_strr_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tCelltypeCaller_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tCelltypeCaller_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	 *p_cellcb;
	struct   tagStruct *outp;
	struct   tagStruct2 *receiverp;
	char_t   **strr;
	int32_t  len;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */

#if 0
	CCALL_FUNC5_OUTP_DEALLOC(outp);
	CCALL_FUNC6_RECEIVEP_DEALLOC(receiverp, len);
	CCALL_FUNC6_STRR_DEALLOC(strr, len);
#endif

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
