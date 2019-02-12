#ifndef tTLSFMalloc__INLINE_H
#define tTLSFMalloc__INLINE_H

#include "tlsf.h"

/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * memoryPoolSize   size_t           ATTR_memoryPoolSize
 * pool             uint64_t*        VAR_pool        
 *
 * #[</PREAMBLE>]# */

/* #[<ENTRY_PORT>]# eMalloc
 * entry port: eMalloc
 * signature:  sMalloc
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMalloc_initializeMemoryPool
 * name:         eMalloc_initializeMemoryPool
 * global_name:  tTLSFMalloc_eMalloc_initializeMemoryPool
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline int
eMalloc_initializeMemoryPool(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
	} /* end if VALID_IDX(idx) */

  return init_memory_pool(ATTR_memoryPoolSize, VAR_pool);
}

/* #[<ENTRY_FUNC>]# eMalloc_calloc
 * name:         eMalloc_calloc
 * global_name:  tTLSFMalloc_eMalloc_calloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void*
eMalloc_calloc(CELLIDX idx, size_t nelem, size_t elem_size)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
	} /* end if VALID_IDX(idx) */

  return calloc_ex( nelem, elem_size, VAR_pool);
}

/* #[<ENTRY_FUNC>]# eMalloc_malloc
 * name:         eMalloc_malloc
 * global_name:  tTLSFMalloc_eMalloc_malloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void*
eMalloc_malloc(CELLIDX idx, size_t size)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
	} /* end if VALID_IDX(idx) */

  return malloc_ex(size, VAR_pool);

}

/* #[<ENTRY_FUNC>]# eMalloc_realloc
 * name:         eMalloc_realloc
 * global_name:  tTLSFMalloc_eMalloc_realloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void*
eMalloc_realloc(CELLIDX idx, const void* ptr, size_t new_size)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
	} /* end if VALID_IDX(idx) */

  return realloc_ex((void *)ptr, new_size, VAR_pool);
}

/* #[<ENTRY_FUNC>]# eMalloc_free
 * name:         eMalloc_free
 * global_name:  tTLSFMalloc_eMalloc_free
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eMalloc_free(CELLIDX idx, const void* ptr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
	} /* end if VALID_IDX(idx) */

  return free_ex((void *)ptr, VAR_pool);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

#endif /* tTLSFMalloc_INLINEH */
