/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSendRecvServ_template.c => src/tSendRecvServ.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * allocator port for call port:eEnt func:snd param: st_val
 *   ER             eEnt_snd_st_val_alloc( int32_t size, void** p );
 *   ER             eEnt_snd_st_val_dealloc( const void* p );
 * allocator port for call port:eEnt func:rcv param: st_val
 *   ER             eEnt_rcv_st_val_alloc( int32_t size, void** p );
 *   ER             eEnt_rcv_st_val_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSendRecvServ_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSigSendRecv
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_snd
 * name:         eEnt_snd
 * global_name:  tSendRecvServ_eEnt_snd
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_snd(CELLIDX idx, ST_VAL* st_val)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_rcv
 * name:         eEnt_rcv
 * global_name:  tSendRecvServ_eEnt_rcv
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_rcv(CELLIDX idx, ST_VAL** st_val)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
