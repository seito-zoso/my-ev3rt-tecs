/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSimpleServer_template.c => src/tSimpleServer.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSimpleServer_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEntA
 * entry port: eEntA
 * signature:  sSimpleA
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEntA_func1
 * name:         eEntA_func1
 * global_name:  tSimpleServer_eEntA_func1
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntA_func1(CELLIDX idx, int32_t inval)
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

/* #[<ENTRY_FUNC>]# eEntA_func2
 * name:         eEntA_func2
 * global_name:  tSimpleServer_eEntA_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntA_func2(CELLIDX idx, char_t* str, int32_t buf_len)
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

/* #[<ENTRY_PORT>]# eEntB
 * entry port: eEntB
 * signature:  sSimpleB
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEntB_func3
 * name:         eEntB_func3
 * global_name:  tSimpleServer_eEntB_func3
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntB_func3(CELLIDX idx, int32_t inval)
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

/* #[<ENTRY_FUNC>]# eEntB_func4
 * name:         eEntB_func4
 * global_name:  tSimpleServer_eEntB_func4
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntB_func4(CELLIDX idx, char_t* str, int32_t buf_len)
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

/* #[<ENTRY_FUNC>]# eEntB_func5
 * name:         eEntB_func5
 * global_name:  tSimpleServer_eEntB_func5
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntB_func5(CELLIDX idx)
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
