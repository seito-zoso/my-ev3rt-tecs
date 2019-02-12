/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * require port : signature: sSysLog context: task
 *   ER             write( uint_t prio, const SYSLOG* p_syslog );
 *   ER_UINT        read( SYSLOG* p_syslog );
 *   ER             mask( uint_t logmask, uint_t lowmask );
 *   ER             refer( T_SYSLOG_RLOG* pk_rlog );
 * call port : cCall  signature: sSimple context: task
 *   void           cCall_shutdown( );
 *   ER             cCall_func1( int32_t inval );
 *   ER             cCall_func2( const char_t* str );
 *   ER             cCall_func3( const char_t* msg, int32_t len );
 *   ER             cCall_func4( const char_t** msg, int32_t len );
 *   ER             cCall_func5( const STA** sta, int32_t len );
 *   ER             cCall_func6( const int8_t array[8] );
 *   ER             cCall_func7( const int8_t array2[8][4] );
 *   ER             cCall_func8( const STA arraySt[2] );
 *   ER             cCall_func9( const STA* arraySt[2] );
 *   ER             cCall_func10( int32_t* val );
 *   ER             cCall_func11( char_t* msg, int32_t len );
 *   ER             cCall_func12( char_t** msg );
 *   ER             cCall_func13( STB* sta, int32_t len );
 *   ER             cCall_func14( STB** sta, int32_t len );
 *   ER             cCall_func15( int8_t(* array1)[8] );
 *   ER             cCall_func40( int32_t* val );
 *   ER             cCall_func41( char_t* msg, int32_t len );
 *   ER             cCall_func42( char_t** msg );
 *   ER             cCall_func43( STA* sta, int32_t len );
 *   ER             cCall_func21( int32_t* a );
 *   ER             cCall_func22( STA* sta );
 *   ER             cCall_func23( char_t* str );
 *   ER             cCall_func24( char_t* msg, int32_t len );
 *   ER             cCall_func25( char_t** msg, int32_t len );
 *   ER             cCall_func26( STA** sta, int32_t len );
 *   ER             cCall_func27( int8_t(* array2)[8] );
 *   ER             cCall_func31( int32_t** a );
 *   ER             cCall_func32( STA** sta );
 *   ER             cCall_func33( char_t** str );
 *   ER             cCall_func34( char_t** msg, int32_t* len );
 *   ER             cCall_func35( char_t*** msg, int32_t* len, int32_t* msglen );
 *   ER             cCall_func36( STA** sta, int32_t* len );
 *   ER             cCall_func37( STA*** sta, int32_t* len );
 *   ER             cCall_func38( int8_t(** array2)[8] );
 *   ER             cCall_func39( STA*(** arraySt)[2] );
 * call port : cOpener  signature: sSocketClientOpener context: task
 *   ER             cOpener_open( const char_t* serverAddr, uint16_t portNo, TMO tmo );
 *   ER             cOpener_close( TMO tmo );
 * allocator port for call port: cCall func: func21 param: a
 *   ER             cCall_func21_a_alloc( int32_t size, void** ptr );
 *   ER             cCall_func21_a_dealloc( const void* ptr );
 *   ER             cCall_func21_a_printStatistics( );
 * allocator port for call port: cCall func: func22 param: sta
 *   ER             cCall_func22_sta_alloc( int32_t size, void** ptr );
 *   ER             cCall_func22_sta_dealloc( const void* ptr );
 *   ER             cCall_func22_sta_printStatistics( );
 * allocator port for call port: cCall func: func23 param: str
 *   ER             cCall_func23_str_alloc( int32_t size, void** ptr );
 *   ER             cCall_func23_str_dealloc( const void* ptr );
 *   ER             cCall_func23_str_printStatistics( );
 * allocator port for call port: cCall func: func24 param: msg
 *   ER             cCall_func24_msg_alloc( int32_t size, void** ptr );
 *   ER             cCall_func24_msg_dealloc( const void* ptr );
 *   ER             cCall_func24_msg_printStatistics( );
 * allocator port for call port: cCall func: func25 param: msg
 *   ER             cCall_func25_msg_alloc( int32_t size, void** ptr );
 *   ER             cCall_func25_msg_dealloc( const void* ptr );
 *   ER             cCall_func25_msg_printStatistics( );
 * allocator port for call port: cCall func: func26 param: sta
 *   ER             cCall_func26_sta_alloc( int32_t size, void** ptr );
 *   ER             cCall_func26_sta_dealloc( const void* ptr );
 *   ER             cCall_func26_sta_printStatistics( );
 * allocator port for call port: cCall func: func27 param: array2
 *   ER             cCall_func27_array2_alloc( int32_t size, void** ptr );
 *   ER             cCall_func27_array2_dealloc( const void* ptr );
 *   ER             cCall_func27_array2_printStatistics( );
 * allocator port for call port: cCall func: func31 param: a
 *   ER             cCall_func31_a_alloc( int32_t size, void** ptr );
 *   ER             cCall_func31_a_dealloc( const void* ptr );
 *   ER             cCall_func31_a_printStatistics( );
 * allocator port for call port: cCall func: func32 param: sta
 *   ER             cCall_func32_sta_alloc( int32_t size, void** ptr );
 *   ER             cCall_func32_sta_dealloc( const void* ptr );
 *   ER             cCall_func32_sta_printStatistics( );
 * allocator port for call port: cCall func: func33 param: str
 *   ER             cCall_func33_str_alloc( int32_t size, void** ptr );
 *   ER             cCall_func33_str_dealloc( const void* ptr );
 *   ER             cCall_func33_str_printStatistics( );
 * allocator port for call port: cCall func: func34 param: msg
 *   ER             cCall_func34_msg_alloc( int32_t size, void** ptr );
 *   ER             cCall_func34_msg_dealloc( const void* ptr );
 *   ER             cCall_func34_msg_printStatistics( );
 * allocator port for call port: cCall func: func35 param: msg
 *   ER             cCall_func35_msg_alloc( int32_t size, void** ptr );
 *   ER             cCall_func35_msg_dealloc( const void* ptr );
 *   ER             cCall_func35_msg_printStatistics( );
 * allocator port for call port: cCall func: func36 param: sta
 *   ER             cCall_func36_sta_alloc( int32_t size, void** ptr );
 *   ER             cCall_func36_sta_dealloc( const void* ptr );
 *   ER             cCall_func36_sta_printStatistics( );
 * allocator port for call port: cCall func: func37 param: sta
 *   ER             cCall_func37_sta_alloc( int32_t size, void** ptr );
 *   ER             cCall_func37_sta_dealloc( const void* ptr );
 *   ER             cCall_func37_sta_printStatistics( );
 * allocator port for call port: cCall func: func38 param: array2
 *   ER             cCall_func38_array2_alloc( int32_t size, void** ptr );
 *   ER             cCall_func38_array2_dealloc( const void* ptr );
 *   ER             cCall_func38_array2_printStatistics( );
 * allocator port for call port: cCall func: func39 param: arraySt
 *   ER             cCall_func39_arraySt_alloc( int32_t size, void** ptr );
 *   ER             cCall_func39_arraySt_dealloc( const void* ptr );
 *   ER             cCall_func39_arraySt_printStatistics( );
 *
 * #[</PREAMBLE>]# */

