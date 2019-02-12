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
 * call port : cMain  signature: sMain
 *   ER             cMain_main( subscript );
 *
 * #[</PREAMBLE>]# */

#include "tMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

main()
{
	int   i;

/* -R を指定した場合に初期化が必要 */
#ifdef INITIALZE_TECSGEN
	INITIALZE_TECSGEN()
#endif

	for( i = 0; i < N_CP_cMain; i++ )
		cMain_main(i);
}
