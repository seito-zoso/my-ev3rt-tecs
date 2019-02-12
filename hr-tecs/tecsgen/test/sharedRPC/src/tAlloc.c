/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tAlloc_template.c => src/tAlloc.c
 * のように名前, フォルダを変更してから修正します
 *
 * #[</PREAMBLE>]# */

#include <stdlib.h>
#include "tAlloc_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eAlloc
 * entry port: eAlloc
 * signature:  sAlloc
 * params: 
 * #[</ENTRY_PORT>]# */

char alloc_mem[1024];

/* #[<ENTRY_FUNC>]# eAlloc_alloc
 * name:         eAlloc_alloc
 * global_name:  tAlloc_eAlloc_alloc
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eAlloc_alloc(CELLIDX idx, int32_t size, void **p)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

	syslog(LOG_INFO, "allocated %d", size );
	/* 超安易実装!!! */
	*p = (void *)alloc_mem;
	return E_OK;
}

/* #[<ENTRY_FUNC>]# eAlloc_dealloc
 * name:         eAlloc_dealloc
 * global_name:  tAlloc_eAlloc_dealloc
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eAlloc_dealloc(CELLIDX idx, const void* ptr)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	/* 超安易実装!!!: 何もしません */

	syslog(LOG_INFO, "free" );
	return(ercd);
}

