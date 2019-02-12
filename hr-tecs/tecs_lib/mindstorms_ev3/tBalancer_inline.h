/*
 *   TOPPERS Software
 *       Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *   Copyright (C) 2010-2011 by Embedded and Real-Time Systems Laboratory
 *               Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *   上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *   ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *   変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *   (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *       権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *       スコード中に含まれていること．
 *   (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *       用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *       者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *       の無保証規定を掲載すること．
 *   (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *       用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *       と．
 *     (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *         作権表示，この利用条件および下記の無保証規定を掲載すること．
 *     (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *         報告すること．
 *   (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *       害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *       また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *       由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *       免責すること．
 *
 *   本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *   よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *   に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *   アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *   の責任を負わない．
 *
 */
#include <t_syslog.h>
/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tBalancerBody_inline_template.h => src/tBalancerBody_inline.h
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

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
    
    
    // 倒立制御用ライブラリ関数を呼び出す
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
    // 倒立制御用ライブラリ関数を呼び出す
    balance_init();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
