#include "OSEK_tKernel_tecsgen.h"

/* 呼び口関数 */
/*
 */

/* 受け口関数 */
/*
 * entry port: ka
 * signature:  sSyscall
 */
/*
 * name:         ka_cre_sem
 * global_name:  OSEK_tKernel_ka_cre_sem
 */
ER_ID    ka_cre_sem( tKernel_IDX idx)
{
  struct tag_OSEK_tKernel_CB *this;
  if( VALID_IDX( idx ) ){
    this = OSEK_tKernel_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }
}

/*
 * name:         ka_wai_sem
 * global_name:  OSEK_tKernel_ka_wai_sem
 */
ER       ka_wai_sem( tKernel_IDX idx, ID id)
{
  struct tag_OSEK_tKernel_CB *this;
  if( VALID_IDX( idx ) ){
    this = OSEK_tKernel_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }
}

/*
 * name:         ka_rel_sem
 * global_name:  OSEK_tKernel_ka_rel_sem
 */
ER       ka_rel_sem( tKernel_IDX idx, ID id)
{
  struct tag_OSEK_tKernel_CB *this;
  if( VALID_IDX( idx ) ){
    this = OSEK_tKernel_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }
}

/*
 * name:         ka_del_sem
 * global_name:  OSEK_tKernel_ka_del_sem
 */
ER       ka_del_sem( tKernel_IDX idx, ID id)
{
  struct tag_OSEK_tKernel_CB *this;
  if( VALID_IDX( idx ) ){
    this = OSEK_tKernel_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }
}

