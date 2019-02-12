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
 * call port: cTalker signature: sHello context:task optional:true
 *   bool_t     is_cTalker_joined()                     check if joined
 *   void           cTalker_hello( );
 *   [dynamic, optional]
 *      void           cTalker_set_descriptor( Descriptor( sHello ) desc );
 *      void           cTalker_unjoin(  );
 * call port: cTalkerSelector signature: sTalkerSelector context:task
 *   void           cTalkerSelector_getTalker( Descriptor( sHello )* talker, int_t i );
 *   void           cTalkerSelector_getNTalker( int_t* n );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include <stdio.h>
#include "tMainSingleton_tecsgen.h"

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
 * global_name:  tMainSingleton_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main()
{
//	CELLCB	*p_cellcb;
    int_t    nTalker;
    int_t    i;
    Descriptor( sHello )  TalkerDesc;
//	if (VALID_IDX(idx)) {
//		p_cellcb = GET_CELLCB(idx);
//	}
//	else {
//		/* エラー処理コードをここに記述します */
//	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    printf( "eMainSingleton_main: start\n" );
    cTalkerSelector_getNTalker( &nTalker );
    printf( "eMain_main: # of Talker=%d\n", nTalker );
    for( i = 0; i < nTalker; i++ ){
        cTalkerSelector_getTalker( &TalkerDesc, i );
        printf( "  Descriptor[%d] is %s\n", i, (is_descriptor_unjoined( TalkerDesc ) ? "NOT joined" : "joined" ) );
        cTalker_set_descriptor( TalkerDesc );
        printf( "cTalkeris_joined: %s\n", is_cTalker_joined() ? "true" : "false" );
        cTalker_hello( );
    }
    printf( "eMain_main: end\n" );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
