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
 * 属性アクセスマクロ #_CAAM_#
 * a_init           int32_t          ATTR_a_init     
 * b_init           int32_t          ATTR_b_init     
 * c_init           int32_t          ATTR_c_init     
 * a                int32_t          VAR_a           
 * b                int32_t          VAR_b           
 * c                int32_t          VAR_c           
 *
 * #[</PREAMBLE>]# */

#include "tIdx_is_id_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func
 * name:         eEnt_func
 * global_name:  tIdx_is_id_eEnt_func
 * #[/ENTRY_FUNC>]# */
int32_t
eEnt_func(CELLIDX idx, int32_t in, int32_t* out)
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

