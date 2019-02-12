/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * cbp              void*            ATTR_cbp        
 * inibp            void*            ATTR_inibp      
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCelltypeInfo signature: nTECSInfo_sCelltypeInfo context:task
 *   ER             cCelltypeInfo_getName( char_t* name, int_t max_len );
 *   void           cCelltypeInfo_getNameLength( uint16_t* len );
 *   void           cCelltypeInfo_getNAttr( int32_t* nAttr );
 *   void           cCelltypeInfo_getAttrInfo( int32_t ith, Descriptor( nTECSInfo_sAttrVarInfo )* desc );
 *   void           cCelltypeInfo_getNVar( int32_t* nVar );
 *   void           cCelltypeInfo_getVarInfo( int32_t ith, Descriptor( nTECSInfo_sAttrVarInfo )* desc );
 *   void           cCelltypeInfo_getNCall( int32_t* nCall );
 *   void           cCelltypeInfo_getCallInfo( int32_t ith, Descriptor( nTECSInfo_sCallInfo )* desc );
 *   void           cCelltypeInfo_getNEntry( int32_t* nEntry );
 *   void           cCelltypeInfo_getEntryInfo( int32_t ith, Descriptor( nTECSInfo_sEntryInfo )* desc );
 *   bool_t         cCelltypeInfo_isSingleton( );
 *   bool_t         cCelltypeInfo_isIDX_is_ID( );
 *   bool_t         cCelltypeInfo_hasCB( );
 *   bool_t         cCelltypeInfo_hasINIB( );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sCelltypeInfo ) cCelltypeInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sCelltypeInfo ) cCelltypeInfo_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tCellInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eCellInfo
 * entry port: eCellInfo
 * signature:  nTECSInfo_sCellInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCellInfo_getName
 * name:         eCellInfo_getName
 * global_name:  nTECSInfo_tCellInfo_eCellInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCellInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eCellInfo_getCelltypeInfo
 * name:         eCellInfo_getCelltypeInfo
 * global_name:  nTECSInfo_tCellInfo_eCellInfo_getCelltypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCellInfo_getCelltypeInfo(CELLIDX idx, Descriptor( nTECSInfo_sCelltypeInfo )* desc)
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

/* #[<ENTRY_FUNC>]# eCellInfo_getCBP
 * name:         eCellInfo_getCBP
 * global_name:  nTECSInfo_tCellInfo_eCellInfo_getCBP
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCellInfo_getCBP(CELLIDX idx, void** cbp)
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

/* #[<ENTRY_FUNC>]# eCellInfo_getINIBP
 * name:         eCellInfo_getINIBP
 * global_name:  nTECSInfo_tCellInfo_eCellInfo_getINIBP
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCellInfo_getINIBP(CELLIDX idx, void** inibp)
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
