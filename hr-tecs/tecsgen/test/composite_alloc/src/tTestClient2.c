/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/_template.c => src/.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cS  signature: sSendRecv
 *   ER             cS_snd( int8_t* buf, int32_t sz );
 *   ER             cS_rcv( int8_t** buf, int32_t* sz );
 * call port : cS_snd_buf  signature: sAlloc
 *   ER             cS_snd_buf_alloc( int32_t size, void** p );
 *   ER             cS_snd_buf_dealloc( const void* p );
 * call port : cS_rcv_buf  signature: sAlloc
 *   ER             cS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             cS_rcv_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

#include "tTestClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

#define BUF_LEN 64

main()
{
	int8_t   *buf;
	int32_t  i;

	if( cS_snd_buf_alloc( BUF_LEN, (void **)&buf ) != E_OK ){
		puts( "alloc failed" );
		exit(1);
	}

	for( i = 0; i < BUF_LEN-2; i++ )
		buf[i] = i+64;

	buf[BUF_LEN-2]='\n';
	buf[BUF_LEN-1]=0;

	cS_snd(buf, BUF_LEN);
}
