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
eTest_test(CELLIDX idx, int input)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "tTECSTest: test %d\n", input );

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

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTest_test4
 * name:         eTest_test4
 * global_name:  tTECSTest_eTest_test4
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eTest_test4(CELLIDX idx, const char* input, int32_t len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "tTECSTest: test4 %s, %d\n", input, len );

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
