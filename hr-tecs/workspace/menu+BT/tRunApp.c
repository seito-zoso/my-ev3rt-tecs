/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tRunApp_template.c => src/tRunApp.c
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
#include "tRunApp_tecsgen.h"

#include <mruby.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c);

/* �������ؿ� #_TEPF_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
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
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
void
mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c){

    /* ���Ĥ� mruby bytecode ��ư����� */
    mrb_load_irep_cxt(mrb, ATTR_irepLib, c);     //mruby library
    // mrb_load_irep_cxt(mrb, buf, c);      //mruby application (transferred via Bluetooth)
    mrb_load_irep_cxt(mrb, VAR_irepApp, c);
    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
        exit(0);
    }
}