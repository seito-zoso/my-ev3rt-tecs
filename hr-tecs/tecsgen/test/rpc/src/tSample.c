/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cSimple  signature: sSimple context: task
 *   ER             cSimple_onewayPtr( const uint32_t* in );
 *   ER             cSimple_onewayArray( const uint32_t* in, int32_t len );
 *   ER             cSimple_onewayDoubleArray( const int32_t* in, int32_t len, const int32_t* in2, int32_t len2 );
 *   ER             cSimple_onewayStringArray( const char_t** in, int32_t len );
 *   ER             cSimple_onewayString( const char_t* in, int32_t len );
 *   ER             cSimple_onewayStruct( const struct stA * a );
 *   ER             cSimple_onewayStruct2( const struct stA * a, int32_t len );
 *   ER             cSimple_onewayInArray( int8_t array0[8] );
 *   ER             cSimple_onewayInArray2( const int8_t(* array1)[8] );
 *   void           cSimple_exit( );
 * allocator port for call port: eEnt func: giftToYou param: buf
 *   ER             eEnt_giftToYou_buf_alloc( int32_t size, void** p );
 *   ER             eEnt_giftToYou_buf_dealloc( const void* ptr );
 * allocator port for call port: eEnt func: returnGiftFromYou param: buf
 *   ER             eEnt_returnGiftFromYou_buf_alloc( int32_t size, void** p );
 *   ER             eEnt_returnGiftFromYou_buf_dealloc( const void* ptr );
 * allocator port for call port: eEnt func: onewayFunc param: buf
 *   ER             eEnt_onewayFunc_buf_alloc( int32_t size, void** p );
 *   ER             eEnt_onewayFunc_buf_dealloc( const void* ptr );
 *
 * #[</PREAMBLE>]# */

#include "tSample_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSample
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_sayHello
 * name:         eEnt_sayHello
 * global_name:  tSample_eEnt_sayHello
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_sayHello(CELLIDX idx, int32_t times)
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
	printf( "Sample: " );
	while( times-- > 0 )
		printf( "hello " );
	printf( "\n" );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_howAreYou
 * name:         eEnt_howAreYou
 * global_name:  tSample_eEnt_howAreYou
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_howAreYou(CELLIDX idx, char_t* buf, int32_t len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	printf( "tSample: buf addr: %08x, size: %d\n", buf, len );
	/* ここに処理本体を記述します */
	strncpy( buf, "Sample: I'm fine!", len );

	return(ercd);
}


