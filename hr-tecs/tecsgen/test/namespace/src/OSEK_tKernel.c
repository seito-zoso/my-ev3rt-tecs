/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tKernel_template.c => src/tKernel.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * a                tecs_int32       ATTR_a          
 * b                tecs_int16       VAR_b           
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "OSEK_tKernel_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# ka
 * entry port: ka
 * signature:  sSyscall
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# ka_cre_sem
 * name:         ka_cre_sem
 * global_name:  OSEK_tKernel_ka_cre_sem
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_ID
ka_cre_sem(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# ka_wai_sem
 * name:         ka_wai_sem
 * global_name:  OSEK_tKernel_ka_wai_sem
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
ka_wai_sem(CELLIDX idx, ID id)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# ka_rel_sem
 * name:         ka_rel_sem
 * global_name:  OSEK_tKernel_ka_rel_sem
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
ka_rel_sem(CELLIDX idx, ID id)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# ka_del_sem
 * name:         ka_del_sem
 * global_name:  OSEK_tKernel_ka_del_sem
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
ka_del_sem(CELLIDX idx, ID id)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
