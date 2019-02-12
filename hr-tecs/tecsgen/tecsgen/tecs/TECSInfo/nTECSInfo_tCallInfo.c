/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * offset           uint32_t         ATTR_offset     
 * b_optional       bool_t           ATTR_b_optional 
 * b_omit           bool_t           ATTR_b_omit     
 * b_dynamic        bool_t           ATTR_b_dynamic  
 * b_ref_desc       bool_t           ATTR_b_ref_desc 
 * b_allocator_port bool_t           ATTR_b_allocator_port
 * b_require_port   bool_t           ATTR_b_require_port
 * place            uint8_t          ATTR_place      
 * b_VMT_useless    bool_t           ATTR_b_VMT_useless
 * b_skelton_useless bool_t           ATTR_b_skelton_useless
 * b_cell_unique    bool_t           ATTR_b_cell_unique
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSignatureInfo signature: nTECSInfo_sSignatureInfo context:task
 *   ER             cSignatureInfo_getName( char_t* name, int_t max_len );
 *   void           cSignatureInfo_getNameLength( uint16_t* len );
 *   void           cSignatureInfo_getNFunction( int32_t* num );
 *   void           cSignatureInfo_getFunctionInfo( int32_t ith, Descriptor( nTECSInfo_sFunctionInfo )* desc );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sSignatureInfo ) cSignatureInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sSignatureInfo ) cSignatureInfo_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tCallInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eCallInfo
 * entry port: eCallInfo
 * signature:  nTECSInfo_sCallInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCallInfo_getName
 * name:         eCallInfo_getName
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCallInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getNameLength
 * name:         eCallInfo_getNameLength
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getSignatureInfo
 * name:         eCallInfo_getSignatureInfo
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getSignatureInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getSignatureInfo(CELLIDX idx, Descriptor( nTECSInfo_sSignatureInfo )* desc)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getArraySize
 * name:         eCallInfo_getArraySize
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getArraySize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getArraySize(CELLIDX idx, uint32_t* array_size)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getSpecifierInfo
 * name:         eCallInfo_getSpecifierInfo
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getSpecifierInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getSpecifierInfo(CELLIDX idx, bool_t* b_optional, bool_t* b_dynamic, bool_t* b_ref_desc, bool_t* b_omit)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getInternalInfo
 * name:         eCallInfo_getInternalInfo
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getInternalInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getInternalInfo(CELLIDX idx, bool_t* b_allocator_port, bool_t* b_require_port)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getLocationInfo
 * name:         eCallInfo_getLocationInfo
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getLocationInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getLocationInfo(CELLIDX idx, uint32_t* offset, uint8_t* place)
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

/* #[<ENTRY_FUNC>]# eCallInfo_getOptimizeInfo
 * name:         eCallInfo_getOptimizeInfo
 * global_name:  nTECSInfo_tCallInfo_eCallInfo_getOptimizeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallInfo_getOptimizeInfo(CELLIDX idx, bool_t* b_VMT_useless, bool_t* b_skelton_useless, bool_t* b_cell_unique)
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
