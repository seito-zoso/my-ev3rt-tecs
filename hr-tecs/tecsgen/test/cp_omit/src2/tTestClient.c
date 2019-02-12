/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTestClient_template.c => src/tTestClient.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cS signature: sSendRecv context:task omit:true
 * call port: cA signature: sSendRecv context:task omit:true
 *       subscript:  0...(NCP_cA-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTestClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tTestClient_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    int_least8_t   *buf;
	int_least32_t   size;
#define BUF_SZ  256
#define STR  "cS_snd :  message in allocated memoery for send"

#if 0
	if( cS_snd_buf_alloc( BUF_SZ, (void **)&buf ) != E_OK ){
#define MSG "cS_snd_buf_alloc() : failed"
		puts( MSG );
		exit( 1 );
	}

	memset( buf, 0, BUF_SZ );
    memcpy( buf, STR, sizeof( STR ) );
    cS_snd( buf, 256 );

    if( cS_rcv( &buf, &size ) == E_OK ){
		puts( buf );
		cS_rcv_buf_dealloc( buf );
	}


	if( cA_snd_buf_alloc( 0, BUF_SZ, (void **)&buf ) != E_OK ){
#define MSG2 "cA_snd_buf_alloc() : failed"
		puts( MSG );
		exit( 1 );
	}

#define STR2  "cA_snd[0] :  message in allocated memoery for send"
	memset( buf, 0, BUF_SZ );
    memcpy( buf, STR2, sizeof( STR2 ) );
    cA_snd( 0, buf, 256 );

    if( cA_rcv( 1, &buf, &size ) == E_OK ){
		puts( buf );
		cA_rcv_buf_dealloc( 1, buf );
	}
#endif /* 0 */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
