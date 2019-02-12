/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func
 * name:         eEnt_func
 * global_name:  tSingleCt_eEnt_func
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*__inline__ int32_t
eEnt_func(tCt_IDX idx) */
Inline int32_t
eEnt_func()
{
	puts( "tCt_func: called" );
}

