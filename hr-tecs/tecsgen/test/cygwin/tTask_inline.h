/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * taskAttribute    ATR              ATTR_taskAttribute
 * exceptionAttribute ATR              ATTR_exceptionAttribute
 * priority         PRI              ATTR_priority   
 * stackSize        SIZE             ATTR_stackSize  
 * name             char_t*          ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * call port: cBody signature: sTaskBody context:task 
 *   void           cBody_main( );
 * call port: cExceptionBody signature: sTaskExceptionBody context:task optional: true
 *   bool_t     is_cExceptionBody_joined()                     check if joined
 *   void           cExceptionBody_main( TEXPTN pattern );
 *
 * #[</PREAMBLE>]# */

#ifndef Inline
#define	Inline	static inline	/* suitable for gcc */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTask
 * entry port: eTask
 * signature:  sTask
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTask_activate
 * name:         eTask_activate
 * global_name:  tTask_eTask_activate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_activate(CELLIDX idx)
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
	ercd = eTask_resume(idx);	

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eTask_suspend
 * name:         eTask_suspend
 * global_name:  tTask_eTask_suspend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_suspend(CELLIDX idx)
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
//	if( pthread_suspend( VAR_my_thread ) != 0 )
	pthread_mutex_lock( &VAR_my_mutex );
	if( pthread_cond_wait( &VAR_my_cond, &VAR_my_mutex ) != 0 )
		ercd = E_ILUSE;	/* とりあえず不正使用とする */
	pthread_mutex_unlock( &VAR_my_mutex );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eTask_resume
 * name:         eTask_resume
 * global_name:  tTask_eTask_resume
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eTask_resume(CELLIDX idx)
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
//	if( pthread_continue( VAR_my_thread ) != 0 )
	if( pthread_cond_signal( &VAR_my_cond ) != 0 )
		ercd = E_ILUSE;	/* とりあえず不正使用とする */

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
