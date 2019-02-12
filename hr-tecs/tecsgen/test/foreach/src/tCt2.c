#include <stdio.h>
#include "tCt2_tecsgen.h"

#ifndef E_OK
#define	E_OK            0               /* 正常終了 */
#define	E_ID            (-18)           /* 不正ID番号 */
#endif


/* 属性アクセスマクロ */
/*
 * c                int32_t          ATTR_c
 */

/* 受け口関数 */
/*
 * entry port: eE
 * signature:  sSig
 */
/*
 * name:         eE_func
 * global_name:  tCt2_eE_func
 */
ER             eE_func( tCt2_IDX idx, int_least8_t a)
{
    ER       ercd_ = E_OK;
    tCt2_CB *p_cellcb;
    if( tCt2_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }

    printf( "tCt2: a=%d  c=%d\n", a, ATTR_c );
    return ercd_;
}

