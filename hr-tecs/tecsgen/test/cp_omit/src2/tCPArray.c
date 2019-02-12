/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCPArray_template.c => src/tCPArray.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   void           cCall_func( subscript );
 *
 * #[</PREAMBLE>]# */

#include "tCPArray_tecsgen.h"

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
 * global_name:  tCPArray_eEnt_func
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
	{
		int32_t  i;
		for( i = 0; i < N_CP_cCall; i++ ){
			if( is_cCall_joined(i) ){
				printf( "tCPArray: cCall[%d]: calling cCall_func[%d]\n", i, i );
				cCall_func(i);
			}else{
				printf( "tCPArray: cCall[%d]: not joined\n", i );
			}
		}
	}
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
	{
		int32_t  i, res;
		for( i = 0; i < N_CP_cCall; i++ ){
			if( is_cCall_joined(i) ){
				printf( "tCPArray: cCall[%d]: calling cCall_func2[%d]\n", i, i );
				res = cCall_func2(i,arg);
			}else{
				printf( "tCPArray: cCall[%d]: not joined\n", i );
			}
		}
		return res;
	}
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

}


