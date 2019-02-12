/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * a                int32_t          ATTR_a          
 * v                int32_t          VAR_v           
 *
 * #[</PREAMBLE>]# */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sSig2
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_func2
 * name:         eEnt_func2
 * global_name:  tMultCt_eEnt_func2
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*__inline__ int32_t*/
Inline int32_t
eEnt_func2(tMultCt_IDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
		return 0;
	}

	/* ここに処理本体を記述します */
	printf( "tMultCt_eEnt_func2: v = %d\n", VAR_v );
	VAR_v++;

	return 0;
}

