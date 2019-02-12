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
 * 属性アクセスマクロ #_CAAM_#
 * size             int32_t          ATTR_size       
 * buffer           int8_t*          VAR_buffer      
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

	VAR_n_alloc++;
	printf( "ALLOC: allocated: %d  deallocated: %d\n", VAR_n_alloc, VAR_n_dealloc );

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

	VAR_n_dealloc++;
	printf( "DEALLOC: allocated: %d  deallocated: %d\n", VAR_n_alloc, VAR_n_dealloc );

    return ercd_;
}

