/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tSharedMemory_template.c => src/tSharedMemory.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * size             int32_t          ATTR_size
 * data             int32_t*         VAR_data
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tSharedMemory_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    return ATTR_size;
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
