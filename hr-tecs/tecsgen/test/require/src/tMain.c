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
 * call port : cCall  signature: sSyscall context: task
 *   ER             cCall_func( subscript );
 *
 * #[</PREAMBLE>]# */

#include "tMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

main()
{
	int_t   i;
	for( i = 0; i < N_CP_cCall; i++ ){
		printf( "calling cCall_func( %d );\n", i );
		cCall_func( i );
	}
}
