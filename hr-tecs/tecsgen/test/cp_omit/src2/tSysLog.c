/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSysLog_template.c => src/tSysLog.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSysLog_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSysLog
 * entry port: eSysLog
 * signature:  sSysLog
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSysLog_write
 * name:         eSysLog_write
 * global_name:  tSysLog_eSysLog_write
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSysLog_write(uint_t prio, const SYSLOG* p_syslog)
{
}

/* #[<ENTRY_FUNC>]# eSysLog_read
 * name:         eSysLog_read
 * global_name:  tSysLog_eSysLog_read
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eSysLog_read(SYSLOG* p_syslog)
{
}

/* #[<ENTRY_FUNC>]# eSysLog_mask
 * name:         eSysLog_mask
 * global_name:  tSysLog_eSysLog_mask
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSysLog_mask(uint_t logmask, uint_t lowmask)
{
}

/* #[<ENTRY_FUNC>]# eSysLog_refer
 * name:         eSysLog_refer
 * global_name:  tSysLog_eSysLog_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSysLog_refer(T_SYSLOG_RLOG* pk_rlog)
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
