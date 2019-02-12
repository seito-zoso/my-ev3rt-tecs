/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSig context: task
 *   int32_t        cCall_func( );
 * call port : cCall2  signature: sSig2 context: task
 *   int32_t        cCall2_func2( );
 *
 * #[</PREAMBLE>]# */

#include "tCt2_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

main()
{
	int  i;

	cCall_func();
	for( i = 0; i < 6; i++ )
		cCall2_func2();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
