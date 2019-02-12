/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSample context: task
 *   ER             cCall_sayHello( int32_t times );
 *   ER             cCall_howAreYou( char_t* buf, int32_t len );
 *
 * #[</PREAMBLE>]# */

#include <stdio.h>
#include "tSimple_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tSimple_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main()
{
	char   buf[256];

#define N_HELLO 3
	printf( "Simple: Say hello %d times.\n", N_HELLO );
	cCall_sayHello( N_HELLO );            /* 呼び口 cCall の sayHello を呼び出す */

	printf( "Simple: How are you?\n" );
	cCall_howAreYou( buf, sizeof buf );   /* 呼び口 cCall の howAreYou を呼び出す */
	puts( buf );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
