/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 */

#include "tAlloc_tecsgen.h"
#include "stddef.h"

#ifndef E_OK
#define	E_OK		0		/* 正常終了 */
#define	E_ID		(-18)		/* 不正ID番号 */
#endif


/* 属性アクセスマクロ */
/*
 * size             int32_t          ATTR_size       
 * buffer           int_least8_t*    VAR_buffer      
 */

/* 呼び口関数 */
/*
 */

/* 受け口関数 */
/*
 * entry port: eA
 * signature:  sAlloc
 */
/*
 * name:         eA_alloc
 * global_name:  tAlloc_eA_alloc
 */
ER             eA_alloc( tAlloc_IDX idx, int32_t size, void** p)
{
    tAlloc_CB *p_cellcb;
    if( tAlloc_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    *p = malloc( size );

	if( *p )
		printf( "tAlloc[%d]: allocated: %d bytes\n", ATTR_num, size );
	else
		printf( "tAlloc[%d]: allocate failed !! %d bytes\n", ATTR_num, size );

    /* malloc が NULL なら */
    return ( *p != 0 ) ? E_OK: E_NOMEM;
}

/*
 * name:         eA_dealloc
 * global_name:  tAlloc_eA_dealloc
 */
ER             eA_dealloc( tAlloc_IDX idx, const void* p)
{
    ER       ercd_ = E_OK;
    tAlloc_CB *p_cellcb;
    if( tAlloc_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    free( (void *)p );

	printf( "tAlloc[%d]: free\n", ATTR_num );
    return ercd_;
}

