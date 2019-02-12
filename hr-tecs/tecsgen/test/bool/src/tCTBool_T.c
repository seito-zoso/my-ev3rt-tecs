/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCTBool_T_template.c => src/tCTBool_T.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * boo              bool_t           ATTR_boo        
 * boo2             bool_t           ATTR_boo2       
 * boo3             bool_t           ATTR_boo3       
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCTBool_T_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBooo
 * entry port: eBooo
 * signature:  sSigBool_T
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBooo_func
 * name:         eBooo_func
 * global_name:  tCTBool_T_eBooo_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eBooo_func(CELLIDX idx, bool_t boo, bool_t* boo2)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	*boo2 = false;
	printf( "func: boo=%d *boo2=%d\n", boo, *boo2 );
}

/* #[<ENTRY_FUNC>]# eBooo_func2
 * name:         eBooo_func2
 * global_name:  tCTBool_T_eBooo_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t*
eBooo_func2(CELLIDX idx, const bool_t* boo, int sz)
{
	CELLCB	*p_cellcb;
	int_t	i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
