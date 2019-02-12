/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tPtrCt_template.c => src/tPtrCt.c
 * のように名前, フォルダを変更してから修正します
 *
 * 属性アクセスマクロ #_CAAM_#
 * a_fp             int32_t(* )()    ATTR_a_fp       
 * fp               int32_t(* )()    VAR_fp          
 *
 * #[</PREAMBLE>]# */

#include "tPtrCt_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

main()
{
	if( c_fp == 0 ){
		puts( "c_pf != 0" );
	}
}
