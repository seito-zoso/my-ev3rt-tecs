/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCall signature: sSample context:task 
 *   ER             cCall_sayHello( int32_t times );
 *   ER             cCall_howAreYou( char_t* buf, int32_t len );
 *   ER             cCall_giftToYou( char_t* buf, int32_t len );
 *   ER             cCall_returnGiftFromYou( int16_t** buf, int32_t* len );
 *   ER             cCall_transferStruct( const struct stA * a, int32_t len );
 *   ER             cCall_transferStruct2( struct stA  a );
 *   ER             cCall_transferInArray( int8_t array0[8] );
 *   ER             cCall_transferInArray2( const int8_t(* array1)[8] );
 *   ER             cCall_transferOutArray( int8_t(* array2)[8] );
 *   unsigned char  cCall_UnsignedTypes( uint8_t in, unsigned short s, uint_t ui, ulong_t ul );
 *   char           cCall_SignedTypes( int8_t in, short s, int_t ui, long_t ul );
 *   ER             cCall_onewayFunc( char_t* buf, int32_t len );
 *   void           cCall_exit( );
 * require port: signature:sKernel context:task
 *   ER             delay( RELTIM delay_time );
 *   ER             exitTask( );
 *   ER             getTime( SYSTIM* p_system_time );
 *   ER             getMicroTime( SYSUTM* p_system_micro_time );
 *   ER             exitKernel( );
 * allocator port for call port:cCall func:giftToYou param: buf
 *   ER             cCall_giftToYou_buf_alloc( int32_t size, void** p );
 *   ER             cCall_giftToYou_buf_dealloc( const void* ptr );
 * allocator port for call port:cCall func:returnGiftFromYou param: buf
 *   ER             cCall_returnGiftFromYou_buf_alloc( int32_t size, void** p );
 *   ER             cCall_returnGiftFromYou_buf_dealloc( const void* ptr );
 * allocator port for call port:cCall func:onewayFunc param: buf
 *   ER             cCall_onewayFunc_buf_alloc( int32_t size, void** p );
 *   ER             cCall_onewayFunc_buf_dealloc( const void* ptr );
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
eBody_main()
{
	char     buf[256];
	char_t   *allocbuf;
	int16_t  *allocbuf2;
	int32_t  i, len;

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

	{
		struct stA a[4];
		int  i;
		
		for( i = 0; i < 4; i++ ){
			a[i].a = i+1;
			a[i].b = (i+1)*(i+1);
			a[i].msg = "TransferStruct message";
			a[i].len = strlen( a[i].msg ) + 1;
		}
		cCall_transferStruct( a, 4 );
	}

	{
		int8_t	array0[ ArraySize ];
		for( i = 0; i < ArraySize; i++ )
			array0[i] = i * 2 + 1;
		cCall_transferInArray( array0 );
	}

	{
		int8_t	array1[ ArraySize ];
		for( i = 0; i < ArraySize; i++ )
			array1[i] = i * 2 + 1;
		cCall_transferInArray2( &array1 );
	}

	{
		int8_t	array2[ ArraySize ];
		cCall_transferOutArray( &array2 );
		for( i = 0; i < ArraySize; i++ )
			syslog( LOG_INFO, "array2[%d]=%d", i, array2[i] );
	}

	{
#define LEN_BUF 1024
#define LEN_INT (LEN_BUF / sizeof( int32_t ))

		void *p;
		int  i;

		printf( "oneway func\n" );
		cCall_onewayFunc_buf_alloc( LEN_BUF, &p );

		for( i = 0; i < LEN_INT; i++ ){
			((int32_t *)p)[i] = i;
		}

		cCall_onewayFunc( p, 1024 );
	}

	cCall_exit();

#define SLEEP (1)
	printf("sleeping %d second\n", SLEEP );
	sleep( SLEEP );
	printf("exiting\n" );

	exitKernel();
}

