#include <stdio.h>
#include "kernel.h"
#include "t_syslog.h"
#include "tServer_tecsgen.h"


/* 属性アクセスマクロ */
/*
 * dummy            int32_t          ATTR_dummy      
 */

/* 呼び口関数 */
/*
 * 呼び口関数 #_TCPF_#
 * allocator port for call port: eEntry func: func9 param: message
 *   void*          eEntry_func9_message_alloc( int32_t size );
 *   ER             eEntry_func9_message_dealloc( const void* ptr );
 */

/* 受け口関数 */
/*
 * entry port: eEntry
 * signature:  sSignature
 */
/*
 * name:         eEntry_func1
 * global_name:  tServer_eEntry_func1
 */
ER             eEntry_func1( tServer_IDX idx, int32_t inval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }

	syslog(LOG_NOTICE, "tServer eEntry func1 inval=%d", inval );
    return ercd_;
}

/*
 * name:         eEntry_func2
 * global_name:  tServer_eEntry_func2
 */
ER             eEntry_func2( tServer_IDX idx, int32_t* outval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
	*outval = 88;
	syslog(LOG_NOTICE, "tServer eEntry func2 *outval=%d", *outval );
    return ercd_;
}

/*
 * name:         eEntry_func3
 * global_name:  tServer_eEntry_func3
 */
ER             eEntry_func3( tServer_IDX idx,  struct tag  stval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
	syslog(LOG_NOTICE, "tServer eEntry func3 stval.member=%d", stval.member );
    return ercd_;
}

/*
 * name:         eEntry_func4
 * global_name:  tServer_eEntry_func4
 */
ER             eEntry_func4( tServer_IDX idx, stTag stval, int_t inval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
	syslog(LOG_NOTICE, "tServer eEntry func4 stval.member=%d  inval=%d", stval.member, inval );
    return ercd_;
}

/*
 * name:         eEntry_func50
 * global_name:  tServer_eEntry_func50
 */
ER             eEntry_func50( tServer_IDX idx, int32_t* ioval, int_t inval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
	syslog(LOG_NOTICE, "tServer eEntry func5 *ioval=%d  inval=%d", *ioval, inval );
	*ioval = 1000;
    return ercd_;
}


/*
 * name:         eEntry_func5
 * global_name:  tServer_eEntry_func5
 */
ER             eEntry_func5( tServer_IDX idx, stTag* stval, int_t inval)
{
    ER       ercd_ = E_OK;
    tServer_CB *p_cellcb;
    if( tServer_VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
    }else{
        return E_ID;
    }
    return ercd_;
}


/* #[<ENTRY_FUNC>]# eEntry_func1way
 * name:         eEntry_func1way
 * global_name:  tServer_eEntry_func1way
 * #[/ENTRY_FUNC>]# */
ER
eEntry_func1way(CELLIDX idx, int32_t inval)
{
	CELLCB	*p_cellcb;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* oneway の場合 E_OK しか返せません */
		return(E_OK);
	}

	syslog(LOG_NOTICE, "tServer eEntry func1way inval=%d", inval );
	/* ここに処理本体を記述します */

	/* oneway の場合 E_OK しか返せません */
	return(E_OK);
}

/* #[<ENTRY_FUNC>]# eEntry_func7
 * name:         eEntry_func7
 * global_name:  tServer_eEntry_func7
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eEntry_func7(CELLIDX idx, const int32_t* array, int32_t sz)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int     i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	syslog(LOG_NOTICE, "func7: sz = %d", sz );
	for( i = 0; i < sz; i++ ){
		syslog(LOG_NOTICE, " array[%d] = %d", i, array[i] );
	}

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func8
 * name:         eEntry_func8
 * global_name:  tServer_eEntry_func8
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eEntry_func8(CELLIDX idx, const char_t* message)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	syslog(LOG_NOTICE, "func8: message = %s", message );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEntry_func9
 * name:         eEntry_func9
 * global_name:  tServer_eEntry_func9
 * oneway:       
 * #[/ENTRY_FUNC>]# */
ER
eEntry_func9(CELLIDX idx, char_t* message)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	syslog(LOG_NOTICE, "func9" );
	syslog(LOG_NOTICE, message );
	eEntry_func9_message_dealloc(message);
	return(ercd);
}

