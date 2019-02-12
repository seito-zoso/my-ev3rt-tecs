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
 * v                int32_t          VAR_v           
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall0  signature: sSig
 *   int32_t        cCall0_func( int32_t in, int32_t* out );
 * call port : cCall1  signature: sSig
 *   int32_t        cCall1_func( int32_t in, int32_t* out );
 *
 * #[</PREAMBLE>]# */

#include "tCt2_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

