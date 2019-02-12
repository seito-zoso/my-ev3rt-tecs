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
 * a                int32_t       ATTR_a          
 * b                int32_t       VAR_b           
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig2
 *   ER             cCall_func1( int32_t a );
 *   int32_t     cCall_func2( int32_t a );
 *
 * #[</PREAMBLE>]# */

#include "tCell2_active_single_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEntry
 * entry port: eEntry
 * signature:  sSig3
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEntry_func1
 * name:         eEntry_func1
 * global_name:  tCell2_active_single_eEntry_func1
 * #[/ENTRY_FUNC>]# */
ER
eEntry_func1(int32_t a)
{
}

/* #[<ENTRY_FUNC>]# eEntry_func2
 * name:         eEntry_func2
 * global_name:  tCell2_active_single_eEntry_func2
 * #[/ENTRY_FUNC>]# */
int32_t
eEntry_func2(int32_t a)
{
}

