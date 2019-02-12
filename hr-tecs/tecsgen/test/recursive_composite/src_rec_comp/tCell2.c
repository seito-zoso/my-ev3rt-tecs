#include "tCell2_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall2  signature: sSig3
 *   tecs_int32 cCall2_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCall2_func2( THIS, tecs_int32 a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry2
 * signature:  sSig2
 */
/*
 * name:         eEntry2_func1
 * global_name:  tCell2_eEntry2_func1
 */
tecs_int32 eEntry2_func1( tCell2_IDX idx, tecs_int32 a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntry2_func1( a=%d )\n", a );
  printf( "tCell2: eEntry2_func1: calling cCall2_func1( this, a=102 )\n" );
  cCall2_func1( 102 );
}

/*
 * name:         eEntry2_func2
 * global_name:  tCell2_eEntry2_func2
 */
tecs_int32 eEntry2_func2( tCell2_IDX idx, tecs_int32 a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntry2_func2( a=%d )\n", a );
  printf( "tCell2: eEntry2_func2: calling cCall2_func2( this, a=202 )\n" );
  cCall2_func2( 202 );
}

