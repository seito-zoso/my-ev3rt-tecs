/*
 *   TOPPERS Software
 *       Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *   Copyright (C) 2010-2011 by Embedded and Real-Time Systems Laboratory
 *               Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *       ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *       �ȡ�
 *     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *         ��𤹤뤳�ȡ�
 *   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *       ���դ��뤳�ȡ�
 *
 *   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *   ����Ǥ�����ʤ���
 *
 */
#include <t_syslog.h>
/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tBalancerBody_inline_template.h => src/tBalancerBody_inline.h
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * #[</PREAMBLE>]# */

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
Inline void
eBalancer_control(int16_t forward, int16_t turn, uint16_t gyro, uint16_t gyroOffset, int32_t leftRevolution, int32_t rightRevolution, uint16_t battery, int8_t* pwm_l, int8_t* pwm_r)
{
    syslog(LOG_EMERG,"in balancer");
    dly_tsk(1000);
    syslog(LOG_EMERG,"0x%x 0x%x",pwm_l,pwm_r);
    dly_tsk(1000);
    syslog(LOG_EMERG,"pwm_l %d ",*pwm_l);
    dly_tsk(1000);
    syslog(LOG_EMERG,"pwm_r %d ",*pwm_r);
    dly_tsk(1000);
    
    
    // ��Ω�����ѥ饤�֥��ؿ���ƤӽФ�
    balance_control((float32_t)forward,
                    (float32_t)turn,
                    (float32_t)gyro,
                    (float32_t)gyroOffset,
                    (float32_t)leftRevolution,
                    (float32_t)rightRevolution,
                    (float32_t)battery,
                    pwm_l,
                    pwm_r);
    syslog(LOG_EMERG,"%d %d",*pwm_l,*pwm_r);
    dly_tsk(1000);
}

/* #[<ENTRY_FUNC>]# eBalancer_init
 * name:         eBalancer_init
 * global_name:  tBalancer_eBalancer_init
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eBalancer_init()
{
    // ��Ω�����ѥ饤�֥��ؿ���ƤӽФ�
    balance_init();
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
