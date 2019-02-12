/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSimpleClient_template.c => src/tSimpleClient.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSimple
 *   ER             cCall_func1( int32_t inval );
 *   ER             cCall_func2( char_t* str );
 *
 * #[</PREAMBLE>]# */

#include "tSimpleClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

int main( int argc, char **argv )
{
	char   buf[256];
	CELLCB *p_cellcb;
	
	cCall_func1( 10 );
	cCall_func2( buf );
	printf( "%s\n", buf );
}
