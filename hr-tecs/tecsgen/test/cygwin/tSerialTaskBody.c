/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cBodyArray signature: sTaskBody context:task
 *   void           cBodyArray_main( subscript );
 *       subscript:  0...(NCP_cBodyArray-1)
 * call port: cTaskExceptionBodyArray signature: sTaskExceptionBody context:task optional:true
 *   bool_t     is_cTaskExceptionBodyArray_joined(int subscript)        check if joined
 *   void           cTaskExceptionBodyArray_main( subscript, TEXPTN pattern );
 *       subscript:  0...(NCP_cTaskExceptionBodyArray-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSerialTaskBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tSerialTaskBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
    int     i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    for( i = 0; i < NCP_cBodyArray; i++ ){
        printf( "------------------------------------------\ntSerialTask: %s: start [%d]\n", ATTR_name, i );
        cBodyArray_main( i );
    }
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
