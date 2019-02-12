/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tReset_template.c => src/tReset.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cMotor signature: sMotor context:task
 *   ER_UINT        cMotor_getType( subscript );
 *   int32_t        cMotor_getCounts( subscript );
 *   int            cMotor_getPower( subscript );
 *   ER             cMotor_resetCounts( subscript );
 *   ER             cMotor_setPower( subscript, int power );
 *   ER             cMotor_stop( subscript, bool_t brake );
 *   ER             cMotor_rotate( subscript, int degrees, uint32_t speed_abs, bool_t blocking );
 *   void           cMotor_initializePort( subscript, int32_t type );
 *       subscript:  0...(NCP_cMotor-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tReset_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eReset
 * entry port: eReset
 * signature:  sReset
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReset_reset
 * name:         eReset_reset
 * global_name:  tReset_eReset_reset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eReset_reset(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    cMotor_stop( 0, true );
    cMotor_stop( 1, true );
    cMotor_stop( 2, true );
    cMotor_stop( 3, true );

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
