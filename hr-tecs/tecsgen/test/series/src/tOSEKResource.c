/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * nest_max         int16_t          ATTR_nest_max   
 * nest             int32_t          VAR_nest        
 *
 * 呼び口関数 #_TCPF_#
 * call port : cLinkedResource  signature: sLinkedResource context: task
 *   void           cLinkedResource_main( subscript );
 *       subscript:  0...(NCP_cLinkedResource-1)
 * call port : cLinkedResource2  signature: sLinkedResource context: task
 *   void           cLinkedResource2_main( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tOSEKResource_tecsgen.h"
#include <stdio.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eLinkedResource
 * entry port: eLinkedResource
 * signature:  sLinkedResource
 * context:    task
 * entry port array size:  NEP_eLinkedResource
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLinkedResource_main
 * name:         eLinkedResource_main
 * global_name:  tOSEKResource_eLinkedResource_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLinkedResource_main(CELLIDX idx, int_t subscript)
{
	CELLCB	*p_cellcb;
	int_t	i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	VAR_nest++;
	printf( "tOSEKResource: name=%s.eLinedResource[%d] nest=%d/%d\n", ATTR_name, subscript, VAR_nest, ATTR_nest_max );

	if( VAR_nest < ATTR_nest_max ){
		for( i = 0; i < NCP_cLinkedResource; i++ ){
			if( is_cLinkedResource_joined( i ) ){
				cLinkedResource_main( i );
			}
		}
		if( is_cLinkedResource2_joined() )
			cLinkedResource2_main( );
	}
	VAR_nest--;
}

/* #[<ENTRY_PORT>]# eLinkedResource_2
 * entry port: eLinkedResource_2
 * signature:  sLinkedResource
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLinkedResource_2_main
 * name:         eLinkedResource_2_main
 * global_name:  tOSEKResource_eLinkedResource_2_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLinkedResource_2_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	int_t	i;

	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	VAR_nest++;
	printf( "tOSEKResource: name=%s.eLinedResource_2 nest=%d/%d\n", ATTR_name, VAR_nest, ATTR_nest_max );

	if( VAR_nest < ATTR_nest_max ){
		for( i = 0; i < NCP_cLinkedResource; i++ ){
			if( is_cLinkedResource_joined( i ) ){
				cLinkedResource_main( i );
			}
		}
		if( is_cLinkedResource2_joined() )
			cLinkedResource2_main( );
	}
	VAR_nest--;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
