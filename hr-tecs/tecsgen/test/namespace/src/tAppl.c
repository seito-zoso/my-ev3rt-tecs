/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tAppl_template.c => src/tAppl.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * a                tecs_int32       ATTR_a          
 * b                tecs_int16       VAR_b           
 *
 * 呼び口関数 #_TCPF_#
 * call port : ka  signature: sSyscall context: task
 *   ER_ID          ka_cre_sem( );
 *   ER             ka_wai_sem( ID id );
 *   ER             ka_rel_sem( ID id );
 *   ER             ka_del_sem( ID id );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tAppl_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
