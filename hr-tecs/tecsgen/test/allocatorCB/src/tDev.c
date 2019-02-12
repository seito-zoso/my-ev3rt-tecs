/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tDev_template.c => src/tDev.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCB  signature: sSigCB context: task
 *   ER             cCB_Send( int8_t* buf, int32_t len );
 *   ER             cCB_Receive( int8_t** buf, int32_t* len );
 * allocator port for call port: eDev func: Send param: buf
 *   ER             eDev_Send_buf_alloc( int32_t size, void** p );
 *   ER             eDev_Send_buf_dealloc( const void* p );
 * allocator port for call port: eDev func: Receive param: buf
 *   ER             eDev_Receive_buf_alloc( int32_t size, void** p );
 *   ER             eDev_Receive_buf_dealloc( const void* p );
 * allocator port for call port: cCB func: Send param: buf
 *   ER             cCB_Send_buf_alloc( int32_t size, void** p );
 *   ER             cCB_Send_buf_dealloc( const void* p );
 * allocator port for call port: cCB func: Receive param: buf
 *   ER             cCB_Receive_buf_alloc( int32_t size, void** p );
 *   ER             cCB_Receive_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tDev_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eDev
 * entry port: eDev
 * signature:  sSigDev
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eDev_Send
 * name:         eDev_Send
 * global_name:  tDev_eDev_Send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eDev_Send(CELLIDX idx, int8_t* buf, int32_t len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	eDev_Send_buf_dealloc( (void *)buf );
	syslog( LOG_INFO, "tDev: eDev_Send: Enter (len=%d)", len );

	syslog( LOG_INFO, "tDev: eDev_Send: calling cCB_Receive()" );
	cCB_Receive( &buf, &len );
	syslog( LOG_INFO, "tDev: eDev_Send: returned from cCB_Receive(len=%d)", len );
	cCB_Receive_buf_dealloc( (void *)buf );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDev_Receive
 * name:         eDev_Receive
 * global_name:  tDev_eDev_Receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eDev_Receive(CELLIDX idx, int8_t** buf, int32_t* len)
{
	ER		ercd = E_OK;
	int32_t i;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	{
#define LEN   100
		int32_t  i, len = LEN;
		int8_t   *buf;

		cCB_Send_buf_alloc( len, (void **)&buf );
		for( i = 0; i < len; i++ )
			buf[ i ] = ( i + 1 ) * 2;
		syslog( LOG_INFO, "tDev: eDev_Receive: calling cCB_Send(len=%d)", len );
		cCB_Send( buf, len );
	}

	*len = 128;
	eDev_Receive_buf_alloc( *len, (void **)buf );
	for( i = 0; i < *len; i++ )
		(*buf)[ i ] = i * i;
	syslog( LOG_INFO, "tDev: eDev_Receive: Exit (*len=%d)", *len );

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
