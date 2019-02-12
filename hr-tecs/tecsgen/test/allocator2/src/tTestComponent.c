/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 */

#include "tTestComponent_tecsgen.h"

#ifndef E_OK
#define	E_OK		0		/* 正常終了 */
#define	E_ID		(-18)		/* 不正ID番号 */
#endif

/* 呼び口関数 */
/*
 * call port : eS_snd_buf  signature: sAlloc
 *   ER             eS_snd_buf_alloc( int32_t size, void** p );
 *   ER             eS_snd_buf_dealloc( void* p );
 * call port : eS_rcv_buf  signature: sAlloc
 *   ER             eS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             eS_rcv_buf_dealloc( void* p );
 */

/* 受け口関数 */
/*
 * entry port: eS
 * signature:  sSendRecv
 */
/*
 * name:         eS_snd
 * global_name:  tTestComponent_eS_snd
 */
ER             eS_snd( tTestComponent_IDX idx, int_least8_t* buf, int32_t sz)
{
    ER       ercd_ = E_OK;
    int_least8_t  *p = buf;
    tTestComponent_CB *p_cellcb;
    if( tTestComponent_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }

	puts( buf );

    eS_snd_buf_dealloc( buf );
    return ercd_;
}

/*
 * name:         eS_rcv
 * global_name:  tTestComponent_eS_rcv
 */
ER             eS_rcv( tTestComponent_IDX idx, int_least8_t** buf, int32_t *sz)
{
    ER       ercd_ = E_OK;
    tTestComponent_CB *p_cellcb;
    if( tTestComponent_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
#define STR  "cS_rcv :  message in allocated memoery for receive"

    *sz = 256;
	if( eS_rcv_buf_alloc( *sz, (void **)buf ) != E_OK ){
		return E_NOMEM;
	}
	memset( *buf, 0, *sz );
	memcpy( *buf, STR, sizeof( STR ) );
    return ercd_;
}

/*
 * entry port: eA
 * signature:  sSendRecv
 */
/*
 * name:         eA_snd
 * global_name:  tTestComponent_eA_snd
 */
ER             eA_snd( tTestComponent_IDX idx, int_t subscript, int_least8_t* buf, int32_t sz)
{
    ER       ercd_ = E_OK;
    tTestComponent_CB *p_cellcb;
    if( tTestComponent_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
	puts( buf );

    eS_snd_buf_dealloc( buf );
    return ercd_;
}

/*
 * name:         eA_rcv
 * global_name:  tTestComponent_eA_rcv
 */
ER             eA_rcv( tTestComponent_IDX idx, int_t subscript, int_least8_t** buf, int32_t* sz)
{
    ER       ercd_ = E_OK;
    tTestComponent_CB *p_cellcb;
    if( tTestComponent_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    *sz = 256;
	if( eS_rcv_buf_alloc( *sz, (void **)buf ) != E_OK ){
		return E_NOMEM;
	}
	memset( *buf, 0, *sz );
#define STR2  "cA_rcv :  message in allocated memoery for receive"
	memcpy( *buf, STR2, sizeof( STR2 ) );
    return ercd_;
    return ercd_;
}

