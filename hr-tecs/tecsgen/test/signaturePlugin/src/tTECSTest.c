/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tTECSTest_tecsgen.h"

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
 * global_name:  tTECSTest_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
    int32_t  ret;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

    printf( "tTECSTest::eTaskBody_main\n" );
    X_test( /* int_t input */  0 );
    X_test2( /* int_t input */ 1, /* int32_t* ret */ &ret );
    X_test3( /* const char_t* input */ "2", /* int32_t* ret */ &ret );
    X_test4( /* const char_t* input */ "3", /* int32_tlen */ 1 );
    
	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eTest
 * entry port: eTest
 * signature:  sTest
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTest_test
 * name:         eTest_test
 * global_name:  tTECSTest_eTest_test
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTest_test(CELLIDX idx, int_t input)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}
    printf( "eTest_test(CELLIDX idx=%08x, int_t input=%d)\n", idx, input );

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTest_test2
 * name:         eTest_test2
 * global_name:  tTECSTest_eTest_test2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eTest_test2(CELLIDX idx, int_t input, int32_t* ret)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}
    *ret = 2;
    printf( "eTest_test2(CELLIDX idx=%08x, int_t input=%d, int32_t *ret=)\n", idx, input, *ret );

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTest_test3
 * name:         eTest_test3
 * global_name:  tTECSTest_eTest_test3
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eTest_test3(CELLIDX idx, const char_t* input, int32_t* ret)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}
    *ret = 3;
    printf( "eTest_test3(CELLIDX idx=%08x, char_t input=%s, int32_t *ret=)\n", idx, input, *ret );

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTest_test4
 * name:         eTest_test4
 * global_name:  tTECSTest_eTest_test4
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eTest_test4(CELLIDX idx, const char_t* input, int32_t len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}
    printf( "eTest_test3(CELLIDX idx=%08x, char_t input=%s, int32_t len)\n", idx, input, len );

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTest_test5
 * name:         eTest_test5
 * global_name:  tTECSTest_eTest_test5
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eTest_test5(CELLIDX idx, const ST* input)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
