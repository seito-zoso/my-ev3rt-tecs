/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tReset_template.c => src/tReset.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * �ƤӸ��ؿ� #_TCPF_#
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

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tReset_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    cMotor_stop( 0, true );
    cMotor_stop( 1, true );
    cMotor_stop( 2, true );
    cMotor_stop( 3, true );

}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
