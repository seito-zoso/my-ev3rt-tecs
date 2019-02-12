/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <serial.h>
#include "sample1.h"

#include "tSampleMain_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cTask  signature: sTask
 *   ER             cTask_act_tsk( subscript );
 *   ER_UINT        cTask_can_act( subscript );
 *   ER             cTask_ter_tsk( subscript );
 *   ER             cTask_chg_pri( subscript, PRI tskpri );
 *   ER             cTask_get_pri( subscript, PRI* p_tskpri );
 *   ER             cTask_wup_tsk( subscript );
 *   ER_UINT        cTask_can_wup( subscript );
 *   ER             cTask_rel_wai( subscript );
 *   ER             cTask_sus_tsk( subscript );
 *   ER             cTask_rsm_tsk( subscript );
 *   ER             cTask_frsm_tsk( subscript );
 *   ER             cTask_ras_tex( subscript, TEXPTN rasptn );
 * call port : cSysMain  signature: sSystem
 *   ER             cSysMain_dis_tex( );
 *   ER             cSysMain_ena_tex( );
 *   BOOL           cSysMain_sns_tex( );
 *   void           cSysMain_ext_tsk( );
 *   ER             cSysMain_slp_tsk( );
 *   ER             cSysMain_tslp_tsk( TMO tmout );
 *   ER             cSysMain_dly_tsk( RELTIM dlytim );
 *   ER             cSysMain_rot_rdq( PRI tskpri );
 *   ER             cSysMain_get_tid( ID* p_tskid );
 *   ER             cSysMain_loc_cpu( );
 *   ER             cSysMain_unl_cpu( );
 *   ER             cSysMain_dis_dsp( );
 *   ER             cSysMain_ena_dsp( );
 *   BOOL           cSysMain_sns_ctx( );
 *   BOOL           cSysMain_sns_loc( );
 *   BOOL           cSysMain_sns_dsp( );
 *   BOOL           cSysMain_sns_dpn( );
 * call port : cCyc  signature: sCyc
 *   ER             cCyc_sta_cyc( );
 *   ER             cCyc_stp_cyc( );
 */

/* 受け口関数 */
/*
 * entry port: eMain
 * signature:  sMain
 */
/*
 * name:         eMain_main
 * global_name:  tSampleMain_eMain_main
 */
ER             eMain_main( intptr_t exinf)
{
  main_task(exinf);
  return E_OK;
}

