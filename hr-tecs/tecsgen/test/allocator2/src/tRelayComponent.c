/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRelayComponent_template.c => src/tThroughComponent.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cSR  signature: sSendRecv context: task
 *   ER             cSR_snd( int8_t* buf, int32_t sz );
 *   ER             cSR_rcv( int8_t** buf, int32_t* sz );
 * allocator port for call port: eS func: snd param: buf
 *   ER             eS_snd_buf_alloc( int32_t size, void** p );
 *   ER             eS_snd_buf_dealloc( const void* p );
 * allocator port for call port: eS func: rcv param: buf
 *   ER             eS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             eS_rcv_buf_dealloc( const void* p );
 * allocator port for call port: eA func: snd param: buf
 *   ER             eA_snd_buf_alloc( subscript, int32_t size, void** p );
 *   ER             eA_snd_buf_dealloc( subscript, const void* p );
 * allocator port for call port: eA func: rcv param: buf
 *   ER             eA_rcv_buf_alloc( subscript, int32_t size, void** p );
 *   ER             eA_rcv_buf_dealloc( subscript, const void* p );
 * allocator port for call port: cSR func: snd param: buf
 *   ER             cSR_snd_buf_alloc( int32_t size, void** p );
 *   ER             cSR_snd_buf_dealloc( const void* p );
 * allocator port for call port: cSR func: rcv param: buf
 *   ER             cSR_rcv_buf_alloc( int32_t size, void** p );
 *   ER             cSR_rcv_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

#include "tRelayComponent_tecsgen.h"
// #include <stdio.h>

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eS
 * entry port: eS
 * signature:  sSendRecv
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eS_snd
 * name:         eS_snd
 * global_name:  tRelayComponent_eS_snd
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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
	}

	/* ここに処理本体を記述します */
	printf( "tRelayComponent:eS_snd(): name=%s, size=%d\n", ATTR_name, sz );
	cSR_snd( buf, sz );
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eS_rcv
 * name:         eS_rcv
 * global_name:  tRelayComponent_eS_rcv
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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
	}

	/* ここに処理本体を記述します */
	cSR_rcv( buf, sz );
	printf( "tRelayComponent:eS_rcv(): name=%s, size=%d\n", ATTR_name, *sz );

	return(ercd);
}

/* #[<ENTRY_PORT>]# eA
 * entry port: eA
 * signature:  sSendRecv
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eA_snd
 * name:         eA_snd
 * global_name:  tRelayComponent_eA_snd
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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
	}

	/* ここに処理本体を記述します */
	cSR_snd( buf, sz );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eA_rcv
 * name:         eA_rcv
 * global_name:  tRelayComponent_eA_rcv
 * oneway:       
 * #[/ENTRY_FUNC>]# */
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
	}

	/* ここに処理本体を記述します */
	cSR_rcv( buf, sz );

	return(ercd);
}

