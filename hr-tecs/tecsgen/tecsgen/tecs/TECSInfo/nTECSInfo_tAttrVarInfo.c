/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * size_expr        char_t*          ATTR_size_expr  
 * inCB             bool_t           ATTR_inCB       
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

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tAttrVarInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eAttrVarInfo
 * entry port: eAttrVarInfo
 * signature:  nTECSInfo_sAttrVarInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAttrVarInfo_getName
 * name:         eAttrVarInfo_getName
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAttrVarInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eAttrVarInfo_getOffset
 * name:         eAttrVarInfo_getOffset
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_getOffset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eAttrVarInfo_getOffset(CELLIDX idx, uint32_t* offset)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eAttrVarInfo_getTypeInfo
 * name:         eAttrVarInfo_getTypeInfo
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_getTypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eAttrVarInfo_getTypeInfo(CELLIDX idx, Descriptor( nTECSInfo_sTypeInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eAttrVarInfo_getSizeIsExpr
 * name:         eAttrVarInfo_getSizeIsExpr
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_getSizeIsExpr
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eAttrVarInfo_getSizeIsExpr(CELLIDX idx, uint32_t* expr_str, int32_t max_len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eAttrVarInfo_getSizeIs
 * name:         eAttrVarInfo_getSizeIs
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_getSizeIs
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAttrVarInfo_getSizeIs(CELLIDX idx, uint32_t* size, const void* p_cb)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eAttrVarInfo_isInCB
 * name:         eAttrVarInfo_isInCB
 * global_name:  nTECSInfo_tAttrVarInfo_eAttrVarInfo_isInCB
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eAttrVarInfo_isInCB(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
