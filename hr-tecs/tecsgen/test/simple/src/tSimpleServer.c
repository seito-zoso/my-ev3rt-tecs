/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSimpleServer_template.c => src/tSimpleServer.c
 * のように名前, フォルダを変更してから修正します
 *
 * #[</PREAMBLE>]# */

#include "tSimpleServer_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSimple
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func1
 * name:         eEnt_func1
 * global_name:  tSimpleServer_eEnt_func1
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eEnt_func1(CELLIDX idx, int32_t inval)
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
	printf( "func1: %d\n", inval );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_func2
 * name:         eEnt_func2
 * global_name:  tSimpleServer_eEnt_func2
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eEnt_func2(CELLIDX idx, char_t* str)
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
	strcpy( str, "hello!" );

	return(ercd);
}

