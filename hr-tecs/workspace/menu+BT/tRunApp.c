/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRunApp_template.c => src/tRunApp.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * irepLib          uint8_t*         ATTR_irepLib
 * irepAppSize      uint32_t         ATTR_irepAppSize
 * mrb              mrb_state*       VAR_mrb
 * context          mrbc_context*    VAR_context
 * irepApp          uint8_t*         VAR_irepApp
 *
 * 呼び口関数 #_TCPF_#
 * call port: cFatFile signature: sFatFile context:task
 *   FRESULT        cFatFile_fopen( const TCHAR* path, const TCHAR* mode );
 *   FRESULT        cFatFile_fclose( );
 *   FRESULT        cFatFile_fread( TCHAR* buffer, UINT btr );
 *   FRESULT        cFatFile_fwrite( const TCHAR* buffer, UINT btw, UINT* bw );
 * call port: cInit signature: nMruby_sInitializeBridge context:task optional:true
 *   bool_t     is_cInit_joined()                     check if joined
 *   void           cInit_initializeBridge( const mrb_state* mrb );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tRunApp_tecsgen.h"

#include <mruby.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eRunApp
 * entry port: eRunApp
 * signature:  sRunApp
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRunApp_runapp
 * name:         eRunApp_runapp
 * global_name:  tRunApp_eRunApp_runapp
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRunApp_runapp(CELLIDX idx, const TCHAR* target)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
  cFatFile_fopen(target,"r");
  cFatFile_fread(VAR_irepApp, ATTR_irepAppSize);
  cFatFile_fclose();
  VAR_mrb = mrb_open();
  if (VAR_mrb == NULL) {
      return;
  }
  VAR_context = mrbc_context_new( VAR_mrb );

  if (is_cInit_joined()) {
    // TECS Bridge
    cInit_initializeBridge( VAR_mrb );
  }
  mrb_init_mrb(p_cellcb, VAR_mrb, VAR_context);
  mrbc_context_free( VAR_mrb, VAR_context );
  mrb_close( VAR_mrb );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
void
mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c){

    /* ２つの mruby bytecode を動作させる */
    mrb_load_irep_cxt(mrb, ATTR_irepLib, c);     //mruby library
    // mrb_load_irep_cxt(mrb, buf, c);      //mruby application (transferred via Bluetooth)
    mrb_load_irep_cxt(mrb, VAR_irepApp, c);
    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
        exit(0);
    }
}