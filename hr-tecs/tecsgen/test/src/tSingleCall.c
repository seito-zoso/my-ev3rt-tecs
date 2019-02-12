#include "tSingleCall_tecsgen.h"

/* 呼び口関数 */
/*
 * call port : cSingleEntry  signature: sSingleEntry
 *   tecs_int32 cSingleEntry_single( THIS, tecs_int32 single );
 */

/* 受け口関数 */
main()
{
   CELLCB *p_cellcb;
/* オプティマイズされているとこれらはなくなる
 * extern tSingleCall_CB    tSingleCall_CB_tab[];
 * struct tag_tSingleCall_CB *p_cellcb = &tSingleCall_CB_tab[0];
 */
  puts( "tSingleCall   main" );

  cSingleEntry_single( 10 );
}
