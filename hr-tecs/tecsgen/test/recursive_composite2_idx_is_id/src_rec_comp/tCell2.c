#include "tCell2_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall2  signature: sSig3
 *   tecs_int32 cCall2_func1( THIS, subscript, tecs_int32 a );
 *   tecs_int32 cCall2_func2( THIS, subscript, tecs_int32 a );
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
  tCell2_CB     *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntry2_func1( a=%d )\n", a );
  printf( "tCell2: eEntry2_func1: calling cCall2_func1( p_cellcb, subscript=0, a=102 )\n" );
  cCall2_func1( 0, 102 );
}

/*
 * name:         eEntry2_func2
 * global_name:  tCell2_eEntry2_func2
 */
tecs_int32 eEntry2_func2( tCell2_IDX idx, tecs_int32 a)
{
  tCell2_CB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntry2_func2( a=%d )\n", a );
  printf( "tCell2: eEntry2_func2: calling cCall2_func2( p_cellcb, subscript=1, a=202 )\n" );
  cCall2_func2( 1, 202 );
}

/*
 * entry port: eEntryB
 * signature:  sSigB
 */
/*
 * name:         eEntryB_func1
 * global_name:  tCell2_eEntryB_func1
 */
tecs_int32 eEntryB_func1( tCell2_IDX idx, tecs_int32 a)
{
  tCell2_CB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntryB_func1( p_cellcb, a=%d )\n", a );

}

/*
 * name:         eEntryB_func2
 * global_name:  tCell2_eEntryB_func2
 */
tecs_int32 eEntryB_func2( tCell2_IDX idx, tecs_int32 a)
{
  tCell2_CB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell2_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell2: eEntryB_func2( p_cellcb, a=%d )\n", a );
}

