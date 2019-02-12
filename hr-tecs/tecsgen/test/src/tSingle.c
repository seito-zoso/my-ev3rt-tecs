#include "tSingle_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall  signature: sSingleCall
 *   tecs_int32 cCall_single( THIS, tecs_int32 single );
 */

/* 受け口関数 */
/*
 * entry port: eEntry
 * signature:  sSingleEntry
 */
/*
 * name:         eEntry_single
 * global_name:  tSingle_eEntry_single
 */
tecs_int32 eEntry_single( tecs_int32 single)
{

  puts( "tSingle       eEntry_single" );

  cCall_single( 20 );
}

