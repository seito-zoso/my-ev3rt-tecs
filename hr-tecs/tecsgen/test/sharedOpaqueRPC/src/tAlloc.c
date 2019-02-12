/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * n_alloc          int32_t          VAR_n_alloc     
 * n_dealloc        int32_t          VAR_n_dealloc   
 * n_alloc_byte     int32_t          VAR_n_alloc_byte
 *
 * #[</PREAMBLE>]# */

#include <stdlib.h>
#include "tAlloc_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

typedef struct {
	int32_t		id;
	int32_t		byte_allocated;
} ALLOC_TAG;

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eAlloc
 * entry port: eAlloc
 * signature:  sAlloc
 * context:    task
 * #[</ENTRY_PORT>]# */

//// 超安易実装用
//// char alloc_mem[1024];

/* #[<ENTRY_FUNC>]# eAlloc_alloc
 * name:         eAlloc_alloc
 * global_name:  tAlloc_eAlloc_alloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAlloc_alloc(CELLIDX idx, int32_t size, void **ptr)
{
	CELLCB		*p_cellcb;
	ALLOC_TAG	*at;
	uint32_t	i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */
	at = (ALLOC_TAG *)malloc( size + sizeof( ALLOC_TAG ) );
	*ptr = (void *)at + sizeof( ALLOC_TAG);

	VAR_n_alloc++;
	VAR_byte_alloc += size;
	at->byte_allocated = size;
	
	for( i = VAR_id_next; i < ATTR_max_n_alloc; i++ ){
		if( VAR_id_map[ i ] == 0 )
			break;
	}
	if( i == ATTR_max_n_alloc ){
		for( i = 0; i < VAR_id_next; i++ ){
			if( VAR_id_map[ i ] == 0 )
				break;
		}
		if( i == VAR_id_next ){
			syslog( LOG_INFO, "memory run out after n_alloc=%d", ATTR_max_n_alloc );
			return E_NOMEM;
		}
	}
	at->id = i;
	if( i + 1 == ATTR_max_n_alloc )
		VAR_id_next = 0;
	else
		VAR_id_next = i+1;
	VAR_id_map[ i ] = size;
	syslog(LOG_INFO, "allocated size=%d p=%08X *p=%08X id=%d", size, ptr, *ptr, i );

	return E_OK;
}

/* #[<ENTRY_FUNC>]# eAlloc_dealloc
 * name:         eAlloc_dealloc
 * global_name:  tAlloc_eAlloc_dealloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAlloc_dealloc(CELLIDX idx, const void* ptr)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	ALLOC_TAG	*at;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	at = (ALLOC_TAG *)(ptr-sizeof( ALLOC_TAG ));
	VAR_n_dealloc++;
	VAR_byte_dealloc+=at->byte_allocated;
	VAR_id_map[ at->id ] = 0;
	syslog(LOG_INFO, "free size=%d p=%08X id=%d", at->byte_allocated, ptr, at->id );

	free((void*)at);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eAlloc_printStatistics
 * name:         eAlloc_printStatistics
 * global_name:  tAlloc_eAlloc_printStatistics
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAlloc_printStatistics(CELLIDX idx)
{
	ER			ercd = E_OK;
	CELLCB		*p_cellcb;
	uint32_t	i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	syslog( LOG_INFO, "=== tAlloc: print statistics ===" );
	syslog( LOG_INFO, "n_alloc=%d n_dealloc=%d byte_alloc=%d byte_dealloc=%d",
			VAR_n_alloc, VAR_n_dealloc, VAR_byte_alloc, VAR_byte_dealloc );
	for( i = 0; i < ATTR_max_n_alloc; i++ ){
		if( VAR_id_map[ i ] != 0 )
			syslog( LOG_INFO, "unfreed id=%d", i );
	}

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
