/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tBalancer_template.c => src/tBalancer.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tBalancer_tecsgen.h"
#include "balancer.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/**
 * �Хå���å��奭��󥻥�
 * @note          ľ���PWM�ͤ˱����ƥ��󥳡����ͤ˥Хå���å���ʬ���ͤ��ɲä��ޤ�
 * @param rwEnc   �����إ��󥳡�����
 * @param lwEnc   �����إ��󥳡�����
 * @date          2017/10/24
 * @auther        Koji SHIMIZU
 */
static inline void backlashCanceler(int32_t backlashhalf, int8_t ret_pwm_l, int8_t ret_pwm_r, int32_t *lwEnc, int32_t *rwEnc)
{
  // �Хå���å����Ⱦʬ[deg]

  if(ret_pwm_l < 0) *lwEnc += backlashhalf;
  else if(ret_pwm_l > 0) *lwEnc -= backlashhalf;

  if(ret_pwm_r < 0) *rwEnc += backlashhalf;
  else if(ret_pwm_r > 0) *rwEnc -= backlashhalf;
}

/* �������ؿ� #_TEPF_# */
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
	// ��Ω�����ѥ饤�֥��ؿ���ƤӽФ�
	balance_init();
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
