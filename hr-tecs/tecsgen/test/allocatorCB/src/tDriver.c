/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tDriver_template.c => src/tDriver.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cDev  signature: sSigDev context: task
 *   ER             cDev_Send( int8_t* buf, int32_t len );
 *   ER             cDev_Receive( int8_t** buf, int32_t* len );
 * allocator port for call port: eCB func: Send param: buf
 *   ER             eCB_Send_buf_alloc( int32_t size, void** p );
 *   ER             eCB_Send_buf_dealloc( const void* p );
 * allocator port for call port: eCB func: Receive param: buf
 *   ER             eCB_Receive_buf_alloc( int32_t size, void** p );
 *   ER             eCB_Receive_buf_dealloc( const void* p );
 * allocator port for call port: cDev func: Send param: buf
 *   ER             cDev_Send_buf_alloc( int32_t size, void** p );
 *   ER             cDev_Send_buf_dealloc( const void* p );
 * allocator port for call port: cDev func: Receive param: buf
 *   ER             cDev_Receive_buf_alloc( int32_t size, void** p );
 *   ER             cDev_Receive_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tDriver_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eCB
 * entry port: eCB
 * signature:  sSigCB
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCB_Send
 * name:         eCB_Send
 * global_name:  tDriver_eCB_Send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCB_Send(CELLIDX idx, int8_t* buf, int32_t len)
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
	syslog( LOG_INFO, "tDriver: eCB_Send:  Enter (len = %d )", len );
	cDev_Send_buf_dealloc( buf );
 
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eCB_Receive
 * name:         eCB_Receive
 * global_name:  tDriver_eCB_Receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCB_Receive(CELLIDX idx, int8_t** buf, int32_t* len)
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
#define LEN 32
	*len = LEN;
	cDev_Receive_buf_alloc( *len,  (void *)*buf );
	syslog( LOG_INFO, "tDriver: eCB_Receive: Exit  ( *len = %d )", *len );

	return(ercd);
}

/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tDriver_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	int32_t i, len;
	int8_t  *buf;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
#define LEN2 86
	len = LEN2;
	cDev_Send_buf_alloc( len, (void **)&buf );
	for( i = 0; i < len; i++ )
		buf[ i ] = i * i;

	syslog( LOG_INFO, "tDriver: eTaskBody_main: calling cDev_Send( len = %d )", len );
	cDev_Send( buf, len );

	syslog( LOG_INFO, "tDriver: eTaskBody_main: calling cDev_Receive()" );
	cDev_Receive( &buf, &len );
	syslog( LOG_INFO, "tDriver: eTaskBody_main: returned from cDev_Receive( len = %d )", len );
	cDev_Receive_buf_dealloc( buf );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
