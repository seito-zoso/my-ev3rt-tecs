/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 */
#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <serial.h>

#include "sample1.h"

#include "tSubMain_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cSysSub  signature: sSystem
 *   ER             cSysSub_dis_tex( );
 *   ER             cSysSub_ena_tex( );
 *   BOOL           cSysSub_sns_tex( );
 *   void           cSysSub_ext_tsk( );
 *   ER             cSysSub_slp_tsk( );
 *   ER             cSysSub_tslp_tsk( TMO tmout );
 *   ER             cSysSub_dly_tsk( RELTIM dlytim );
 *   ER             cSysSub_rot_rdq( PRI tskpri );
 *   ER             cSysSub_get_tid( ID* p_tskid );
 *   ER             cSysSub_loc_cpu( );
 *   ER             cSysSub_unl_cpu( );
 *   ER             cSysSub_dis_dsp( );
 *   ER             cSysSub_ena_dsp( );
 *   BOOL           cSysSub_sns_ctx( );
 *   BOOL           cSysSub_sns_loc( );
 *   BOOL           cSysSub_sns_dsp( );
 *   BOOL           cSysSub_sns_dpn( );
 */

/* 受け口関数 */
/*
 * entry port: eSubMain
 * signature:  sMain
 */
/*
 * name:         eSubMain_main
 * global_name:  tSubMain_eSubMain_main
 */
ER             eSubMain_main( VP_INT exinf)
{
  task(exinf);
  return E_OK;
}

