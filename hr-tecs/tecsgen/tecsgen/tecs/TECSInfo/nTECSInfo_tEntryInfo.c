/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * b_inline         bool_t           ATTR_b_inline   
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
#include "nTECSInfo_tEntryInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eEntryInfo
 * entry port: eEntryInfo
 * signature:  nTECSInfo_sEntryInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEntryInfo_getName
 * name:         eEntryInfo_getName
 * global_name:  nTECSInfo_tEntryInfo_eEntryInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEntryInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eEntryInfo_getNameLength
 * name:         eEntryInfo_getNameLength
 * global_name:  nTECSInfo_tEntryInfo_eEntryInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEntryInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eEntryInfo_getSignatureInfo
 * name:         eEntryInfo_getSignatureInfo
 * global_name:  nTECSInfo_tEntryInfo_eEntryInfo_getSignatureInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEntryInfo_getSignatureInfo(CELLIDX idx, Descriptor( nTECSInfo_sSignatureInfo )* desc)
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

/* #[<ENTRY_FUNC>]# eEntryInfo_getArraySize
 * name:         eEntryInfo_getArraySize
 * global_name:  nTECSInfo_tEntryInfo_eEntryInfo_getArraySize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEntryInfo_getArraySize(CELLIDX idx, uint32_t* array_size)
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

/* #[<ENTRY_FUNC>]# eEntryInfo_isInline
 * name:         eEntryInfo_isInline
 * global_name:  nTECSInfo_tEntryInfo_eEntryInfo_isInline
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eEntryInfo_isInline(CELLIDX idx)
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
