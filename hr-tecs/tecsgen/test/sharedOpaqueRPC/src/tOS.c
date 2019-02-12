/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

#include "tOS_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSVC
 * entry port: eSVC
 * signature:  sSVC
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSVC_systemCall
 * name:         eSVC_systemCall
 * global_name:  tOS_eSVC_systemCall
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSVC_systemCall()
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
