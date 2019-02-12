#include "tCell1_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall  signature: sSig1
 *   tecs_int32 cCall_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCall_func2( THIS, tecs_int32 a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry
 * signature:  sSig2
 */
/*
 * name:         eEntry_func1
 * global_name:  tCell1_eEntry_func1
 */
int32_t eEntry_func1( tCell1_IDX idx, int32_t a)
{
  struct tag_tCell1_CB *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell1_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell1: eEntry_func1 %d\n", a );
  cCall_func1( a );
}

/*
 * name:         eEntry_func2
 * global_name:  tCell1_eEntry_func2
 */
int32_t eEntry_func2( tCell1_IDX idx, int32_t a)
{
  struct tag_tCell1_CB *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell1_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell1: eEntry_func2 %d\n", a );
  cCall_func2( a );
}

