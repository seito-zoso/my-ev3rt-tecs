/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * id               ID               ATTR_id         
 * attribute        ATR              ATTR_attribute  
 * count            uint_t           ATTR_count      
 * pdqmb            void*            ATTR_pdqmb      
 * fd               int_t [2]        VAR_fd          
 *
 * #[</PREAMBLE>]# */

/*
 * 初めて呼び出されたときに初期化が行われるようにするためのマクロ
 */
#define INITIALIZE(idx) \
	if( ! VAR_b_init ){\
        cInitializing_wait(); \
		/* セマフォを取ってもう一度、初期化が行われていないことの確認 */ \
        if( ! VAR_b_init ){\
            eDataqueue_initialize(idx);\
            VAR_b_init = 1;\
        }\
        cInitializing_signal();\
    }


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eDataqueue
 * entry port: eDataqueue
 * signature:  sDataqueue
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eDataqueue_send
 * name:         eDataqueue_send
 * global_name:  tDataqueue_eDataqueue_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_send(CELLIDX idx, intptr_t data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_sendPolling
 * name:         eDataqueue_sendPolling
 * global_name:  tDataqueue_eDataqueue_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_sendTimeout
 * name:         eDataqueue_sendTimeout
 * global_name:  tDataqueue_eDataqueue_sendTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendTimeout(CELLIDX idx, intptr_t data, TMO timeout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_sendForce
 * name:         eDataqueue_sendForce
 * global_name:  tDataqueue_eDataqueue_sendForce
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_receive
 * name:         eDataqueue_receive
 * global_name:  tDataqueue_eDataqueue_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_receive(CELLIDX idx, intptr_t* p_data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	/* printf( "DQ:read begin fd=%d. ", VAR_fd[0] ); */
	ercd = read( VAR_fd[0], p_data, sizeof( intptr_t ) );
	/* printf( "DQ:read done %02X\n", *p_data ); */
	if( ercd > 0 )         /* 必ず sizeof intptr_t 読み込めると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_receivePolling
 * name:         eDataqueue_receivePolling
 * global_name:  tDataqueue_eDataqueue_receivePolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = read( VAR_fd[0], p_data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 読み込めると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_receiveTimeout
 * name:         eDataqueue_receiveTimeout
 * global_name:  tDataqueue_eDataqueue_receiveTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, TMO timeout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = read( VAR_fd[0], p_data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 読み込めると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_initialize
 * name:         eDataqueue_initialize
 * global_name:  tDataqueue_eDataqueue_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_initialize(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int     filedes[2];

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	( ercd = pipe(VAR_fd) ) < 0 ? ercd = E_SYS : E_OK;

	printf( "Dataqueue initialized %d, %d\n", VAR_fd[0], VAR_fd[1] );
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eDataqueue_refer
 * name:         eDataqueue_refer
 * global_name:  tDataqueue_eDataqueue_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eDataqueue_refer(CELLIDX idx, T_RDTQ* pk_dataqueue_status)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	/* 何もしない */

	return(ercd);
}

/* #[<ENTRY_PORT>]# eiDataqueue
 * entry port: eiDataqueue
 * signature:  siDataqueue
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiDataqueue_sendPolling
 * name:         eiDataqueue_sendPolling
 * global_name:  tDataqueue_eiDataqueue_sendPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eiDataqueue_sendForce
 * name:         eiDataqueue_sendForce
 * global_name:  tDataqueue_eiDataqueue_sendForce
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	INITIALIZE(idx);
	ercd = write( VAR_fd[1], &data, sizeof( intptr_t ) );
	if( ercd > 0 )         /* 必ず sizeof intptr_t 書きこめると仮定 */
		ercd = E_OK;

	return(ercd);
}

