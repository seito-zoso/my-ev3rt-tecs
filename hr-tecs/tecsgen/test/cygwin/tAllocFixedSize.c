/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tAllocFixedSize_template.c => src/tAllocFixedSize.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * size             int32_t          ATTR_size       
 * buffer           int8_t*          VAR_buffer      
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tAllocFixedSize_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eA
 * entry port: eA
 * signature:  sAllocFixedSize
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eA_alloc
 * name:         eA_alloc
 * global_name:  tAllocFixedSize_eA_alloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_alloc(CELLIDX idx, void** p, TMO tmo)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    *p = malloc( ATTR_fixed_size );

    /* malloc が NULL なら */
    return ( *p != 0 ) ? E_OK: E_NOMEM;
}

/* #[<ENTRY_FUNC>]# eA_dealloc
 * name:         eA_dealloc
 * global_name:  tAllocFixedSize_eA_dealloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_dealloc(CELLIDX idx, const void* p)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

    free( (void *)p );
	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
