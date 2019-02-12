#include "tSingleEntry_tecsgen.h"

/* 呼び口関数 */
/*
 */

/* 受け口関数 */
/*
 * entry port: eSingleCall
 * signature:  sSingleCall
 */
/*
 * name:         eSingleCall_single
 * global_name:  tSingleEntry_eSingleCall_single
 */
tecs_int32 eSingleCall_single( tSingleEntry_IDX idx, tecs_int32 single)
{
  CELLCB     *this;
  if( VALID_IDX( idx ) ){
    this = tSingleEntry_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  puts( "tSingleEntry  eSingleCall_single" );
}

