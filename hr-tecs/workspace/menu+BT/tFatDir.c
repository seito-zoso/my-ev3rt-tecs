/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tFatDir_template.c => src/tFatDir.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * dirObject        DIR              VAR_dirObject   
 * fno              FILINFO          VAR_fno         
 * res              FRESULT          VAR_res         
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tFatDir_tecsgen.h"
#include "ff.h"
#include "string.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eFatDir
 * entry port: eFatDir
 * signature:  sFatDir
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eFatDir_fopendir
 * name:         eFatDir_fopendir
 * global_name:  tFatDir_eFatDir_fopendir
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatDir_fopendir(CELLIDX idx, const TCHAR* path)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return f_opendir(&VAR_dirObject, path);
}

/* #[<ENTRY_FUNC>]# eFatDir_fclosedir
 * name:         eFatDir_fclosedir
 * global_name:  tFatDir_eFatDir_fclosedir
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatDir_fclosedir(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return f_closedir(&VAR_dirObject);
}

/* #[<ENTRY_FUNC>]# eFatDir_freaddir
 * name:         eFatDir_freaddir
 * global_name:  tFatDir_eFatDir_freaddir
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatDir_freaddir(CELLIDX idx, TCHAR* buffer, int len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	VAR_res = f_readdir(&VAR_dirObject, &VAR_fno);
	strncpy(buffer, VAR_fno.fname, len);
	return VAR_res;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
