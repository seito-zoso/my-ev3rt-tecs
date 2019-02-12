/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tFatDir_template.c => src/tFatDir.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * dirObject        DIR              VAR_dirObject   
 * fno              FILINFO          VAR_fno         
 * res              FRESULT          VAR_res         
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tFatDir_tecsgen.h"
#include "ff.h"
#include "string.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
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
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	VAR_res = f_readdir(&VAR_dirObject, &VAR_fno);
	strncpy(buffer, VAR_fno.fname, len);
	return VAR_res;
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
