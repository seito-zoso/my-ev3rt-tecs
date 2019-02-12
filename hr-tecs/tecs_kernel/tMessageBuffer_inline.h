/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tMessageBuffer_inline_template.h => src/tMessageBuffer_inline.h
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id         
 *
 * #[</PREAMBLE>]# */
#include "kernel.h"

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eSendMessageBuffer
 * entry port: eSendMessageBuffer
 * signature:  sSendMessageBuffer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSendMessageBuffer_send
 * name:         eSendMessageBuffer_send
 * global_name:  tMessageBuffer_eSendMessageBuffer_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eMessageBuffer_send(CELLIDX idx, const uint8_t* message, uint32_t size)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = snd_mbf(ATTR_id, message, size);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSendMessageBuffer_sendPolling
 * name:         eSendMessageBuffer_sendPolling
 * global_name:  tMessageBuffer_eSendMessageBuffer_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eMessageBuffer_sendPolling(CELLIDX idx, const uint8_t* message, uint32_t size)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = psnd_mbf(ATTR_id, message, size);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSendMessageBuffer_sendTimeout
 * name:         eSendMessageBuffer_sendTimeout
 * global_name:  tMessageBuffer_eSendMessageBuffer_sendTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eMessageBuffer_sendTimeout(CELLIDX idx, const uint8_t* message, uint32_t size, TMO timeout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = tsnd_mbf(ATTR_id, message, size, timeout);

	return(ercd);
}

/* #[<ENTRY_PORT>]# eReceiveMessageBuffer
 * entry port: eReceiveMessageBuffer
 * signature:  sReceiveMessageBuffer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReceiveMessageBuffer_receive
 * name:         eReceiveMessageBuffer_receive
 * global_name:  tMessageBuffer_eReceiveMessageBuffer_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER_UINT
eMessageBuffer_receive(CELLIDX idx, uint8_t* message)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = rcv_mbf(ATTR_id, message);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eReceiveMessageBuffer_receivePolling
 * name:         eReceiveMessageBuffer_receivePolling
 * global_name:  tMessageBuffer_eReceiveMessageBuffer_receivePolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER_UINT
eMessageBuffer_receivePolling(CELLIDX idx, uint8_t* message)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = prcv_mbf(ATTR_id, message);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eReceiveMessageBuffer_receiveTimeout
 * name:         eReceiveMessageBuffer_receiveTimeout
 * global_name:  tMessageBuffer_eReceiveMessageBuffer_receiveTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER_UINT
eMessageBuffer_receiveTimeout(CELLIDX idx, uint8_t* message, TMO timeout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = trcv_mbf(ATTR_id, message, timeout);

	return(ercd);
}

/* #[<ENTRY_PORT>]# eManageMessageBuffer
 * entry port: eManageMessageBuffer
 * signature:  sManageMessageBuffer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eManageMessageBuffer_initialize
 * name:         eManageMessageBuffer_initialize
 * global_name:  tMessageBuffer_eManageMessageBuffer_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eMessageBuffer_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* ���顼���������ɤ򤳤��˵��Ҥ��ޤ� */
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ini_mbf(ATTR_id);

}

/* #[<ENTRY_PORT>]# eReferMessageBuffer
 * entry port: eReferMessageBuffer
 * signature:  sReferMessageBuffer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eReferMessageBuffer_refer
 * name:         eReferMessageBuffer_refer
 * global_name:  tMessageBuffer_eReferMessageBuffer_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eMessageBuffer_refer(CELLIDX idx, T_RMBF* packet)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* �����˽������Τ򵭽Ҥ��ޤ� #_TEFB_# */
    ercd = ref_mbf(ATTR_id, packet);

	return(ercd);
}

