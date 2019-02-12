/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCelltype_template.c => src/tCelltype.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * attr1            int32_t          ATTR_attr1      
 * attr2            int32_t          ATTR_attr2      
 * attr3            int32_t          ATTR_attr3      
 * attr4            int32_t          ATTR_attr4      
 * var1             int32_t          VAR_var1        
 * var2             int32_t          VAR_var2        
 * var3             int32_t          VAR_var3        
 * var4             int32_t          VAR_var4        
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCall signature: sSig context:task 
 *   void           cCall_func( );
 *   void           cCall_Send( int32_t* buf, int32_t sz );
 * call port: cCall2 signature: sSig context:task 
 *   void           cCall2_func( subscript );
 *   void           cCall2_Send( subscript, int32_t* buf, int32_t sz );
 *       subscript:  0...(NCP_cCall2-1)
 * allocator port for call port:cCall func:Send param: buf
 *   ER             cCall_Send_buf_alloc( int32_t size, void** p );
 *   ER             cCall_Send_buf_dealloc( const void* p );
 * allocator port for call port:cCall2 func:Send param: buf
 *   ER             cCall2_Send_buf_alloc( subscript, int32_t size, void** p );
 *   ER             cCall2_Send_buf_dealloc( subscript, const void* p );
 *       subscript:  0...(NCP_cCall2_Send_buf-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCelltype_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tCelltype_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	cCall_func();
	cCall2_func( 0 );
	cCall2_func( 1 );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
