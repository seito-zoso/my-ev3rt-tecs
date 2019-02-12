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
 * msg              char_t*          ATTR_msg        
 *
 * 呼び口関数 #_TCPF_#
 * call port : cPrint  signature: sPrint
 *   void           cPrint_print( char_t* str );
 *
 * #[</PREAMBLE>]# */

#include "tTECSMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* <<< */
/* このファイルは gen/tTECSMain_templ.c を src/tTECSMain.c に移して使用します */
/* <<< */

/****** ここから書き加える ******/
main( )
{
	cPrint_print( ATTR_msg );
}
/****** ここまで書き加え ******/
