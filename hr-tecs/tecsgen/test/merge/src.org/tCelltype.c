/* HEAD COMMENT */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* 追加した PREAMBLE COMMENT */
#include "tCelltype_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt2
 * entry port: eEnt2
 * signature:  sSig2
 * context:    task
 * #[</ENTRY_PORT>]# */
/* 追加した ENTRY COMMENT */

/* #[<ENTRY_FUNC>]# eEnt2_func
 * name:         eEnt2_func
 * global_name:  tCelltype_eEnt2_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt2_func(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

	/* 追加した関数本体 1 */
}

/* #[<ENTRY_FUNC>]# eEnt2_func2
 * name:         eEnt2_func2
 * global_name:  tCelltype_eEnt2_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt2_func2(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

	/* 追加した関数本体 2 */
}

/* #[<ENTRY_FUNC>]# eEnt2_func3
 * name:         eEnt2_func3
 * global_name:  tCelltype_eEnt2_func3
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt2_func3(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

	/* 追加した関数本体 3 */
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
/* 追加した POSTAMBLE COMMENT */
