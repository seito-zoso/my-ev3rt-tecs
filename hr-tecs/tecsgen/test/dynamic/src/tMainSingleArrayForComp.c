/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cDefaultTalker signature: sHello context:task
 *   void           cDefaultTalker_hello( );
 *   [ref_desc]
 *      Descriptor( sHello ) cDefaultTalker_refer_to_descriptor();
 *      Descriptor( sHello ) cDefaultTalker_ref_desc()      (same as above; abbreviated version);
 * call port: cTalker signature: sHello context:task
 *   void           cTalker_hello( subscript );
 *       subscript:  0...(NCP_cTalker-1)
 *   [dynamic]
 *      void           cTalker_set_descriptor( Descriptor( sHello ) desc, int_t subscript );
 * call port: cTalker2 signature: sHello context:task optional:true
 *   bool_t     is_cTalker2_joined(int subscript)        check if joined
 *   void           cTalker2_hello( subscript );
 *       subscript:  0...(NCP_cTalker2-1)
 *   [dynamic, optional]
 *      void           cTalker2_set_descriptor( Descriptor( sHello ) desc, int_t subscript );
 *      void           cTalker2_unjoin(  int_t subscript );
 * call port: cTalkerSelector signature: sTalkerSelector context:task
 *   void           cTalkerSelector_getTalker( Descriptor( sHello )* talker, int_t i );
 *   void           cTalkerSelector_getNTalker( int_t* n );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include <stdio.h>
#include "tMainSingleArrayForComp_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tMainSingleArray_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main()
{
	CELLCB	*p_cellcb;
    int_t    nTalker;
    int_t    i, j;
    Descriptor( sHello )  TalkerDesc;

	/* ここに処理本体を記述します #_TEFB_# */
    cTalkerSelector_getNTalker( &nTalker );
    printf( "eMain_main: start\n" );
    printf( "eMain_main: initial join\n" );
    for( j = 0; j < NCP_cTalker; j++ ){
        printf( "* Talker=%d\n", j );
        cTalker_hello( j );
    }
    printf( "eMain_main: cTalker: dynamic join\n" );
    printf( "eMain_main: # of Talker=%d\n", nTalker );
    for( i = j = 0; i < nTalker; i++ ){
        printf( "* TalkerSelector=%d, Talker=%d\n", nTalker - i - 1, j );
        cTalkerSelector_getTalker( &TalkerDesc, nTalker - i - 1 );

        printf( "   Descriptor[%d] is %s\n", nTalker - i - 1, (is_descriptor_unjoined( TalkerDesc ) ? "NOT joined" : "joined" ) );
        if( is_descriptor_unjoined( TalkerDesc ) )
            continue;

        cTalker_set_descriptor( j, TalkerDesc );
        cTalker_hello( j );
        j++;
        if( j >= NCP_cTalker )
            j = 0;
    }

    printf( "eMain_main: cTalker2: dynamic join\n" );
    for( i = j = 0; i < nTalker; i++ ){
        printf( "* TalkerSelector=%d, Talker=%d\n", nTalker - i - 1, j );
        cTalkerSelector_getTalker( &TalkerDesc, nTalker - i - 1 );

        printf( "   Descriptor[%d] is %s\n", nTalker - i - 1, (is_descriptor_unjoined( TalkerDesc ) ? "NOT joined" : "joined" ) );
        if( is_descriptor_unjoined( TalkerDesc ) )
            continue;

        printf( "   cTalker2_is_joined: %s\n", is_cTalker2_joined( j ) ? "true" : "false" );
        cTalker2_set_descriptor( j, TalkerDesc );
        cTalker2_hello( j );
        j++;
        if( j >= NCP_cTalker2 )
            j = 0;
    }

    printf( "eMain_main: end\n" );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
