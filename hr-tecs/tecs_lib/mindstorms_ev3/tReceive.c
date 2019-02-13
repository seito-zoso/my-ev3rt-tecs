/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tReceive_template.c => src/tReceive.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * irepLib          uint8_t*         ATTR_irepLib
 * irepAppSize      uint32_t         ATTR_irepAppSize
 * mrb              mrb_state*       VAR_mrb
 * context          mrbc_context*    VAR_context
 * irepApp          uint8_t*         VAR_irepApp
 * bw               uint16_t*        VAR_bw
 * fs               FIL              VAR_fs
 *
 * �ƤӸ��ؿ� #_TCPF_#
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

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
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

/* �������ؿ� #_TEPF_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */

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
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
void
mrb_init_mrb2(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c){

    /* ���Ĥ� mruby bytecode ��ư����� */
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