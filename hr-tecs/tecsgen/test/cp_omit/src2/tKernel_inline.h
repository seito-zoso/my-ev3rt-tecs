/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tKernel_inline_template.h => src/tKernel_inline.h
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eKernel
 * entry port: eKernel
 * signature:  sKernel
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eKernel_delay
 * name:         eKernel_delay
 * global_name:  tKernel_eKernel_delay
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_delay(RELTIM delay_time)
{
}

/* #[<ENTRY_FUNC>]# eKernel_exitTask
 * name:         eKernel_exitTask
 * global_name:  tKernel_eKernel_exitTask
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_exitTask()
{
}

/* #[<ENTRY_FUNC>]# eKernel_getTime
 * name:         eKernel_getTime
 * global_name:  tKernel_eKernel_getTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_getTime(SYSTIM* p_system_time)
{
}

/* #[<ENTRY_FUNC>]# eKernel_getMicroTime
 * name:         eKernel_getMicroTime
 * global_name:  tKernel_eKernel_getMicroTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_getMicroTime(SYSUTM* p_system_micro_time)
{
}

/* #[<ENTRY_FUNC>]# eKernel_exitKernel
 * name:         eKernel_exitKernel
 * global_name:  tKernel_eKernel_exitKernel
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eKernel_exitKernel()
{
}

/* #[<ENTRY_PORT>]# eiKernel
 * entry port: eiKernel
 * signature:  siKernel
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiKernel_getMicroTime
 * name:         eiKernel_getMicroTime
 * global_name:  tKernel_eiKernel_getMicroTime
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline ER
eiKernel_getMicroTime(SYSUTM* p_system_micro_time)
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
