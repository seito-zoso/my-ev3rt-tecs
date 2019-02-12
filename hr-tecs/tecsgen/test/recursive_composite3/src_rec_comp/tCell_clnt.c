/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * a                int32_t          ATTR_a          
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCall signature: sSig1 context:task
 *   int32_t        cCall_func1( subscript, int32_t a );
 *   int32_t        cCall_func2( subscript, int32_t a );
 *       subscript:  0...(NCP_cCall-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCell_clnt_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tCell_clnt_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
    int_t   i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    for( i = 0; i < NCP_cCall; i++ ){
        printf( "main: -------------------  %d\n", i );
        printf( "main: calling cCall_func1( subscript=%d, a=100 )\n", i );
        cCall_func1( i, 100 );

//        printf( "main: calling cCall_func2( subscript=%d, a=200 )\n", i );
//        cCall_func2( i, 200 );
    }

    printf( "main: exit(0)\n" );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
