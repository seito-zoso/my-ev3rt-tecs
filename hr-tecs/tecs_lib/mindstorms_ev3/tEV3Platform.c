/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tEV3Platform_template.c => src/tEV3Platform.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cRiteVM signature: sRiteVM context:task optional:true
 *   bool_t     is_cRiteVM_joined(int subscript)        check if joined
 *   void           cRiteVM_reset( subscript );
 *       subscript:  0...(NCP_cRiteVM-1)
 * call port: cTask signature: sTask context:task optional:true
 *   bool_t     is_cTask_joined(int subscript)        check if joined
 *   ER             cTask_activate( subscript );
 *   ER_UINT        cTask_cancelActivate( subscript );
 *   ER             cTask_terminate( subscript );
 *   ER             cTask_changePriority( subscript, PRI priority );
 *   ER             cTask_getPriority( subscript, PRI* p_priority );
 *   ER             cTask_refer( subscript, T_RTSK* pk_taskStatus );
 *   ER             cTask_wakeup( subscript );
 *   ER_UINT        cTask_cancelWakeup( subscript );
 *   ER             cTask_releaseWait( subscript );
 *   ER             cTask_suspend( subscript );
 *   ER             cTask_resume( subscript );
 *   ER             cTask_raiseException( subscript, TEXPTN pattern );
 *   ER             cTask_referException( subscript, T_RTEX* pk_rtex );
 *   ER             cTask_startOverRunHandler( subscript, OVRTIM ovrtim );
 *   ER             cTask_stopOverRunHandler( subscript );
 *   ER             cTask_referOverRunHandler( subscript, T_ROVR* pk_rovr );
 *       subscript:  0...(NCP_cTask-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEV3Platform_tecsgen.h"
#include <t_syslog.h>
#include "ev3api_button.h"
/* static void back_button_event_handler(intptr_t button); */
#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include "console_dri.h"

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tEV3Platform_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
    void
eTaskBody_main(CELLIDX idx)
{

    /* ev3_button_set_on_clicked(BACK_BUTTON, back_button_event_handler, BACK_BUTTON); */

    while(1) {
        // TODO::support event_handler
        dly_tsk(250);
        if (ev3_button_is_pressed(BACK_BUTTON)) {
// #ifndef ZMODEM
            ext_ker();
// #else
//             CELLCB   *p_cellcb;
//             if (VALID_IDX(idx)) {
//                 p_cellcb = GET_CELLCB(idx);
//             }
//             initialize_console_dri();
//             dly_tsk(500);
//             syslog(LOG_EMERG,"Reset button is pressed");
//             for (int i=0; i<NCP_cRiteVM; i++) {
//                 cRiteVM_reset(i);
//             }
//             for (int i=0; i<NCP_cTask; i++) {
//                 cTask_activate(i);
//             }
// #endif /* ZMODEM */
        }
    }
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/* static void back_button_event_handler(intptr_t button){ */
/* 	syslog(LOG_EMERG, "ext_ker"); */
/* 	ext_ker(); */
/* }; */
