/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tServerErrorHandler_template.c => src/tServerErrorHandler.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cOpener  signature: sServerChannelOpener context: task
 *   ER             cOpener_open( );
 *   ER             cOpener_close( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tServerErrorHandler_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eErrorHandler
 * entry port: eErrorHandler
 * signature:  sRPCErrorHandler
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eErrorHandler_errorOccured
 * name:         eErrorHandler_errorOccured
 * global_name:  tServerErrorHandler_eErrorHandler_errorOccured
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

	/* チャンネルを閉じたのち、1秒休憩して、再度開きなおす */
	syslog( LOG_INFO, "ServerHandler closing channel" );
	cOpener_close( );
	sleep(1);
	syslog( LOG_INFO, "ServerHandler reopen channel" );
	cOpener_open( );

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
