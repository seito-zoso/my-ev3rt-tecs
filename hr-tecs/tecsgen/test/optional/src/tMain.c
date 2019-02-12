/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMain_template.c => src/tMain.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cMain  signature: sSig context: task
 *   void           cMain_func( subscript );
 *
 * #[</PREAMBLE>]# */

#include "tMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

void eMain_main()
{
	int32_t  i, res;
	struct tagST st;

	printf( "tMain: testing func() ***\n" );
	for( i = 0; i < N_CP_cMain; i++ )
		cMain_func( i );
	printf( "\ntMain: testing func2() ***\n" );
	for( i = 0; i < N_CP_cMain; i++ ){
		res = cMain_func2( i, 100+i );
		printf( "tMain: func2[%d] = %d\n", i, res );
	}
	printf( "\ntMain: testing func3() ***\n" );
	for( i = 0; i < N_CP_cMain; i++ ){
		st.a = 101;
		st = cMain_func3( i, st );
		printf( "tMain: func3[%d] = %d\n", i, st.a );
	}
}
