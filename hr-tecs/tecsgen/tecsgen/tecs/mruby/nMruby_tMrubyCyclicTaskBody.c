/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMrubyCyclicTaskBody_template.c => src/tMrubyCyclicTaskBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cMrubyVM signature: nMruby_sMrubyVM context:task
 *   bool_t         cMrubyVM_initialize( );
 *   bool_t         cMrubyVM_run( );
 *   void           cMrubyVM_funcall( const char_t* name );
 *   void           cMrubyVM_finalize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMruby_tMrubyCyclicTaskBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyBody
 * entry port: eMrubyBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyBody_main
 * name:         eMrubyBody_main
 * global_name:  nMruby_tMrubyCyclicTaskBody_eMrubyBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMrubyBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
  if( ! VAR_b_init ){
      cMrubyVM_initialize( );
      VAR_b_init = true;
  }
  cMrubyVM_run( );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