/* #[<ENTRY_PORT>]# eSimple
 * entry port: eSimple
 * signature:  sSimple
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSimple_onewayPtr
 * name:         eSimple_onewayPtr
 * global_name:  tSimple_eSimple_onewayPtr
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayPtr(const uint32_t* in)
{
	printf( "eSimple_onewayPtr: *in=%d\n", *in );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayArray
 * name:         eSimple_onewayArray
 * global_name:  tSimple_eSimple_onewayArray
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayArray(const uint32_t* in, int32_t len)
{
	int   i;
	printf( "eSimple_onewayArray: len=%d\n", len );
	for( i = 0; i < len; i++ ){
		printf( "%08x ", in[i] );
		if( i % 8 == 7 )
			putchar( '\n' );
	}
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayDoubleArray
 * name:         eSimple_onewayDoubleArray
 * global_name:  tSimple_eSimple_onewayDoubleArray
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayDoubleArray(const int32_t* in, int32_t len, const int32_t* in2, int32_t len2)
{
	int   i;
	printf( "eSimple_onewayDoubleArray: len=%d, len2=%d\n", len, len2 );
	printf( "eSimple_onewayDoubleArray: in1:\n" );

	for( i = 0; i < len; i++ ){
		printf( "%08x ", in[i] );
		if( i % 8 == 7 )
			putchar( '\n' );
	}
	printf( "eSimple_onewayDoubleArray: in2:\n" );
	for( i = 0; i < len2; i++ ){
		printf( "%08x ", in2[i] );
		if( i % 8 == 7 )
			putchar( '\n' );
	}
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayStringArray
 * name:         eSimple_onewayStringArray
 * global_name:  tSimple_eSimple_onewayStringArray
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayStringArray(const char_t** in, int32_t len)
{
	int32_t   i;
	for( i = 0; i < len; i++ )
		puts( in[i] );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayString
 * name:         eSimple_onewayString
 * global_name:  tSimple_eSimple_onewayString
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayString(const char_t* in, int32_t len)
{
	printf( "eSimple_onewayString: len=%d\n", len );
	puts( in );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayStruct
 * name:         eSimple_onewayStruct
 * global_name:  tSimple_eSimple_onewayStruct
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayStruct(const struct stA * a)
{
	printf( "eSimple_onewayStruct:\n" );
	printf( " a->a=%d, a->b=%d\n", a->a, a->b );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayStruct2
 * name:         eSimple_onewayStruct2
 * global_name:  tSimple_eSimple_onewayStruct2
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayStruct2(const struct stA * a, int32_t len)
{
	int  i;

	printf( "eSimple_onewayStruct2: len=%d\n", len );
	for( i = 0; i < len; i++ )
		printf( " a[%d].a=%d, a[%d].b=%d\n", i, a[i].a, i, a[i].b );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayInArray
 * name:         eSimple_onewayInArray
 * global_name:  tSimple_eSimple_onewayInArray
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayInArray(int8_t array0[8])
{
	int_t	i;
	syslog( LOG_INFO, "eSimple_onewayInArray" );
	for( i = 0; i < ArraySize; i ++ )
		syslog( LOG_INFO, "array0[%d]=%d", i, array0[i] );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayInArray2
 * name:         eSimple_onewayInArray2
 * global_name:  tSimple_eSimple_onewayInArray2
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayInArray2(const int8_t(* array1)[8])
{
	int_t	i;
	syslog( LOG_INFO, "eSimple_onewayInArray2" );
	for( i = 0; i < ArraySize; i ++ )
		syslog( LOG_INFO, "array1[%d]=%d", i, (*array1)[i] );
	return	E_OK;
}

/* #[<ENTRY_FUNC>]# eSimple_onewayNulable
 * name:         eSimple_onewayNulable
 * global_name:  tSimple_eSimple_onewayNulable
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eSimple_onewayNulable(const int8_t(* array)[3])
{
	if( array ){
		printf( "eSimple_onewayNulable array[3]={ %d, %d, %d }\n", (*array)[0], (*array)[1], (*array)[2] );
	} else {
		printf( "eSimple_onewayNulable array=NULL\n" );
	}
}

/* #[<ENTRY_FUNC>]# eSimple_exit
 * name:         eSimple_exit
 * global_name:  tSimple_eSimple_exit
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
void
eSimple_exit()
{
	pthread_exit(0);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
