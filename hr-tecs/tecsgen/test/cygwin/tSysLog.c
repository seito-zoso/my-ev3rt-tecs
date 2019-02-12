/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

#include <stdio.h>
#include <sys/unistd.h>
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
#define	BUF_LEN	(128)
	char	buf[BUF_LEN+2];
	int	len;
	snprintf( buf, BUF_LEN, (char *)p_syslog->loginfo[0], p_syslog->loginfo[1], p_syslog->loginfo[2],
			p_syslog->loginfo[3], p_syslog->loginfo[4], p_syslog->loginfo[5] );
	buf[128] = '\0';
	len = strlen(buf);
	buf[len] = '\n';
	buf[len+1] = '\0';
	write( 2, buf, strlen(buf) );
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
