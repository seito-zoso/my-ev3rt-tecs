/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tFatFile_template.c => src/tFatFile.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * fs               FIL              VAR_fs
 * br               UINT             VAR_br
 * read_buff        TCHAR [100]      VAR_read_buff
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tFatFile_tecsgen.h"
#include "ff.h"
#include "string.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eFatFile
 * entry port: eFatFile
 * signature:  sFatFile
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eFatFile_fopen
 * name:         eFatFile_fopen
 * global_name:  tFatFile_eFatFile_fopen
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatFile_fopen(CELLIDX idx, const TCHAR* path, const TCHAR* mode)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	// ������Mode��Ƚ�̤���
	if(!strcmp(mode,"r")){ /* �ɤ߹��� */
		f_open(&VAR_fs, path, FA_READ | FA_OPEN_EXISTING);
	}else if(!strcmp(mode,"w")){ /* �񤭹��� */
		f_open(&VAR_fs, path, FA_WRITE | FA_OPEN_ALWAYS);
	}else if(!strcmp(mode,"a")){ /* �ɲý񤭹��� */
		f_open(&VAR_fs, path, FA_WRITE | FA_OPEN_ALWAYS);
		f_lseek(&VAR_fs, f_size(&VAR_fs)); /* �ե����������˥ե�����ݥ��󥿤��ư������ */
	}


}

/* #[<ENTRY_FUNC>]# eFatFile_fclose
 * name:         eFatFile_fclose
 * global_name:  tFatFile_eFatFile_fclose
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatFile_fclose(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	return f_close(&VAR_fs);
}

/* #[<ENTRY_FUNC>]# eFatFile_fread
 * name:         eFatFile_fread
 * global_name:  tFatFile_eFatFile_fread
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatFile_fread(CELLIDX idx, TCHAR* buffer, UINT btr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	return f_read(&VAR_fs, buffer, btr, &VAR_br);
}

/* #[<ENTRY_FUNC>]# eFatFile_fwrite
 * name:         eFatFile_fwrite
 * global_name:  tFatFile_eFatFile_fwrite
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatFile_fwrite(CELLIDX idx, const TCHAR* buffer, UINT btw, UINT* bw)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	return f_write(&VAR_fs, buffer, btw, bw);
}

/* #[<ENTRY_FUNC>]# eFatFile_unlink
 * name:         eFatFile_unlink
 * global_name:  tFatFile_eFatFile_unlink
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
FRESULT
eFatFile_unlink(CELLIDX idx, const TCHAR* path)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
	f_unlink(path);
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
