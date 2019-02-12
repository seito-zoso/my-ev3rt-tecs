/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCTBool_TClient_template.c => src/tCTBool_TClient.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cBooo  signature: sSigBool_T context: task
 *   bool_t         cBooo_func( subscript, bool_t boo, bool_t* boo2 );
 *   bool_t*        cBooo_func2( subscript, const bool_t* boo, int sz );
 *       subscript:  0...(NCP_cBooo-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCTBool_TClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

int main( int argc, char **argv )
{
	bool_t		boo2;
#define	BOO_LEN	(2)
	static bool_t		boo[BOO_LEN] = { true, false };
	
	cBooo_func( 0, true, &boo2 );
	cBooo_func( 1, true, &boo2 );


	cBooo_func2( 0, boo, BOO_LEN );
}
