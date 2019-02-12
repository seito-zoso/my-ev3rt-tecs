/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char*            ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCellInfo signature: nTECSInfo_sCellInfo context:task optional:true
 *   bool_t     is_cCellInfo_joined(int subscript)        check if joined
 *   ER             cCellInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cCellInfo_getCelltypeInfo( subscript, Descriptor( nTECSInfo_sCelltypeInfo )* desc );
 *   void           cCellInfo_getCBP( subscript, void** cbp );
 *   void           cCellInfo_getINIBP( subscript, void** inibp );
 *       subscript:  0...(NCP_cCellInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sCellInfo ) cCellInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sCellInfo ) cCellInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cRegionInfo signature: nTECSInfo_sRegionInfo context:task optional:true
 *   bool_t     is_cRegionInfo_joined(int subscript)        check if joined
 *   ER             cRegionInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cRegionInfo_getNameLength( subscript, uint16_t* len );
 *   void           cRegionInfo_getNCell( subscript, int32_t* num );
 *   void           cRegionInfo_getCellInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sCellInfo )* des );
 *   void           cRegionInfo_getNRegion( subscript, int32_t* num );
 *   void           cRegionInfo_getRegionInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sRegionInfo )* des );
 *       subscript:  0...(NCP_cRegionInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sRegionInfo ) cRegionInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sRegionInfo ) cRegionInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tRegionInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eRegionInfo
 * entry port: eRegionInfo
 * signature:  nTECSInfo_sRegionInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRegionInfo_getName
 * name:         eRegionInfo_getName
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eRegionInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eRegionInfo_getNameLength
 * name:         eRegionInfo_getNameLength
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRegionInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eRegionInfo_getNCell
 * name:         eRegionInfo_getNCell
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getNCell
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRegionInfo_getNCell(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eRegionInfo_getCellInfo
 * name:         eRegionInfo_getCellInfo
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getCellInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRegionInfo_getCellInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sCellInfo )* des)
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

/* #[<ENTRY_FUNC>]# eRegionInfo_getNRegion
 * name:         eRegionInfo_getNRegion
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getNRegion
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRegionInfo_getNRegion(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eRegionInfo_getRegionInfo
 * name:         eRegionInfo_getRegionInfo
 * global_name:  nTECSInfo_tRegionInfo_eRegionInfo_getRegionInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRegionInfo_getRegionInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sRegionInfo )* des)
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
