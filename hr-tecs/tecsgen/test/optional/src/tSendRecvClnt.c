/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCall signature: sSigSendRecv context:task optional:true omit:true
 *   bool_t     is_cCall_joined()                     check if joined
 *   ER             cCall_snd( ST_VAL* st_val );
 *   ER             cCall_rcv( ST_VAL** st_val );
 * allocator port for call port:cCall func:snd param: st_val
 *   ER             cCall_snd_st_val_alloc( int32_t size, void** p );
 *   ER             cCall_snd_st_val_dealloc( const void* p );
 * allocator port for call port:cCall func:rcv param: st_val
 *   ER             cCall_rcv_st_val_alloc( int32_t size, void** p );
 *   ER             cCall_rcv_st_val_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSendRecvClnt_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tSendRecvClnt_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
//****  omit code cannot be called  ****
    if( is_cCall_joined() ){
        ST_VAL *st_val;
        int32_t size = sizeof( ST_VAL );
        fprintf( stderr, "cCall joined\n" );
        cCall_snd_st_val_alloc( size, &st_val );
        cCall_snd( st_val );
    }
    else {
        fprintf( stderr, "cCall NOT joined\n" );
    }
/***********/

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
