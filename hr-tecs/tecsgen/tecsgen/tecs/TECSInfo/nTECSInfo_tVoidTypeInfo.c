/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * typeKind         int8_t           ATTR_typeKind   
 * bitSize          int32_t          ATTR_bitSize    
 * b_const          bool_t           ATTR_b_const    
 * b_volatile       bool_t           ATTR_b_volatile 
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tVoidTypeInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eTypeInfo
 * entry port: eTypeInfo
 * signature:  nTECSInfo_sTypeInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTypeInfo_getName
 * name:         eTypeInfo_getName
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTypeInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eTypeInfo_getNameLength
 * name:         eTypeInfo_getNameLength
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTypeInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eTypeInfo_getSize
 * name:         eTypeInfo_getSize
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getSize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTypeInfo_getSize(CELLIDX idx, uint32_t* size)
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

/* #[<ENTRY_FUNC>]# eTypeInfo_getKind
 * name:         eTypeInfo_getKind
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getKind
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTypeInfo_getKind(CELLIDX idx, int8_t* kind)
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

/* #[<ENTRY_FUNC>]# eTypeInfo_getNType
 * name:         eTypeInfo_getNType
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getNType
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTypeInfo_getNType(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eTypeInfo_getTypeInfo
 * name:         eTypeInfo_getTypeInfo
 * global_name:  nTECSInfo_tVoidTypeInfo_eTypeInfo_getTypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTypeInfo_getTypeInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sTypeInfo )* desc)
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
