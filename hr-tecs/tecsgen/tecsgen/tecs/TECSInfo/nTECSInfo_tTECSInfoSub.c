/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cNamespaceInfo signature: nTECSInfo_sNamespaceInfo context:task
 *   ER             cNamespaceInfo_getName( char_t* name, int_t max_len );
 *   void           cNamespaceInfo_getNameLength( uint16_t* len );
 *   void           cNamespaceInfo_getNNamespace( int32_t* num );
 *   void           cNamespaceInfo_getNamespaceInfo( int32_t ith, Descriptor( nTECSInfo_sNamespaceInfo )* des );
 *   void           cNamespaceInfo_getNSignature( int32_t* num );
 *   void           cNamespaceInfo_getSignatureInfo( int32_t ith, Descriptor( nTECSInfo_sSignatureInfo )* des );
 *   void           cNamespaceInfo_getNCelltype( int32_t* num );
 *   void           cNamespaceInfo_getCelltypeInfo( int32_t ith, Descriptor( nTECSInfo_sCelltypeInfo )* des );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sNamespaceInfo ) cNamespaceInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sNamespaceInfo ) cNamespaceInfo_ref_desc()      (same as above; abbreviated version);
 * call port: cRegionInfo signature: nTECSInfo_sRegionInfo context:task
 *   ER             cRegionInfo_getName( char_t* name, int_t max_len );
 *   void           cRegionInfo_getNameLength( uint16_t* len );
 *   void           cRegionInfo_getNCell( int32_t* num );
 *   void           cRegionInfo_getCellInfo( int32_t ith, Descriptor( nTECSInfo_sCellInfo )* des );
 *   void           cRegionInfo_getNRegion( int32_t* num );
 *   void           cRegionInfo_getRegionInfo( int32_t ith, Descriptor( nTECSInfo_sRegionInfo )* des );
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sRegionInfo ) cRegionInfo_refer_to_descriptor();
 *      Descriptor( nTECSInfo_sRegionInfo ) cRegionInfo_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tTECSInfoSub_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eTECSInfo
 * entry port: eTECSInfo
 * signature:  nTECSInfo_sTECSInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTECSInfo_findNamespace
 * name:         eTECSInfo_findNamespace
 * global_name:  nTECSInfo_tTECSInfoSub_eTECSInfo_findNamespace
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTECSInfo_findNamespace(const char_t* namespace_path, Descriptor( nTECSInfo_sNamespaceInfo )* NSdesc)
{
}

/* #[<ENTRY_FUNC>]# eTECSInfo_findRegion
 * name:         eTECSInfo_findRegion
 * global_name:  nTECSInfo_tTECSInfoSub_eTECSInfo_findRegion
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTECSInfo_findRegion(const char_t* namespace_path, Descriptor( nTECSInfo_sRegionInfo )* RGNdesc)
{
}

/* #[<ENTRY_FUNC>]# eTECSInfo_findSignature
 * name:         eTECSInfo_findSignature
 * global_name:  nTECSInfo_tTECSInfoSub_eTECSInfo_findSignature
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTECSInfo_findSignature(const char_t* namespace_path, Descriptor( nTECSInfo_sSignatureInfo )* SIGdesc)
{
}

/* #[<ENTRY_FUNC>]# eTECSInfo_findCelltype
 * name:         eTECSInfo_findCelltype
 * global_name:  nTECSInfo_tTECSInfoSub_eTECSInfo_findCelltype
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTECSInfo_findCelltype(const char_t* namespace_path, Descriptor( nTECSInfo_sCelltypeInfo )* CTdesc)
{
}

/* #[<ENTRY_FUNC>]# eTECSInfo_findCell
 * name:         eTECSInfo_findCell
 * global_name:  nTECSInfo_tTECSInfoSub_eTECSInfo_findCell
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTECSInfo_findCell(const char_t* namespace_path, Descriptor( nTECSInfo_sCellInfo )* CELLdesc)
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
