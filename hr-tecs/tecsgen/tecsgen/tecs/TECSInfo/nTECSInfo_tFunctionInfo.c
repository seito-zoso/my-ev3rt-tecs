/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * bOneway          bool_t           ATTR_bOneway    
 *
 * 呼び口関数 #_TCPF_#
 * call port: cParamInfo signature: nTECSInfo_sParamInfo context:task optional:true
 *   bool_t     is_cParamInfo_joined(int subscript)        check if joined
 *   ER             cParamInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cParamInfo_getNameLength( subscript, uint16_t* len );
 *   ER             cParamInfo_getTypeInfo( subscript, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *       subscript:  0...(NCP_cParamInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sParamInfo ) cParamInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sParamInfo ) cParamInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cReturnTypeInfo signature: nTECSInfo_sTypeInfo context:task
 *   ER             cReturnTypeInfo_getName( char_t* name, int_t max_len );
 *   void           cReturnTypeInfo_getNameLength( uint16_t* len );
 *   void           cReturnTypeInfo_getSize( uint32_t* size );
 *   void           cReturnTypeInfo_getKind( int8_t* kind );
 *   void           cReturnTypeInfo_getNType( int32_t* num );
 *   void           cReturnTypeInfo_getTypeInfo( int32_t ith, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sTypeInfo ) cReturnTypeInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sTypeInfo ) cReturnTypeInfo_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tFunctionInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eFunctionInfo
 * entry port: eFunctionInfo
 * signature:  nTECSInfo_sFunctionInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eFunctionInfo_getName
 * name:         eFunctionInfo_getName
 * global_name:  nTECSInfo_tFunctionInfo_eFunctionInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eFunctionInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eFunctionInfo_getNameLength
 * name:         eFunctionInfo_getNameLength
 * global_name:  nTECSInfo_tFunctionInfo_eFunctionInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eFunctionInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eFunctionInfo_getReturnTypeInfo
 * name:         eFunctionInfo_getReturnTypeInfo
 * global_name:  nTECSInfo_tFunctionInfo_eFunctionInfo_getReturnTypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eFunctionInfo_getReturnTypeInfo(CELLIDX idx, Descriptor( nTECSInfo_sTypeInfo )* desc)
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

/* #[<ENTRY_FUNC>]# eFunctionInfo_getNParam
 * name:         eFunctionInfo_getNParam
 * global_name:  nTECSInfo_tFunctionInfo_eFunctionInfo_getNParam
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eFunctionInfo_getNParam(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eFunctionInfo_getParamInfo
 * name:         eFunctionInfo_getParamInfo
 * global_name:  nTECSInfo_tFunctionInfo_eFunctionInfo_getParamInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eFunctionInfo_getParamInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sParamInfo )* param)
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

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
