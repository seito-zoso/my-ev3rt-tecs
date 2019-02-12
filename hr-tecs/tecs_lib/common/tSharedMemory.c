/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSharedMemory_template.c => src/tSharedMemory.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * size             int32_t          ATTR_size
 * data             int32_t*         VAR_data
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSharedMemory_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSharedMemory
 * entry port: eSharedMemory
 * signature:  sSharedMemory
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSharedMemory_putVal
 * name:         eSharedMemory_putVal
 * global_name:  tSharedMemory_eSharedMemory_putVal
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eSharedMemory_putVal(CELLIDX idx, int32_t index, int32_t val)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    VAR_data[index] = val;
}

/* #[<ENTRY_FUNC>]# eSharedMemory_getVal
 * name:         eSharedMemory_getVal
 * global_name:  tSharedMemory_eSharedMemory_getVal
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eSharedMemory_getVal(CELLIDX idx, int32_t index)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    return VAR_data[index];
}

/* #[<ENTRY_FUNC>]# eSharedMemory_getSize
 * name:         eSharedMemory_getSize
 * global_name:  tSharedMemory_eSharedMemory_getSize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int32_t
eSharedMemory_getSize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    return ATTR_size;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
