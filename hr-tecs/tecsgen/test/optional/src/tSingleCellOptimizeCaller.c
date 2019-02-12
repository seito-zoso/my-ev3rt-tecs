/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSingleCellOptimizeCaller_template.c => src/tSingleCellOptimizeCaller.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   void           cCall_func( );
 *
 * #[</PREAMBLE>]# */

#include "tSingleCellOptimizeCaller_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/*
 * name:         eEnt_func
 * global_name:  tSingleCellOptimizeCaller_eEnt_func
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eEnt_func(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	if( is_cCall_joined() )
		cCall_func();
	else
		printf( "tSingleCellOptimizeCaller: cCall: not joined\n" );
}

/* #[<ENTRY_FUNC>]# eEnt_func2
 * name:         eEnt_func2
 * global_name:  tSingleCellOptimizeCallee_eEnt_func2
 * oneway:       
 * #[/ENTRY_FUNC>]# */
int32_t
eEnt_func2(CELLIDX idx, int32_t arg)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	if( is_cCall_joined() ){
		int32_t res;
		res = cCall_func2( arg );
		return res;
	}
	else
		printf( "tSingleCellOptimizeCaller: cCall: not joined\n" );

}

/* #[<ENTRY_FUNC>]# eEnt_func3
 * name:         eEnt_func3
 * global_name:  tSingleCellOptimizeCallee_eEnt_func3
 * oneway:       
 * #[/ENTRY_FUNC>]# */
struct tagST 
eEnt_func3(CELLIDX idx, struct tagST  a)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	if( is_cCall_joined() ){
		struct tagST res;
		res = cCall_func3( a );
		return res;
	}
	else
		printf( "tSingleCellOptimizeCaller: cCall: not joined\n" );

}



