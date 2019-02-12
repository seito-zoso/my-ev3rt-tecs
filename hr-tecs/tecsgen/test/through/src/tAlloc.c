
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * n_alloc          int32_t          VAR_n_alloc     
 * n_dealloc        int32_t          VAR_n_dealloc   
 *
 * #[</PREAMBLE>]# */

#include "tAlloc_tecsgen.h"
#include "stddef.h"

#ifndef E_OK
#define	E_OK		0		/* 正常終了 */
#define	E_ID		(-18)		/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eA
 * entry port: eA
 * signature:  sAlloc
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eA_alloc
 * name:         eA_alloc
 * global_name:  tAlloc_eA_alloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_alloc(int32_t sz, void **ptr)
{
    *ptr = malloc( sz );

    /* malloc が NULL なら */
	if( *ptr == 0 )  return E_NOMEM;
	else             return E_OK;
}

/* #[<ENTRY_FUNC>]# eA_dealloc
 * name:         eA_dealloc
 * global_name:  tAlloc_eA_dealloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eA_dealloc(const void* ptr)
{
	free( (void *)ptr );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
