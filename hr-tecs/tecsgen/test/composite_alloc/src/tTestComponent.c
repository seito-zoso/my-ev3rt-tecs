/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/_template.c => src/.c
 * のように名前, フォルダを変更してから修正します
 *
 * 呼び口関数 #_TCPF_#
 * call port : cS  signature: sSendRecv
 *   ER             cS_snd( int8_t* buf, int32_t sz );
 *   ER             cS_rcv( int8_t** buf, int32_t* sz );
 * call port : eS_snd_buf  signature: sAlloc
 *   ER             eS_snd_buf_alloc( int32_t size, void** p );
 *   ER             eS_snd_buf_dealloc( const void* p );
 * call port : eS_rcv_buf  signature: sAlloc
 *   ER             eS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             eS_rcv_buf_dealloc( const void* p );
 * call port : cS_snd_buf  signature: sAlloc
 *   ER             cS_snd_buf_alloc( int32_t size, void** p );
 *   ER             cS_snd_buf_dealloc( const void* p );
 * call port : cS_rcv_buf  signature: sAlloc
 *   ER             cS_rcv_buf_alloc( int32_t size, void** p );
 *   ER             cS_rcv_buf_dealloc( const void* p );
 *
 * #[</PREAMBLE>]# */

#include "tTestComponent_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eS
 * entry port: eS
 * signature:  sSendRecv
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eS_snd
 * name:         eS_snd
 * global_name:  tTestComponent_eS_snd
 * #[/ENTRY_FUNC>]# */
ER
eS_snd(CELLIDX idx, int8_t* buf, int32_t sz)
{
	CELLCB	*p_cellcb;
	void    *p;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

	printf( "eS_snd: sz = %d\n", sz );
	puts( buf );

	cS_snd_buf_alloc( sz, &p );
	memcpy( p, buf, sz );
	eS_snd_buf_dealloc( (void *)buf );

	cS_snd( p, sz );
}

/* #[<ENTRY_FUNC>]# eS_rcv
 * name:         eS_rcv
 * global_name:  tTestComponent_eS_rcv
 * #[/ENTRY_FUNC>]# */
ER
eS_rcv(CELLIDX idx, int8_t** buf, int32_t* sz)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します */

}

