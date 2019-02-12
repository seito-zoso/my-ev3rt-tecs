/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

#include <sys/time.h>
#include <sys/unistd.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eKernel
 * entry port: eKernel
 * signature:  sKernel
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eKernel_delay
 * name:         eKernel_delay
 * global_name:  tKernel_eKernel_delay
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_delay( RELTIM tim )
{
	sleep( tim /1000 );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eKernel_exitTask
 * name:         eKernel_exitTask
 * global_name:  tKernel_eKernel_exitTask
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_exitTask()
{
	pthread_exit( (void *)0 );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eKernel_getTime
 * name:         eKernel_getTime
 * global_name:  tKernel_eKernel_getTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_getTime(SYSTIM* p_system_time)
{
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eKernel_getMicroTime
 * name:         eKernel_getMicroTime
 * global_name:  tKernel_eKernel_getMicroTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_getMicroTime(SYSUTM* p_system_micro_time)
{
	struct timeval tv;
	struct timezone *tz = 0;

	gettimeofday( &tv, tz );
	*p_system_micro_time = tv.tv_sec * 1000000+ tv.tv_usec;
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eKernel_exitKernel
 * name:         eKernel_exitKernel
 * global_name:  tKernel_eKernel_exitKernel
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_exitKernel()
{
	exit(0);
	return	E_OK;
}

/* #[<ENTRY_PORT>]# eiKernel
 * entry port: eiKernel
 * signature:  siKernel
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiKernel_getMicroTime
 * name:         eiKernel_getMicroTime
 * global_name:  tKernel_eiKernel_getMicroTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiKernel_getMicroTime(SYSUTM* p_system_micro_time)
{
	struct timeval tv;
	struct timezone *tz = 0;

	gettimeofday( &tv, tz );
	*p_system_micro_time = tv.tv_sec * 1000000+ tv.tv_usec;
	return	E_OK;
}

