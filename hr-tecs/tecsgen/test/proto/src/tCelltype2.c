/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCelltype2_template.c => src/tCelltype2.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * allocator port for call port:eEnt func:Send param: buf
 *   ER             eEnt_Send_buf_alloc( int32_t size, void** p );
 *   ER             eEnt_Send_buf_dealloc( const void* p );
 * allocator port for call port:eEnt2 func:Send param: buf
 *   ER             eEnt2_Send_buf_alloc( subscript, int32_t size, void** p );
 *   ER             eEnt2_Send_buf_dealloc( subscript, const void* p );
 *       subscript:  0...(NCP_eEnt2_Send_buf-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCelltype2_tecsgen.h"

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
 * global_name:  tCelltype2_eEnt_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt_func(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "name=%s\n", ATTR_name );
}

/* #[<ENTRY_FUNC>]# eEnt_Send
 * name:         eEnt_Send
 * global_name:  tCelltype2_eEnt_Send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt_Send(CELLIDX idx, int32_t* buf, int32_t sz)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eEnt2
 * entry port: eEnt2
 * signature:  sSig
 * context:    task
 * entry port array size:  NEP_eEnt2
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt2_func
 * name:         eEnt2_func
 * global_name:  tCelltype2_eEnt2_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt2_func(CELLIDX idx, int_t subscript)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eEnt2_Send
 * name:         eEnt2_Send
 * global_name:  tCelltype2_eEnt2_Send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt2_Send(CELLIDX idx, int_t subscript, int32_t* buf, int32_t sz)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
