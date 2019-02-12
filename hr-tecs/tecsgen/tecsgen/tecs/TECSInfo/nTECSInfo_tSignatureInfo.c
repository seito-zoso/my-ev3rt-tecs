/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char*            ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * call port: cFunctionInfo signature: nTECSInfo_sFunctionInfo context:task optional:true
 *   bool_t     is_cFunctionInfo_joined(int subscript)        check if joined
 *   ER             cFunctionInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cFunctionInfo_getNameLength( subscript, uint16_t* len );
 *   void           cFunctionInfo_getReturnTypeInfo( subscript, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   void           cFunctionInfo_getNParam( subscript, int32_t* num );
 *   ER             cFunctionInfo_getParamInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sParamInfo )* param );
 *       subscript:  0...(NCP_cFunctionInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sFunctionInfo ) cFunctionInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sFunctionInfo ) cFunctionInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tSignatureInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eSignatureInfo
 * entry port: eSignatureInfo
 * signature:  nTECSInfo_sSignatureInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSignatureInfo_getName
 * name:         eSignatureInfo_getName
 * global_name:  nTECSInfo_tSignatureInfo_eSignatureInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSignatureInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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
    strncpy( name, ATTR_name, max_len );
	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSignatureInfo_getNameLength
 * name:         eSignatureInfo_getNameLength
 * global_name:  nTECSInfo_tSignatureInfo_eSignatureInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eSignatureInfo_getNameLength(CELLIDX idx, uint16_t* len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */
    *len = strlen( ATTR_name ) + 1;
      /* 終端文字 (NULL) を含む */
}

/* #[<ENTRY_FUNC>]# eSignatureInfo_getNFunction
 * name:         eSignatureInfo_getNFunction
 * global_name:  nTECSInfo_tSignatureInfo_eSignatureInfo_getNFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eSignatureInfo_getNFunction(CELLIDX idx, int32_t* num)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */
    *num = NCP_cFunctionInfo;
}

/* #[<ENTRY_FUNC>]# eSignatureInfo_getFunctionInfo
 * name:         eSignatureInfo_getFunctionInfo
 * global_name:  nTECSInfo_tSignatureInfo_eSignatureInfo_getFunctionInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eSignatureInfo_getFunctionInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sFunctionInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */
    *desc = cFunctionInfo_ref_desc( ith );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
