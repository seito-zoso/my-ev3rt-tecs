#include "tCell_clnt_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall  signature: sSig3
 *   tecs_int32 cCall_func1( tecs_int32 a );
 *   tecs_int32 cCall_func2( tecs_int32 a );
 */

/* 受け口関数 */

int main()
{
  cCall_func1( 32 );
  cCall_func2( 96 );
}
