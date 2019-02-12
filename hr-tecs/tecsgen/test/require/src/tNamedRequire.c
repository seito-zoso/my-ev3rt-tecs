/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tNamedRequire_template.c => src/tNamedRequire.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSyscall context: task
 *   ER             cCall_func( );
 * require port : signature: sSyscall context: task
 *   ER             cReqCall_func( );
 * require port : signature: sSyscall context: task
 *   ER             func( );
 *
 * #[</PREAMBLE>]# */

#include "tNamedRequire_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSc
 * entry port: eSc
 * signature:  sSyscall
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSc_func
 * name:         eSc_func
 * global_name:  tNamedRequire_eSc_func
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eSc_func(CELLIDX idx)
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


	puts( "tNamedRequire: func: called" );
	puts( "tNamedRequire: func: calling required port: func" );
	func();
	puts( "tNamedRequire: func: calling call port: cCall_func" );
	cCall_func();
	puts( "tNamedRequire: func: calling required port: cReqCall_func" );
	cReqCall_func();
	return(ercd);
}

