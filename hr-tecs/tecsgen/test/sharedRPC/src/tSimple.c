/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cCall  signature: sSample context: task
 *   ER             cCall_sayHello( int32_t times );
 *   ER             cCall_howAreYou( char_t* buf, int32_t len );
 *   ER             cCall_giftToYou( char_t* buf, int32_t len );
 *   ER             cCall_returnGiftFromYou( int16_t** buf, int32_t* len );
 * call port : cDataqueue  signature: sDataqueue context: task
 *   ER             cDataqueue_send( intptr_t data );
 *   ER             cDataqueue_sendPolling( intptr_t data );
 *   ER             cDataqueue_sendTimeout( intptr_t data, TMO timeout );
 *   ER             cDataqueue_sendForce( intptr_t data );
 *   ER             cDataqueue_receive( intptr_t* p_data );
 *   ER             cDataqueue_receivePolling( intptr_t* p_data );
 *   ER             cDataqueue_receiveTimeout( intptr_t* p_data, TMO timeout );
 *   ER             cDataqueue_initialize( );
 *   ER             cDataqueue_refer( T_RDTQ* pk_dataqueue_status );
 * allocator port for call port: cCall func: giftToYou param: buf
 *   ER             cCall_giftToYou_buf_alloc( int32_t size, void** p );
 *   ER             cCall_giftToYou_buf_dealloc( const void* ptr );
 * allocator port for call port: cCall func: returnGiftFromYou param: buf
 *   ER             cCall_returnGiftFromYou_buf_alloc( int32_t size, void** p );
 *   ER             cCall_returnGiftFromYou_buf_dealloc( const void* ptr );
 *
 * #[</PREAMBLE>]# */

#include "tSimple_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tSimple_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main(CELLIDX idx)
{
	char     buf[256];
	char_t   *allocbuf;
	int16_t  *allocbuf2;
	int32_t  i, len;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	if( is_cDataqueue_joined() )
		cDataqueue_initialize();
	else
		sleep(1);

#define N_HELLO 3
	printf( "Simple: Say hello %d times.\n", N_HELLO );
	cCall_sayHello( N_HELLO );            /* 呼び口 cCall の sayHello を呼び出す */

	printf( "Simple: How are you?\n" );
	printf( "tSimple: buf addr: %08x, size: %d\n", buf, sizeof buf );
	cCall_howAreYou( buf, sizeof buf );   /* 呼び口 cCall の howAreYou を呼び出す */
	printf( "returned\n" );
	puts( buf );

#define GIFT_LEN   256
	cCall_giftToYou_buf_alloc( GIFT_LEN, (void **)&allocbuf );
	strcpy( allocbuf, "Good Luck!!" );
	cCall_giftToYou( allocbuf, GIFT_LEN );

	cCall_returnGiftFromYou( &allocbuf2, &len );
	printf( "return gift len: %d\n", len );
	for( i = 0; i < len; i++ ){
		printf( "%04x ", allocbuf2[i] );
		if( i % 8 == 7 )
			putchar( '\n' );
	}
	cCall_returnGiftFromYou_buf_dealloc( (void *)allocbuf2 );

#define ONEWAY_LEN  25
	for( i = 0; i < ONEWAY_LEN; i++ )
		buf[i] = ( ( i % 8 ) + 1 );
	cCall_oneway( buf, ONEWAY_LEN );

	cCall_sayHello( 1 );            /* 呼び口 cCall の sayHello を呼び出す */

	/* サーバータスクを停止させる */
	if( is_cDataqueue_joined() ){
		sleep(2);
		cCall_shutdown();
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
