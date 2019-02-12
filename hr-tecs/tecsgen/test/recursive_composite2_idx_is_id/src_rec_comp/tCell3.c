#include "tCell3_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall3  signature: sSig4
 *   tecs_int32 cCall3_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCall3_func2( THIS, tecs_int32 a );
 * call port : cCallB  signature: sSigB
 *   tecs_int32 cCallB_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCallB_func2( THIS, tecs_int32 a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry3
 * signature:  sSig3
 */
/*
 * name:         eEntry3_func1
 * global_name:  tCell3_eEntry3_func1
 */
tecs_int32 eEntry3_func1( tCell3_IDX idx, int_t subscript, tecs_int32 a)
{
  tCell3_CB     *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell3_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell3: eEntry3_func1( subscript=%d, a=%d )\n", subscript, a );
  printf( "tCell3: eEntry3_func1: calling cCallB_func1( p_cellcb, a=303 )\n" );
  cCallB_func1( 303 );
  printf( "tCell3: eEntry3_func1: calling cCall3_func1( p_cellcb, a=103 )\n" );
  cCall3_func1( 103 );
}

/*
 * name:         eEntry3_func2
 * global_name:  tCell3_eEntry3_func2
 */
tecs_int32 eEntry3_func2( tCell3_IDX idx, int_t subscript, tecs_int32 a)
{
  tCell3_CB     *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell3_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell3: eEntry3_func2( subscript=%d, a=%d )\n", subscript, a );
  printf( "tCell3: eEntry3_func2: calling cCallB_func2( p_cellcb, a=403 )\n" );
  cCallB_func2( 403 );
  printf( "tCell3: eEntry3_func2: calling cCall3_func2( p_cellcb, a=203 )\n" );
  cCall3_func2( 203 );
}

