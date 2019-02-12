/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTestOptional_template.c => src/tTestOptional.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cS  signature: sSendRecv context: task
 *   ER             cS_snd( int8_t* buf, int32_t sz );
 *   ER             cS_rcv( int8_t** buf, int32_t* sz );
 * allocator port for call port: cS func: snd param: buf
 *   ER             cS_snd_buf_alloc( int32_t size, void** p );
 *   ER             cS_snd_buf_dealloc( const void* p );
 * allocator port for call port: cS func: rcv param: buf
 *   ER             cS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             cS_rcv_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTestOptional_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