#include "tSimpleClient_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tSimpleClient_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	}

	/* ここに処理本体を記述します #_TEFB_# */
	char   buf[256];

	syslog( LOG_INFO, "SimpleClient: opening Channel" );
	cOpener_open("127.0.0.1", 8931, TMO_FEVR );
	// cOpener_open("192.168.99.2", 8931, TMO_FEVR );

	cSampleTask_activate();

	syslog( LOG_INFO, "SimpleClient: cCall_func1" );
	cCall_func1( 10 );

	syslog( LOG_INFO, "SimpleClient: cCall_func2" );
	cCall_func2( "hello" );

#define FUNC3_MSG  "message for func3"
	syslog( LOG_INFO, "SimpleClient: cCall_func3" );
	cCall_func3( FUNC3_MSG, sizeof FUNC3_MSG );

	{
#define MSG_LEN  5
		const char_t  *msg[MSG_LEN] = { "this", "is", "a", "pen", "." };
		syslog( LOG_INFO, "SimpleClient: cCall_func4" );
		cCall_func4( msg, MSG_LEN );
	}

	{
#define STA_LEN2	2
		STA			sta[STA_LEN2] = { { 11, 121 }, { 13, 169 } };
		STA			*psta[STA_LEN2];
		char_t		*msg0 = "hello!! func5-0";
		char_t		*msg1 = "hello!! func5-1";
		psta[0] = &sta[0];
		psta[1] = &sta[1];
		psta[0]->msg = msg0;
		psta[0]->len = psta[0]->count = strlen( msg0 ) + 1;
		psta[1]->msg = msg1;
		psta[1]->len = psta[1]->count = strlen( msg1 ) + 1;
		syslog( LOG_INFO, "SimpleClient: cCall_func5" );
		cCall_func5( &psta[0], STA_LEN2 );
	}

	{
		int8_t	array[ ArraySize ];
		int_t	i;
		for( i = 0; i < ArraySize; i++ )
			array[i] = i*i*i;
		cCall_func6( array );
	}

	{
		int8_t	array[ ArraySize ][ ArraySize2 ];
		int_t	i, j;
		for( i = 0; i < ArraySize; i++ )
			for( j = 0; j < ArraySize2; j++ )
				array[i][j] = i*10+j;
		cCall_func7( array );
	}

	{
		STA			sta[ArraySizeSTA] = { { 11, 121 }, { 13, 169 } };
		char_t		*msg0 = "hello!! func8-0";
		char_t		*msg1 = "hello!! func8-1";
		sta[0].msg = msg0;
		sta[0].len = sta[0].count = strlen( msg0 ) + 1;
		sta[1].msg = msg1;
		sta[1].len = sta[1].count = strlen( msg1 ) + 1;
		syslog( LOG_INFO, "SimpleClient: cCall_func8" );
		cCall_func8( sta );
	}

	{
		STA			sta[ArraySizeSTA] = { { 14, 196 }, { 17, 289 } };
		STA			*psta[ArraySizeSTA];
		char_t		*msg0 = "hello!! func9-0";
		char_t		*msg1 = "hello!! func9-1";
		psta[0] = &sta[0];
		psta[1] = &sta[1];
		psta[0]->msg = msg0;
		psta[0]->len = psta[0]->count = strlen( msg0 ) + 1;
		psta[1]->msg = msg1;
		psta[1]->len = psta[1]->count = strlen( msg1 ) + 1;
		syslog( LOG_INFO, "SimpleClient: cCall_func9" );
		cCall_func9( psta );
	}

	{
		int32_t  val;
		syslog( LOG_INFO, "SimpleClient: cCall_func10" );
		cCall_func10( &val );
		syslog( LOG_INFO, "  val = %d", val );
	}

	{
#define MSG_LEN11  32
		char_t  msg[MSG_LEN11];
		syslog( LOG_INFO, "SimpleClient: cCall_func11" );
		cCall_func11( msg, MSG_LEN11 );
		syslog( LOG_INFO, msg );
	}

	{
#define	N_BUF	8
#define	BUF_LEN	32
		char_t  *buf[N_BUF];
		char_t  buf2[N_BUF][BUF_LEN+1];
		int32_t i;

		for( i = 0; i < N_BUF; i++ )
			buf[i] = buf2[i];

		syslog( LOG_INFO, "SimpleClient: cCall_func12" );
		cCall_func12( buf );
		for( i = 0; i < N_BUF; i++ ){
			// Too long string chop
			buf[i][BUF_LEN-1] = '\0';
			syslog( LOG_INFO, "  str[%d] = %s", i, buf[i] );
		}
	}

	{
#define STA_LEN 2
		STB     sta[STA_LEN];
		int32_t i;

		syslog( LOG_INFO, "SimpleClient: cCall_func13" );
		cCall_func13( sta, STA_LEN );
		for( i = 0; i < STA_LEN; i++ ){
			syslog( LOG_INFO, "  sta[%d].a = %d", i, sta[i].a );
			syslog( LOG_INFO, "  sta[%d].b = %d", i, sta[i].b );
		}
	}

	{
#define STA_LEN3	3
		STB     sta[STA_LEN3];
		STB     *psta[STA_LEN3];
		int32_t i;

		for( i = 0; i < STA_LEN3; i++ )
			psta[i] = &sta[i];
		syslog( LOG_INFO, "SimpleClient: cCall_func14" );
		cCall_func14( psta, STA_LEN3 );
		for( i = 0; i < STA_LEN3; i++ ){
			syslog( LOG_INFO, "  sta[%d]->a = %d", i, sta[i].a );
			syslog( LOG_INFO, "  sta[%d]->b = %d", i, sta[i].b );
		}
	}

	{
		int8_t	array1[ ArraySize ];
		int_t	i;
		syslog( LOG_INFO, "SimpleClient: cCall_func15" );
		cCall_func15( &array1 );
		for( i = 0; i < ArraySize; i++ )
			syslog( LOG_INFO, " array[%d]=%d", i, array1[i] );
	}

	{
#define	IN_VAL  1414213
		int32_t  val = IN_VAL;
		syslog( LOG_INFO, "SimpleClient: cCall_func40" );
		cCall_func40( &val );
		syslog( LOG_INFO, "  val = in:%d/out:%d", IN_VAL, val );
	}

	{
		char_t		msg[32] = "This is func41 in message.\0";
		int32_t		len = sizeof msg;
		syslog( LOG_INFO, "SimpleClient: cCall_func41" );
		cCall_func41( msg, len );
		syslog( LOG_INFO, msg );
	}

	{
		char_t		*msg[8], MSG[8][32];
		int32_t		i, len = 8;
		for( i = 0; i < len; i++ )
			msg[i]=MSG[i];

		syslog( LOG_INFO, "SimpleClient: cCall_func42" );
		cCall_func42( msg );

		for( i = 0; i < len; i++ )
			syslog( LOG_INFO, msg[i] );
	}

	{
#define N_STA		4
#define STA_MSG_LEN	32
		STA			*sta[N_STA], STA[N_STA];
		char_t		msg[N_STA][STA_MSG_LEN];
		const char_t *MSG[ N_STA ] = { "Hello everyone.", "Have a nice day.", "Good luck!", "It's fine tody." };
		int32_t		i, len = N_STA;
		for( i = 0; i < len; i++ ){
			sta[i] = &STA[i];
			sta[i]->a = 5 * (i+1);
			sta[i]->b = 3 * (i+1);
			sta[i]->msg = msg[i];
			strncpy( msg[i], MSG[i], STA_MSG_LEN );
			sta[i]->len = STA_MSG_LEN;
			sta[i]->count = strlen( msg[i] ) + 1;
		};

		syslog( LOG_INFO, "SimpleClient: cCall_func43" );
		cCall_func43( STA, N_STA );

		for( i = 0; i < len; i++ )
			syslog( LOG_INFO, " sta[%d]->a=%d, sta[%d]->b=%d", i, sta[i]->a, i, sta[i]->b );
	}

	{
		int32_t size = sizeof( int32_t );
		int32_t *a;
		cCall_func21_a_alloc( size, (void**) &a );
		*a = 6954;

		syslog( LOG_INFO, "SimpleClient: cCall_func21" );
		cCall_func21( a );
	}

	{
		int32_t size = sizeof( STA );
		STA     *sta;

		cCall_func22_sta_alloc( size, (void**) &sta );
		sta->a = 88;
		sta->b = 64;
#define	FUNC22_MSG	"Hope your luck."
		cCall_func22_sta_alloc( sizeof( FUNC22_MSG ), (void**) &sta->msg );
		sta->len = sta->count = sizeof( FUNC22_MSG );
		strcpy( sta->msg, FUNC22_MSG );
		syslog( LOG_INFO, "SimpleClient: cCall_func22" );
		cCall_func22( sta );
	}

	{
		const char_t  *STR = "How do you feel ?";
		char_t		*str;

		cCall_func23_str_alloc( strlen( STR ) + 1, (void **)&str );
		strcpy( str, STR );

		syslog( LOG_INFO, "SimpleClient: cCall_func23" );
		cCall_func23( str );
	}

	{
		const char_t  *MSG = "I feel so nice.";
		char_t		*msg;

		cCall_func24_msg_alloc( strlen( MSG ) + 1, (void **)&msg );
		strcpy( msg, MSG );

		syslog( LOG_INFO, "SimpleClient: cCall_func24" );
		cCall_func24( msg, strlen( MSG ) + 1 );
	}

	{
		const char_t  *MSG[MSG_LEN] = { "I", "feel", "so", "nice", "." };
		char_t		**msg;
		int_t		i;

		cCall_func25_msg_alloc( MSG_LEN * sizeof(char_t*), (void **)&msg );
		for( i = 0; i < MSG_LEN; i++ ){
			cCall_func25_msg_alloc( strlen(MSG[i])+1, (void **)&(msg[i]) );
			strcpy( msg[i], MSG[i] );
		}

		syslog( LOG_INFO, "SimpleClient: cCall_func25" );
		cCall_func25( msg, MSG_LEN );
	}

	{
		STA		**sta;
		int_t	i;
#define	STA_LEN4	4
#define FUNC26_MSG	"We are very happy."
		cCall_func26_sta_alloc( STA_LEN4 * sizeof(STA *), (void **)&sta );
		for( i = 0; i < STA_LEN4; i++ ){
			cCall_func26_sta_alloc( sizeof( STA ), (void **)&(sta[i]) );
			cCall_func26_sta_alloc( sizeof FUNC26_MSG, (void **)&sta[i]->msg );
			sta[i]->a = 2 * ( i + 1 );
			sta[i]->b = 4 * ( i + 1 );
			sta[i]->len = sta[i]->count = sizeof FUNC26_MSG;
		}

		syslog( LOG_INFO, "SimpleClient: cCall_func26" );
		cCall_func26( sta, STA_LEN4 );
	}

	{
		int8_t	*array;
		int_t	i;

		cCall_func27_array2_alloc( sizeof( int8_t ) * ArraySize, (void **)&array );
		for( i = 0; i < ArraySize; i++ ){
			array[i] = 100+i;
		}

		syslog( LOG_INFO, "SimpleClient: cCall_func27" );
		cCall_func27( array );
	}

	{
		int32_t	*a;
		syslog( LOG_INFO, "SimpleClient: cCall_func31" );
		cCall_func31( &a );
		syslog( LOG_INFO, "   *a = %d", *a );
		CCALL_FUNC31_A_DEALLOC( a );
	}

	{
		STA     *sta;

		syslog( LOG_INFO, "SimpleClient: cCall_func32" );
		cCall_func32( &sta );
		syslog( LOG_INFO, "   sta->a = %d", sta->a );
		syslog( LOG_INFO, "   sta->b = %d", sta->b );

		CCALL_FUNC32_STA_DEALLOC( sta );
	}

	{
		char_t     *str;

		syslog( LOG_INFO, "SimpleClient: cCall_func33" );
		cCall_func33( &str );
		syslog( LOG_INFO, str );

		CCALL_FUNC33_STR_DEALLOC( str );
	}

	{
		char_t     *msg;
		int32_t    len;

		syslog( LOG_INFO, "SimpleClient: cCall_func34" );
		cCall_func34( &msg, &len );
		syslog( LOG_INFO, "  len = %d", len );
		syslog( LOG_INFO, msg );

		CCALL_FUNC34_MSG_DEALLOC( msg );
	}

	{
		char_t     **msg;
		int32_t    i, len, msglen;

		syslog( LOG_INFO, "SimpleClient: cCall_func35" );
		cCall_func35( &msg, &len, &msglen );
		syslog( LOG_INFO, "  len = %d", len );
		for( i = 0; i < len; i++ )
			syslog( LOG_INFO, msg[i] );

		CCALL_FUNC35_MSG_DEALLOC( msg, len );
	}

	{
		int32_t	i, len;
		STA		*sta;
		syslog( LOG_INFO, "SimpleClient: cCall_func36" );
		cCall_func36( &sta, &len );
		for( i = 0; i < len; i++ )
			syslog( LOG_INFO, "  sta[%d].a = %d, sta[%d].b = %d", i, sta[i].a, i, sta[i].b );

		CCALL_FUNC36_STA_DEALLOC( sta, len );
	}

	{
		int32_t	i, len;
		STA		**sta;
		syslog( LOG_INFO, "SimpleClient: cCall_func37" );
		cCall_func37( &sta, &len );
		for( i = 0; i < len; i++ )
			syslog( LOG_INFO, "  sta[%d]->a = %d, sta[%d]->b = %d", i, sta[i]->a, i, sta[i]->b );

		CCALL_FUNC37_STA_DEALLOC( sta, len );
	}

	{
		int32_t	i, len;
		STA		*(*arraySt)[ArraySizeSTA];
		syslog( LOG_INFO, "SimpleClient: cCall_func39" );
		cCall_func39( &arraySt );
		for( i = 0; i < ArraySizeSTA; i++ ){
			syslog( LOG_INFO, "  (*arraySt)[%d]->a = %d, (*arraySt)[%d]->b = %d",
					i, (*arraySt)[i]->a, i, (*arraySt)[i]->b );
			syslog( LOG_INFO, (*arraySt)[i]->msg );
		}
		CCALL_FUNC39_ARRAYST_DEALLOC( arraySt );
	}


	/* チャンネルを閉じる前に wait する */
#define WAITING	2
	syslog( LOG_INFO, "sleeping %d seconds", WAITING );
	sleep( WAITING );

	syslog( LOG_INFO, "SimpleClient: shutdown server" );
	cCall_shutdown();

	cCall_func21_a_printStatistics();

	syslog( LOG_INFO, "SimpleClient: closing Channel" );
	cOpener_close( TMO_FEVR );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
