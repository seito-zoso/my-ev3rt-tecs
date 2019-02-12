/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSimpleClient_template.c => src/tSimpleClient.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCallA signature: sSimpleA context:task
 *   ER             cCallA_func1( int32_t inval );
 *   ER             cCallA_func2( char_t* str, int32_t buf_len );
 * call port: cCallB signature: sSimpleB context:task
 *   ER             cCallB_func3( int32_t inval );
 *   ER             cCallB_func4( char_t* str, int32_t buf_len );
 *   ER             cCallB_func5( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSimpleClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
