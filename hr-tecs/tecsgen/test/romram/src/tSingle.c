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
 * 属性アクセスマクロ #_CAAM_#
 * a                int32_t          ATTR_a          
 * b                int32_t          VAR_b           
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig
 *   int32_t        cCall_func( subscript, int32_t in, int32_t* out );
 *
 * #[</PREAMBLE>]# */

#include "tSingle_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSig
 * entry port: eSig
 * signature:  sSig
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSig_func
 * name:         eSig_func
 * global_name:  tSingle_eSig_func
 * #[/ENTRY_FUNC>]# */
int32_t
eSig_func(int32_t in, int32_t* out)
{
	printf( "Single: attribute a: %d, var b: %d\n", ATTR_a, VAR_b );
}
