/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTaskMain_template.c => src/tTaskMain.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cQueue  signature: sDataqueue context: task
 *   ER             cQueue_send( intptr_t data );
 *   ER             cQueue_sendPolling( intptr_t data );
 *   ER             cQueue_sendTimeout( intptr_t data, TMO timeout );
 *   ER             cQueue_sendForce( intptr_t data );
 *   ER             cQueue_receive( intptr_t* p_data );
 *   ER             cQueue_receivePolling( intptr_t* p_data );
 *   ER             cQueue_receiveTimeout( intptr_t* p_data, TMO timeout );
 *   ER             cQueue_initialize( );
 *   ER             cQueue_refer( T_RDTQ* pk_dataqueue_status );
 *
 * #[</PREAMBLE>]# */

#include "tTaskMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tTaskMain_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	char   msg[] = "hello\n";
	int    data, i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
	printf( "Dataqueue test 0\n" );
	cQueue_initialize();

	printf( "Dataqueue test 1\n" );
	for( i = 0; i < sizeof msg; i++ )
		cQueue_send( msg[i] );

	printf( "Dataqueue test 2\n" );
	for( i = 0; i < sizeof msg; i++ ){
		cQueue_receive( &data );
		putchar( data );
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
