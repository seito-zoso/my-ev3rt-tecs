/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRPCAdaptor_template.c => src/tRPCAdaptor.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * jbuf             jmp_buf          VAR_jbuf        
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sTaskBody context: task
 *   void           cCall_main( );
 * call port : cOpener  signature: sSocketClientOpener context: task
 *   ER             cOpener_open( const char_t* serverAddr, uint16_t portNo, TMO tmo );
 *   ER             cOpener_simpleOpen( TMO tmo );
 *   ER             cOpener_close( TMO tmo );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tRPCAdaptor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define  LONGJMP_SETJMP		(0)
#define  LONGJMP_OPEN		(1)
#define  LONGJMP_HANDLER	(2)

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tRPCAdaptor_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	int     ret;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	/* set jbuf or return by longjmp */
	if( (ret=setjmp( VAR_jbuf )) != LONGJMP_SETJMP ){
		// 例外で走りなおす
		if( ret == LONGJMP_HANDLER ){
			// 必要なら、ここで後始末をする

			// チャンネルは開いているものとして、閉じる
			cOpener_close( TMO_FEVR );
		}
		syslog( LOG_INFO, "tRPCAdaptor: rerun" );
		sleep( 3 );    // 3秒ごとに retry
	}


	syslog( LOG_INFO, "tRPCAdaptor: opening Channel" );
	if( cOpener_simpleOpen( TMO_FEVR ) != E_OK ){
	// if( cOpener_open("127.0.0.1", 8931, TMO_FEVR ) != E_OK ){
	// if( cOpener_open("192.168.99.2", 8931, TMO_FEVR ) != E_OK ){
		syslog( LOG_INFO, "tRPCAdaptor: fail to open" );
		// open の失敗だけなら longjmp でなくても戻れるが、handler と同じに扱う
		longjmp( VAR_jbuf, LONGJMP_OPEN );
	}

	syslog( LOG_INFO, "tRPCAdaptor: calling Main" );
	cCall_main();

	syslog(LOG_INFO, "tRPCAdaptor:  closing channel");
	cOpener_close( TMO_FEVR );
}

/* #[<ENTRY_PORT>]# eErrorHandler
 * entry port: eErrorHandler
 * signature:  sRPCErrorHandler
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eErrorHandler_errorOccured
 * name:         eErrorHandler_errorOccured
 * global_name:  tRPCAdaptor_eErrorHandler_errorOccured
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eErrorHandler_errorOccured(CELLIDX idx, int16_t func_id, ER er, int16_t state)
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
	longjmp( VAR_jbuf, LONGJMP_HANDLER );
	// NOTE:
	//   never return here
	//   if resources are remained open, they must be closed or resources are leaked.

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
