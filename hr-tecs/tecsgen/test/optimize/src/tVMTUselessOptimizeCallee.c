/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tVMTUselessOptimizeCallee_template.c => src/tVMTUselessOptimizeCallee.c
 * のように名前, フォルダを変更してから修正します
 *
 * 属性アクセスマクロ #_CAAM_#
 * attribute        int32_t          ATTR_attribute  
 *
 * #[</PREAMBLE>]# */

#include <stdio.h>
#include "tVMTUselessOptimizeCallee_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func
 * name:         eEnt_func
 * global_name:  tVMTUselessOptimizeCallee_eEnt_func
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eEnt_func(CELLIDX idx, int_t subscript)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	printf( "tVMTUselessOptimizeCallee: eEnt_func: called\n" );

}

