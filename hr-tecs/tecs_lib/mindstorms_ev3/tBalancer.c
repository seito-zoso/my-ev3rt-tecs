/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tBalancer_template.c => src/tBalancer.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tBalancer_tecsgen.h"
#include "balancer.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/**
 * バックラッシュキャンセル
 * @note          直近のPWM値に応じてエンコーダ値にバックラッシュ分の値を追加します
 * @param rwEnc   右車輪エンコーダ値
 * @param lwEnc   左車輪エンコーダ値
 * @date          2017/10/24
 * @auther        Koji SHIMIZU
 */
static inline void backlashCanceler(int32_t backlashhalf, int8_t ret_pwm_l, int8_t ret_pwm_r, int32_t *lwEnc, int32_t *rwEnc)
{
  // バックラッシュの半分[deg]

  if(ret_pwm_l < 0) *lwEnc += backlashhalf;
  else if(ret_pwm_l > 0) *lwEnc -= backlashhalf;

  if(ret_pwm_r < 0) *rwEnc += backlashhalf;
  else if(ret_pwm_r > 0) *rwEnc -= backlashhalf;
}

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBalancer
 * entry port: eBalancer
 * signature:  sBalancer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBalancer_control
 * name:         eBalancer_control
 * global_name:  tBalancer_eBalancer_control
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBalancer_control(int16_t forward, int16_t turn, int16_t gyro, int16_t gyroOffset, int32_t leftRevolution, int32_t rightRevolution, int16_t battery, int8_t* pwm_l, int8_t* pwm_r, int32_t backlashhalf)
{
	float32_t f_forward = (float32_t) forward;
	float32_t f_turn = (float32_t) turn;
	float32_t f_gyro = (float32_t) gyro;
	float32_t f_gyroOffset = (float32_t) gyroOffset;
 	float32_t f_leftRevolution;
	float32_t f_rightRevolution;
	float32_t f_battery = (float32_t) battery;

	if( backlashhalf != 0 ){
		backlashCanceler(backlashhalf, *pwm_l, *pwm_r, &leftRevolution, &rightRevolution);
	}
 	f_leftRevolution = (float32_t) leftRevolution;
	f_rightRevolution = (float32_t) rightRevolution;

	balance_control(f_forward,
			f_turn,
			f_gyro,
			f_gyroOffset,
			f_leftRevolution,
			f_rightRevolution,
			f_battery,
			pwm_l,
			pwm_r);	
}

/* #[<ENTRY_FUNC>]# eBalancer_init
 * name:         eBalancer_init
 * global_name:  tBalancer_eBalancer_init
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBalancer_init()
{
	// 倒立制御用ライブラリ関数を呼び出す
	balance_init();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
