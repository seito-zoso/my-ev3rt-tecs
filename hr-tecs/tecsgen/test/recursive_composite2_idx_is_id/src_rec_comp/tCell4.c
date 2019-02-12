#include "tCell4_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall4  signature: sSig5
 *   tecs_int32 cCall4_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCall4_func2( THIS, tecs_int32 a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry4
 * signature:  sSig4
 */
/*
 * name:         eEntry4_func1
 * global_name:  tCell4_eEntry4_func1
 */
tecs_int32 eEntry4_func1( tCell4_IDX idx, tecs_int32 a)
{
  tCell4_CB       *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell4_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell4: eEntry4_func1( a=%d )\n", a );
  printf( "tCell4: eEntry4_func1: calling cCall4_func1( p_cellcb, a=104 )\n" );
  cCall4_func1( 104 );
}

/*
 * name:         eEntry4_func2
 * global_name:  tCell4_eEntry4_func2
 */
tecs_int32 eEntry4_func2( tCell4_IDX idx, tecs_int32 a)
{
  tCell4_CB       *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell4_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell4: eEntry4_func2( a=%d )\n", a );
  printf( "tCell4: eEntry4_func2: calling cCall4_func2( p_cellcb, a=204 )\n" );
  cCall4_func2( 204 );
}

