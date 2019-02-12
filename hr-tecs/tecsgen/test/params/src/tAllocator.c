/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tAllocator_template.c => src/tAllocator.c
 * のように名前, フォルダを変更してから修正します
 *
 * #[</PREAMBLE>]# */

#include "tAllocator_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eAlloc
 * entry port: eAlloc
 * signature:  sAllocator
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAlloc_allocate
 * name:         eAlloc_allocate
 * global_name:  tAllocator_eAlloc_allocate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eAlloc_allocate(int32_t size, void** m)
{
}

/* #[<ENTRY_FUNC>]# eAlloc_deallocate
 * name:         eAlloc_deallocate
 * global_name:  tAllocator_eAlloc_deallocate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eAlloc_deallocate(void* m)
{
}

