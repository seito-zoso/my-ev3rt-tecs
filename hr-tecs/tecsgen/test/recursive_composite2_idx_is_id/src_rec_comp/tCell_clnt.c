#include "tCell_clnt_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cCall  signature: sSig1
 *   tecs_int32 cCall_func1( subscript, tecs_int32 a );
 *   tecs_int32 cCall_func2( subscript, tecs_int32 a );
 */

/* 受け口関数 */

int main( int argc, char **argv )
{
  printf( "main\n" );
  printf( "main: calling cCall_func1( subscript=0, a=100 )\n" );
  cCall_func1( 0, 100 );

  printf( "main: calling cCall_func2( subscript=1, a=200 )\n" );
  cCall_func2( 1, 200 );

  printf( "main: exit(0)\n" );
  exit( 0 );
}
