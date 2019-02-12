
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * call port function #_TCPF_#
 * call port: cNonInline signature: sNonInline context:task 
 *   void           cNonInline_nonInline( );
 *
 * #[</PREAMBLE>]# */

#include "tInline_tecsgen.h"

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInline1
 * entry port: eInline1
 * signature:  sInline1
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInline1_inline1
 * name:         eInline1_inline1
 * global_name:  tInline_eInline1_inline1
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eInline1_inline1(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	cNonInline_nonInline();
}

/* #[<ENTRY_PORT>]# eInline2
 * entry port: eInline2
 * signature:  sInline2
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInline2_inline2
 * name:         eInline2_inline2
 * global_name:  tInline_eInline2_inline2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eInline2_inline2(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	cNonInline_nonInline();
}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
