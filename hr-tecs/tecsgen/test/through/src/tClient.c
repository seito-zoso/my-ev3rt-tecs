/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * call port function #_TCPF_#
 * call port: cCall signature: sSignature context:task 
 *   ER             cCall_func1( int32_t inval );
 *   ER             cCall_func2( int32_t* outval );
 *   ER             cCall_func3( struct tag  stval );
 *   ER             cCall_func4( stTag stval, INT inval );
 *   ER             cCall_func5( stTag* stval, INT inval );
 *   ER             cCall_func6( int8_t* buf, int32_t sz );
 *   ER             cCall_func7( int8_t** buf, int32_t* sz );
 *   ER             cCall_func10( const stTag* stval, int16_t a );
 * call port: cCall2 signature: sSignature context:task 
 *   ER             cCall2_func1( subscript, int32_t inval );
 *   ER             cCall2_func2( subscript, int32_t* outval );
 *   ER             cCall2_func3( subscript, struct tag  stval );
 *   ER             cCall2_func4( subscript, stTag stval, INT inval );
 *   ER             cCall2_func5( subscript, stTag* stval, INT inval );
 *   ER             cCall2_func6( subscript, int8_t* buf, int32_t sz );
 *   ER             cCall2_func7( subscript, int8_t** buf, int32_t* sz );
 *   ER             cCall2_func10( subscript, const stTag* stval, int16_t a );
 *       subscript:  0...(NCP_cCall2-1)
 * allocator port for call port:cCall func:func6 param: buf
 *   ER             cCall_func6_buf_alloc( int32_t sz, void** ptr );
 *   ER             cCall_func6_buf_dealloc( const void* ptr );
 * allocator port for call port:cCall func:func7 param: buf
 *   ER             cCall_func7_buf_alloc( int32_t sz, void** ptr );
 *   ER             cCall_func7_buf_dealloc( const void* ptr );
 * allocator port for call port:cCall2 func:func6 param: buf
 *   ER             cCall2_func6_buf_alloc( subscript, int32_t sz, void** ptr );
 *   ER             cCall2_func6_buf_dealloc( subscript, const void* ptr );
 *       subscript:  0...(NCP_cCall2_func6_buf-1)
 * allocator port for call port:cCall2 func:func7 param: buf
 *   ER             cCall2_func7_buf_alloc( subscript, int32_t sz, void** ptr );
 *   ER             cCall2_func7_buf_dealloc( subscript, const void* ptr );
 *       subscript:  0...(NCP_cCall2_func7_buf-1)
 *
 * #[</PREAMBLE>]# */

#include "tClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sMain
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tClient_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMain_main(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	struct  tag stval;
	int32_t  sz;
	int8_t   *buf;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します */
	int32_t val = 30;
	cCall_func1( val );

	val = 15;
	cCall_func2( &val );

	stval.member = 200;
	cCall_func3( stval );  

	stval.member = 200;
	cCall_func4( stval, val );

	stval.member = 200;
	cCall_func5( &stval, val );

#define STR_HELLO "hello func6"
	sz = 6;
	cCall_func6_buf_alloc( sz, (void **)&buf );
	memcpy( buf, STR_HELLO, sizeof( STR_HELLO ) );
	cCall_func6( buf, sz );

	cCall_func7( &buf, &sz );
	puts( buf );
	cCall_func7_buf_dealloc( buf );

	cCall_func10( NULL, 1 );

	cCall2_func1( 0, 11 );
	return (ercd);
}
/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
