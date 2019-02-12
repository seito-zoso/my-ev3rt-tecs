#include "tCell2_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall  signature: sSig2
 *   int32_t cCall_func1( THIS, int32_t a );
 *   int32_t cCall_func2( THIS, int32_t a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry
 * signature:  sSig3
 */
/*
 * name:         eEntry_func1
 * global_name:  tCell2_eEntry_func1
 */
int32_t eEntry_func1( tCell2_IDX idx, int32_t a)
{
  struct tag_tCell2_CB *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }


  printf( "tCell2: eEntry_func1 %d\n", a );
  cCall_func1( 128 );
}

/*
 * name:         eEntry_func2
 * global_name:  tCell2_eEntry_func2
 */
int32_t eEntry_func2( tCell2_IDX idx, int32_t a)
{
  struct tag_tCell2_CB *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntry_func2 %d\n", a );
  cCall_func2( 164 );
}

