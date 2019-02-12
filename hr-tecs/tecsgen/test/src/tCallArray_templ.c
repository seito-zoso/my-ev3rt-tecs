/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : carray  signature: sArray context: task
 *   int32_t        carray_func( subscript, int32_t a );
 *       subscript:  0...(NCP_carray-1)
 * call port : carray2  signature: sArray context: task
 *   int32_t        carray2_func( subscript, int32_t a );
 *       subscript:  0...(NCP_carray2-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCallArray_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# callback
 * entry port: callback
 * signature:  sArrayBack
 * context:    task
 * entry port array size:  NEP_callback
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# callback_func
 * name:         callback_func
 * global_name:  tCallArray_callback_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
callback_func(CELLIDX idx, int_t subscript, int32_t a)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "tCallArray    callback_func  subscript=%d/%d\n", subscript, NEP_callback );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

main()
{
  extern CELLCB      tCallArray_CB_tab[];
  CELLCB *p_cellcb = &tCallArray_CB_tab[0];

  carray_func( 1, 10 );
}
