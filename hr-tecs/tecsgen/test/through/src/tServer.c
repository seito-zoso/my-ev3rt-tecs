/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * allocator port for call port:eEntry func:func6 param: buf
 *   ER             eEntry_func6_buf_alloc( int32_t sz, void** ptr );
 *   ER             eEntry_func6_buf_dealloc( const void* ptr );
 * allocator port for call port:eEntry func:func7 param: buf
 *   ER             eEntry_func7_buf_alloc( int32_t sz, void** ptr );
 *   ER             eEntry_func7_buf_dealloc( const void* ptr );
 *
 * #[</PREAMBLE>]# */


#include "tServer_tecsgen.h"

#ifndef E_OK
#define	E_OK            0               /* 正常終了 */
#define	E_ID            (-18)           /* 不正ID番号 */
#endif


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEntry
 * entry port: eEntry
 * signature:  sSignature
 * context:    task
 * #[</ENTRY_PORT>]# */

/* 受け口関数 #_TEPF_# */
/*
 * entry port: eEntry
 * signature:  sSignature
 */

/* #[<ENTRY_FUNC>]# eEntry_func1
 * name:         eEntry_func1
 * global_name:  tServer_eEntry_func1
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func1(CELLIDX idx, int32_t inval)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func2
 * name:         eEntry_func2
 * global_name:  tServer_eEntry_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func2(CELLIDX idx, int32_t* outval)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func3
 * name:         eEntry_func3
 * global_name:  tServer_eEntry_func3
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func3(CELLIDX idx, struct tag  stval)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func4
 * name:         eEntry_func4
 * global_name:  tServer_eEntry_func4
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func4(CELLIDX idx, stTag stval, INT inval)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func5
 * name:         eEntry_func5
 * global_name:  tServer_eEntry_func5
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func5(CELLIDX idx, stTag* stval, INT inval)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func6
 * name:         eEntry_func6
 * global_name:  tServer_eEntry_func6
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func6(CELLIDX idx, int8_t* buf, int32_t sz)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	eEntry_func6_buf_dealloc( buf );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func7
 * name:         eEntry_func7
 * global_name:  tServer_eEntry_func7
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func7(CELLIDX idx, int8_t** buf, int32_t* sz)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	*sz = 128;
#define STRING_HELLO   "hello func7!!"
	eEntry_func7_buf_alloc( *sz, (void **)buf );
	memset( *buf, 0, *sz );
	memcpy( *buf, STRING_HELLO, sizeof(STRING_HELLO) );

	return(ercd);
}
/* #[<ENTRY_FUNC>]# eEntry_func10
 * name:         eEntry_func10
 * global_name:  tServer_eEntry_func10
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntry_func10(CELLIDX idx, const stTag* stval, int32_t a)
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

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
