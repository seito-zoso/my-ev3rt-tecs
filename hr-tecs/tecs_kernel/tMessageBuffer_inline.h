/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMessageBuffer_inline_template.h => src/tMessageBuffer_inline.h
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 *
 * #[</PREAMBLE>]# */
#include "kernel.h"

/* 受け口関数 #_TEPF_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
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
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
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

	/* ここに処理本体を記述します #_TEFB_# */
    ercd = ref_mbf(ATTR_id, packet);

	return(ercd);
}

