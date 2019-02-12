

/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * allocator port for call port:eS func:snd param: buf
 *   ER             eS_snd_buf_alloc( int32_t size, void** p );
 *   ER             eS_snd_buf_dealloc( const void* p );
 * allocator port for call port:eS func:rcv param: buf
 *   ER             eS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             eS_rcv_buf_dealloc( const void* p );
 * allocator port for call port:eA func:snd param: buf
 *   ER             eA_snd_buf_alloc( subscript, int32_t size, void** p );
 *   ER             eA_snd_buf_dealloc( subscript, const void* p );
 *       subscript:  0...(NCP_eA_snd_buf-1)
 * allocator port for call port:eA func:rcv param: buf
 *   ER             eA_rcv_buf_alloc( subscript, int32_t size, void** p );
 *   ER             eA_rcv_buf_dealloc( subscript, const void* p );
 *       subscript:  0...(NCP_eA_rcv_buf-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTestComponent2_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eS
 * entry port: eS
 * signature:  sSendRecv
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eS_snd
 * name:         eS_snd
 * global_name:  tTestComponent_eS_snd
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eS_snd(CELLIDX idx, int8_t* buf, int32_t sz)
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
	puts( buf );

    eS_snd_buf_dealloc( buf );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eS_rcv
 * name:         eS_rcv
 * global_name:  tTestComponent_eS_rcv
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eS_rcv(CELLIDX idx, int8_t** buf, int32_t* sz)
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
#define STR  "cS_rcv :  message in allocated memoery for receive"

    *sz = 256;
	if( eS_rcv_buf_alloc( *sz, (void **)buf ) != E_OK ){
		return E_NOMEM;
	}
	memset( *buf, 0, *sz );
	memcpy( *buf, STR, sizeof( STR ) );

	return(ercd);
}

/* #[<ENTRY_PORT>]# eA
 * entry port: eA
 * signature:  sSendRecv
 * context:    task
 * entry port array size:  NEP_eA
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eA_snd
 * name:         eA_snd
 * global_name:  tTestComponent_eA_snd
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_snd(CELLIDX idx, int_t subscript, int8_t* buf, int32_t sz)
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

	puts( buf );

    eS_snd_buf_dealloc( buf );
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eA_rcv
 * name:         eA_rcv
 * global_name:  tTestComponent_eA_rcv
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_rcv(CELLIDX idx, int_t subscript, int8_t** buf, int32_t* sz)
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
    *sz = 256;
	if( eS_rcv_buf_alloc( *sz, (void **)buf ) != E_OK ){
		return E_NOMEM;
	}
	memset( *buf, 0, *sz );
#define STR2  "cA_rcv :  message in allocated memoery for receive"
	memcpy( *buf, STR2, sizeof( STR2 ) );

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
