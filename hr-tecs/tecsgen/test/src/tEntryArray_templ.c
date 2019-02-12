/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : callback  signature: sArrayBack context: task
 *   int32_t        callback_func( subscript, int32_t a );
 *       subscript:  0...(NCP_callback-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEntryArray_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# earray
 * entry port: earray
 * signature:  sArray
 * context:    task
 * entry port array size:  NEP_earray
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# earray_func
 * name:         earray_func
 * global_name:  tEntryArray_earray_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
earray_func(CELLIDX idx, int_t subscript, int32_t a)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "tEntryArray   earray_func    subscript=%d/%d\n", subscript, NEP_earray );
	callback_func( subscript, 10 );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
