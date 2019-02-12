/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCt2_template.c => src/tCt2.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   ER             cCall_func( int32_t* a );
 *   ER             cCall_func2( int8_t* buf, int32_t sz );
 * allocator port for call port: cCall func: func param: a
 *   ER             cCall_func_a_alloc( int32_t sz, void** p );
 *   ER             cCall_func_a_dealloc( const void* p );
 * allocator port for call port: cCall func: func2 param: buf
 *   ER             cCall_func2_buf_alloc( int32_t sz, void** p );
 *   ER             cCall_func2_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

#include "tCt2_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

main()
{
	int32_t   sz = 32;
	void     *p;

	cCall_func2_buf_alloc( 0, sz, &p );
	strncpy( p, "hello !!", sz );
	cCall_func2( 0, p, sz );

	cCall_func2_buf_alloc( 1, sz, &p );
	strncpy( p, "good-bye !!", sz );
	cCall_func2( 1, p, sz );
}
