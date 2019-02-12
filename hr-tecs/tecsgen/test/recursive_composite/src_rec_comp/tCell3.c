#include "tCell3_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall3  signature: sSig4
 *   tecs_int32 cCall3_func1( THIS, tecs_int32 a );
 *   tecs_int32 cCall3_func2( THIS, tecs_int32 a );
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
tecs_int32 eEntry3_func1( tCell3_IDX idx, tecs_int32 a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell3_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell3: eEntry3_func1( a=%d )\n", a );
  printf( "tCell3: eEntry3_func1: calling cCall3_func1( this, a=103 )\n" );
  cCall3_func1( 103 );
}

/*
 * name:         eEntry3_func2
 * global_name:  tCell3_eEntry3_func2
 */
tecs_int32 eEntry3_func2( tCell3_IDX idx, tecs_int32 a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell3_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell3: eEntry3_func2( a=%d )\n", a );
  printf( "tCell3: eEntry3_func2: calling cCall3_func2( this, a=203 )\n" );
  cCall3_func2( 203 );
}

