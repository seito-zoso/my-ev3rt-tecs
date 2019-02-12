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
 * entry port: eAlloc
 * signature:  sAlloc
 */
/*
 * name:         eAlloc_alloc
 * global_name:  tAlloc_eAlloc_alloc
 */
ER             eAlloc_alloc( tAlloc_IDX idx, int32_t size, void** p)
{
    tAlloc_CB *p_cellcb;
    if( tAlloc_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    *p = malloc( size );

    /* malloc が NULL なら */
    return ( *p != 0 ) ? E_OK: E_NOMEM;
}

/*
 * name:         eAlloc_dealloc
 * global_name:  tAlloc_eAlloc_dealloc
 */
ER             eAlloc_dealloc( tAlloc_IDX idx, const void* p)
{
    ER       ercd_ = E_OK;
    tAlloc_CB *p_cellcb;
    if( tAlloc_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    free( (void *)p );
    return ercd_;
}

