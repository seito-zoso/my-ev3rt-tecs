/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tReceive_template.c => src/tReceive.c
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
 * bw               uint16_t*        VAR_bw
 * fs               FIL              VAR_fs
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
#include "tReceive_tecsgen.h"
#include <mruby.h>
#include <ff.h>

#include "zmodem-toppers.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void mrb_init_mrb2(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c);
static void test_serial_loader(CELLCB *p_cellcb, intptr_t portid);
ER zmodem_recv_file(ID portid, void *buf, SIZE size, SIZE *filesz);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eReceive
 * entry port: eReceive
 * signature:  sReceive
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReceive_receive
 * name:         eReceive_receive
 * global_name:  tReceive_eReceive_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eReceive_receive(CELLIDX idx, const char_t* path)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

  while(1) {
    test_serial_loader(p_cellcb, SIO_PORT_BT);
    cFatFile_fopen(path,"w");
    // cFatFile_fopen("mrb_app/received.mrb","w");
    cFatFile_fwrite(VAR_irepApp, ATTR_irepAppSize, VAR_bw);
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
    mrb_init_mrb2(p_cellcb, VAR_mrb, VAR_context);
    mrbc_context_free( VAR_mrb, VAR_context );
    mrb_close( VAR_mrb );
  }
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
void
mrb_init_mrb2(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c){

    /* ２つの mruby bytecode を動作させる */
    mrb_load_irep_cxt(mrb, ATTR_irepLib, c);     //mruby library
    // mrb_load_irep_cxt(mrb, buf, c);      //mruby application (transferred via Bluetooth)
    mrb_load_irep_cxt(mrb, VAR_irepApp, c);
    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
        exit(0);
    }
}
static
void test_serial_loader(CELLCB *p_cellcb, intptr_t portid) {
    SIZE filesz;

    zmodem_recv_file(portid, VAR_irepApp, ATTR_irepAppSize, &filesz);
}