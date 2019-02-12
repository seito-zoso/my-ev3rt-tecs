/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/_template.c => src/.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig1 context: task
 *   ER             cCall_func1( int32_t arg1, int32_t* res );
 *
 * #[</PREAMBLE>]# */

#include "tCtOuter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig2
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func1
 * name:         eEnt_func1
 * global_name:  tCtOuter_eEnt_func1
 * #[/ENTRY_FUNC>]# */
ER
eEnt_func1(CELLIDX idx, int32_t arg1, int32_t* res)
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
	puts( "tCtOuter.eEnt_func1 : called" );

	return(ercd);
}

/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sMain
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tCtOuter_eMain_main
 * #[/ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	int32_t  res;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	puts( "tCtOuter.eMain_main : calling cCall_func1" );

	cCall_func1( 1, &res );
}