/* #[<ENTRY_FUNC>]# eEnt_giftToYou
 * name:         eEnt_giftToYou
 * global_name:  tSample_eEnt_giftToYou
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_giftToYou(CELLIDX idx, char_t* buf, int32_t len)
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

	printf( "tSample: Gift: %s\n", buf );

	eEnt_giftToYou_buf_dealloc( buf );
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_returnGiftFromYou
 * name:         eEnt_returnGiftFromYou
 * global_name:  tSample_eEnt_returnGiftFromYou
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_returnGiftFromYou(CELLIDX idx, int16_t** buf, int32_t* len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int16_t *allocbuf;

	int_t   i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
#define GIFT_LEN 512
	eEnt_returnGiftFromYou_buf_alloc( GIFT_LEN * sizeof(int16_t), (void **)&allocbuf );
	for( i = 0; i < GIFT_LEN; i++ )
		allocbuf[i] = i;

	*buf = allocbuf;
	*len = GIFT_LEN;
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_transferStruct
 * name:         eEnt_transferStruct
 * global_name:  tSample_eEnt_transferStruct
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_transferStruct(CELLIDX idx, const struct stA * a, int32_t len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int32_t i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */

	printf( "transferStruct: len=%d\n", len );
	for( i = 0; i < len; i++ ){
		printf( "i=%d a=%d, b=%d\n", i, a[i].a, a[i].b );
		printf( "len=%d msg=%s\n", a[i].len, a[i].msg );
	}

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_transferStruct2
 * name:         eEnt_transferStruct2
 * global_name:  tSample_eEnt_transferStruct2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_transferStruct2(CELLIDX idx, struct stA  a)
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

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_transferInArray
 * name:         eEnt_transferInArray
 * global_name:  tSample_eEnt_transferInArray
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_transferInArray(CELLIDX idx, int8_t array0[ArraySize])
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int_t	i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	syslog( LOG_INFO, "eEnt_transferInArray" );
	for( i = 0; i < ArraySize; i ++ )
		syslog( LOG_INFO, "array0[%d]=%d", i, array0[i] );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_transferInArray2
 * name:         eEnt_transferInArray2
 * global_name:  tSample_eEnt_transferInArray2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_transferInArray2(CELLIDX idx, const int8_t(* array1)[ArraySize])
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int_t	i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	syslog( LOG_INFO, "eEnt_transferInArray2" );
	for( i = 0; i < ArraySize; i ++ )
		syslog( LOG_INFO, "(*array1)[%d]=%d", i, (*array1)[i] );

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_transferOutArray
 * name:         eEnt_transferOutArray
 * global_name:  tSample_eEnt_transferOutArray
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEnt_transferOutArray(CELLIDX idx, int8_t(* array2)[ArraySize])
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	int_t	i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	}

	/* ここに処理本体を記述します #_TEFB_# */
	syslog( LOG_INFO, "eEnt_transferOutArray" );
	for( i = 0; i < ArraySize; i ++ )
		(*array2)[i] = ArraySize - i;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eEnt_UnsignedTypes
 * name:         eEnt_UnsignedTypes
 * global_name:  tSample_eEnt_UnsignedTypes
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
unsigned char
eEnt_UnsignedTypes(CELLIDX idx, uint8_t in, unsigned short s, uint_t ui, ulong_t ul)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eEnt_SignedTypes
 * name:         eEnt_SignedTypes
 * global_name:  tSample_eEnt_SignedTypes
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
char
eEnt_SignedTypes(CELLIDX idx, int8_t in, short s, int_t ui, long_t ul)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eEnt_onewayFunc
 * name:         eEnt_onewayFunc
 * global_name:  tSample_eEnt_onewayFunc
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eEnt_onewayFunc(CELLIDX idx, char_t* buf, int32_t len)
{
	CELLCB	*p_cellcb;
	int     i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* oneway の場合 E_OK しか返せません */
		return(E_OK);
	}

	printf( "onewayFunc: len=%d\n", len );
	/* ここに処理本体を記述します #_TEFB_# */
	for( i = 0; i < len; i++ ){
		if( i % 8 == 0 )
			printf( "%d: ", i );
		printf( "%02X ", (uint8_t)buf[i] );
		if( i % 8 == 7 )
			printf( "\n" );
	}
	eEnt_onewayFunc_buf_dealloc( buf );

	{
		int32_t  in, i;
#define BUF_LEN   8
#define BUF_LEN2  4
		int32_t  buf[BUF_LEN];
		int32_t  buf2[BUF_LEN2];

		in = 999;
		cSimple_onewayPtr( &in );

		for( i = 0; i < BUF_LEN; i++ )
			buf[i]= (i+1)*2;
		cSimple_onewayArray( buf, BUF_LEN );

		for( i = 0; i < BUF_LEN; i++ )
			buf[i]= (i+1)*2;
		for( i = 0; i < BUF_LEN2; i++ )
			buf2[i]= (i+2)*3;
		cSimple_onewayDoubleArray( buf, BUF_LEN, buf2, BUF_LEN2 );
	}

	{
#define MSG_LEN  5
		static const char_t  *msg[MSG_LEN] = { "I", "am", "a", "software", "engineer" };
		cSimple_onewayStringArray( msg, MSG_LEN );
	}


#define MESSAGE "Hello TECS !"
	cSimple_onewayString( MESSAGE, sizeof( MESSAGE ) );

	{
		struct stA stA;

		stA.a = 999;
		stA.b = 1001;
		stA.msg = "This is onewayStruct message.";
		stA.len = strlen( stA.msg ) + 1;

		cSimple_onewayStruct( &stA );
	}

	{
#define  LEN  5
		struct stA stA[LEN];
		int32_t  len = LEN;

		for( i = 0; i < LEN; i++ ){
			stA[i].a = 999  + i;
			stA[i].b = 2001 + i * 2;
			stA[i].msg = "This is onewayStruct2 message.";
			stA[i].len = strlen( stA[i].msg ) + 1;
		}
		cSimple_onewayStruct2( stA, len );
	}

	{
		int8_t	array0[ ArraySize ];
		for( i = 0; i < ArraySize; i++ )
			array0[i] = i * 2 + 1;
		cSimple_onewayInArray( array0 );
	}

	{
		int8_t	array1[ ArraySize ];
		for( i = 0; i < ArraySize; i++ )
			array1[i] = i * 2 + 1;
		cSimple_onewayInArray2( array1 );  /* mikan compile 時の警告が消せない */
	}

	{
		int8_t	array[3];
		array[0] = 1; array[1] = 2; array[2] = 3;
		cSimple_onewayNulable( array );
		cSimple_onewayNulable( NULL );
	}

	cSimple_exit( );
	printf( "tSample: onewayFunc: reach end!!!!\n" );

	/* oneway の場合 E_OK しか返せません */
	return(E_OK);
}

/* #[<ENTRY_FUNC>]# eEnt_exit
 * name:         eEnt_exit
 * global_name:  tSample_eEnt_exit
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
void
eEnt_exit(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
	pthread_exit(0);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
