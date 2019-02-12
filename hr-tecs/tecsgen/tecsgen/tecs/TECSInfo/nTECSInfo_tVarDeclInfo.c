/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * sizeIsExpr       char_t*          ATTR_sizeIsExpr 
 * declType         int8_t           ATTR_declType   
 * offset           uint32_t         ATTR_offset     
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTypeInfo signature: nTECSInfo_sTypeInfo context:task
 *   ER             cTypeInfo_getName( char_t* name, int_t max_len );
 *   void           cTypeInfo_getNameLength( uint16_t* len );
 *   void           cTypeInfo_getSize( uint32_t* size );
 *   void           cTypeInfo_getKind( int8_t* kind );
 *   void           cTypeInfo_getNType( int32_t* num );
 *   void           cTypeInfo_getTypeInfo( int32_t ith, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sTypeInfo ) cTypeInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sTypeInfo ) cTypeInfo_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nTECSInfo_tVarDeclInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eVarDeclInfo
 * entry port: eVarDeclInfo
 * signature:  nTECSInfo_sVarDeclInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eVarDeclInfo_getName
 * name:         eVarDeclInfo_getName
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eVarDeclInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eVarDeclInfo_getOffset
 * name:         eVarDeclInfo_getOffset
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_getOffset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eVarDeclInfo_getOffset(CELLIDX idx, uint32_t* offset)
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

/* #[<ENTRY_FUNC>]# eVarDeclInfo_getTypeInfo
 * name:         eVarDeclInfo_getTypeInfo
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_getTypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eVarDeclInfo_getTypeInfo(CELLIDX idx, Descriptor( nTECSInfo_sTypeInfo )* desc)
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

/* #[<ENTRY_FUNC>]# eVarDeclInfo_getSizeIsExpr
 * name:         eVarDeclInfo_getSizeIsExpr
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_getSizeIsExpr
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eVarDeclInfo_getSizeIsExpr(CELLIDX idx, uint32_t* expr_str, int32_t max_len)
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

/* #[<ENTRY_FUNC>]# eVarDeclInfo_getSizeIs
 * name:         eVarDeclInfo_getSizeIs
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_getSizeIs
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eVarDeclInfo_getSizeIs(CELLIDX idx, uint32_t* size, const void* p_cb)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eVarDeclInfo_isInCB
 * name:         eVarDeclInfo_isInCB
 * global_name:  nTECSInfo_tVarDeclInfo_eVarDeclInfo_isInCB
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eVarDeclInfo_isInCB(CELLIDX idx)
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

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
