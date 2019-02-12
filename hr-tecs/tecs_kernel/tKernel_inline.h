/*
 *  TOPPERS/HSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2008-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2012 by Ubiquitous Computing and Networking Laboratory
 *                Ritsumeikan Univ., JAPAN  
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: tKernel_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eKernel
 * entry port: eKernel
 * signature:  sKernel
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eKernel_sleep
 * name:         eKernel_sleep
 * global_name:  tKernel_eKernel_sleep
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_sleep()
{
	return(slp_tsk());
}

/* #[<ENTRY_FUNC>]# eKernel_sleepTimeout
 * name:         eKernel_sleepTimeout
 * global_name:  tKernel_eKernel_sleepTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_sleepTimeout(TMO timeout)
{
	return(tslp_tsk(timeout));
}

/* #[<ENTRY_FUNC>]# eKernel_delay
 * name:         eKernel_delay
 * global_name:  tKernel_eKernel_delay
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_delay(RELTIM delayTime)
{
	return(dly_tsk(delayTime));
}

/* #[<ENTRY_FUNC>]# eKernel_exitTask
 * name:         eKernel_exitTask
 * global_name:  tKernel_eKernel_exitTask
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_exitTask()
{
	return(ext_tsk());
}

/* #[<ENTRY_FUNC>]# eKernel_getTaskId
 * name:         eKernel_getTaskId
 * global_name:  tKernel_eKernel_getTaskId
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_getTaskId(ID* p_taskId)
{
	return(get_tid(p_taskId));
}

/* #[<ENTRY_FUNC>]# eKernel_rotateReadyQueue
 * name:         eKernel_rotateReadyQueue
 * global_name:  tKernel_eKernel_rotateReadyQueue
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_rotateReadyQueue(PRI taskPriority)
{
	return(rot_rdq(taskPriority));
}

/* #[<ENTRY_FUNC>]# eKernel_getTime
 * name:         eKernel_getTime
 * global_name:  tKernel_eKernel_getTiime
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_getTime(SYSTIM* p_systemTime)
{
	return(get_tim(p_systemTime));
}

/* #[<ENTRY_FUNC>]# eKernel_getMicroTime
 * name:         eKernel_getMicroTime
 * global_name:  tKernel_eKernel_getMicroTime
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_getMicroTime(SYSUTM* p_systemMicroTime)
{
#ifdef TOPPERS_SUPPORT_GET_UTM
	return(get_utm(p_systemMicroTime));
#else /* TOPPERS_SUPPORT_GET_UTM */
	return E_NOSPT;
#endif /* TOPPERS_SUPPORT_GET_UTM */
}

/* #[<ENTRY_FUNC>]# eKernel_lockCpu
 * name:         eKernel_lockCpu
 * global_name:  tKernel_eKernel_lockCpu
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_lockCpu()
{
	return(loc_cpu());
}

/* #[<ENTRY_FUNC>]# eKernel_unlockCpu
 * name:         eKernel_unlockCpu
 * global_name:  tKernel_eKernel_unlockCpu
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_unlockCpu()
{
	return(unl_cpu());
}

/* #[<ENTRY_FUNC>]# eKernel_disableDispatch
 * name:         eKernel_disableDispatch
 * global_name:  tKernel_eKernel_disableDispatch
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_disableDispatch()
{
	return(dis_dsp());
}

/* #[<ENTRY_FUNC>]# eKernel_enableDispatch
 * name:         eKernel_enableDispatch
 * global_name:  tKernel_eKernel_enableDispatch
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_enableDispatch()
{
	return(ena_dsp());
}
/* #[<ENTRY_FUNC>]# eKernel_disableTaskException
 * name:         eKernel_disableTaskException
 * global_name:  tKernel_eKernel_disableTaskException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_disableTaskException()
{
	return(dis_tex());
}

/* #[<ENTRY_FUNC>]# eKernel_EnableTaskException
 * name:         eKernel_EnableTaskException
 * global_name:  tKernel_eKernel_EnableTaskException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_enableTaskException()
{
	return(ena_tex());
}
/* #[<ENTRY_FUNC>]# eKernel_changeInterruptPriorityMask
 * name:         eKernel_changeInterruptPriorityMask
 * global_name:  tKernel_eKernel_changeInterruptPriorityMask
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_changeInterruptPriorityMask(PRI interruptPriority)
{
	return(chg_ipm(interruptPriority));
}

/* #[<ENTRY_FUNC>]# eKernel_getInterruptPriorityMask
 * name:         eKernel_getInterruptPriorityMask
 * global_name:  tKernel_eKernel_getInterruptPriorityMask
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_getInterruptPriorityMask(PRI* p_interruptPriority)
{
	return(get_ipm(p_interruptPriority));
}

/* #[<ENTRY_FUNC>]# eKernel_exitKernel
 * name:         eKernel_exitKernel
 * global_name:  tKernel_eKernel_exitKernel
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eKernel_exitKernel()
{
	return(ext_ker());
}


/* #[<ENTRY_PORT>]# eKernel
 * entry port: eKernel
 * signature:  saKernel
 * context:    any
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eKernel_senseContext
 * name:         eKernel_senseContext
 * global_name:  tKernel_eKernel_senseContext
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eKernel_senseContext()
{
	return(sns_ctx());
}

/* #[<ENTRY_FUNC>]# eKernel_senseLock
 * name:         eKernel_senseLock
 * global_name:  tKernel_eKernel_senseLock
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eKernel_senseLock()
{
	return(sns_loc());
}

/* #[<ENTRY_FUNC>]# eKernel_senseDispatch
 * name:         eKernel_senseDispatch
 * global_name:  tKernel_eKernel_senseDispatch
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eKernel_senseDispatch()
{
	return(sns_dsp());
}

/* #[<ENTRY_FUNC>]# eKernel_senseDispatchPendingState
 * name:         eKernel_senseDispatchPendingState
 * global_name:  tKernel_eKernel_senseDispatchPendingState
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eKernel_senseDispatchPendingState()
{
	return(sns_dpn());
}

/* #[<ENTRY_FUNC>]# eKernel_senseKernel
 * name:         eKernel_senseKernel
 * global_name:  tKernel_eKernel_senseKernel
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eKernel_senseKernel()
{
	return(sns_ker());
}

/* #[<ENTRY_PORT>]# eiKernel
 * entry port: eiKernel
 * signature:  siKernel
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */


/* #[<ENTRY_FUNC>]# eiKernel_getTaskId
 * name:         eiKernel_getTaskId
 * global_name:  tKernel_eiKernel_getTaskId
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_getTaskId(ID* p_taskId)
{
	return(iget_tid(p_taskId));
}
/* #[<ENTRY_FUNC>]# eiKernel_rotateReadyQueue
 * name:         eiKernel_rotateReadyQueue
 * global_name:  tKernel_eiKernel_rotateReadyQueue
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_rotateReadyQueue(PRI taskPriority)
{
	return(irot_rdq(taskPriority));
}

/* #[<ENTRY_FUNC>]# eiKernel_getMicroTime
 * name:         eiKernel_getMicroTime
 * global_name:  tKernel_eiKernel_getMicroTime
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_getMicroTime(SYSUTM* p_systemMicroTime)
{
#ifdef TOPPERS_SUPPORT_GET_UTM
	return(get_utm(p_systemMicroTime));
#else /* TOPPERS_SUPPORT_GET_UTM */
	return E_NOSPT;
#endif /* TOPPERS_SUPPORT_GET_UTM */
}

/* #[<ENTRY_FUNC>]# eiKernel_lockCpu
 * name:         eiKernel_lockCpu
 * global_name:  tKernel_eiKernel_lockCpu
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_lockCpu()
{
	return(iloc_cpu());
}

/* #[<ENTRY_FUNC>]# eiKernel_unlockCpu
 * name:         eiKernel_unlockCpu
 * global_name:  tKernel_eiKernel_unlockCpu
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_unlockCpu()
{
	return(iunl_cpu());
}
/* #[<ENTRY_FUNC>]# eiKernel_exitKernel
 * name:         eiKernel_exitKernel
 * global_name:  tKernel_eiKernel_exitKernel
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiKernel_exitKernel()
{
	return(ext_ker());
}


/* #[<ENTRY_PORT>]# eiKernel
 * entry port: eiKernel
 * signature:  saKernel
 * context:    any
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiKernel_senseContext
 * name:         eiKernel_senseContext
 * global_name:  tKernel_eiKernel_senseContext
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseContext()
{
	return(sns_ctx());
}

/* #[<ENTRY_FUNC>]# eiKernel_senseLock
 * name:         eiKernel_senseLock
 * global_name:  tKernel_eiKernel_senseLock
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseLock()
{
	return(sns_loc());
}

/* #[<ENTRY_FUNC>]# eiKernel_senseDispatch
 * name:         eiKernel_senseDispatch
 * global_name:  tKernel_eiKernel_senseDispatch
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseDispatch()
{
	return(sns_dsp());
}

/* #[<ENTRY_FUNC>]# eiKernel_senseDispatchPendingState
 * name:         eiKernel_senseDispatchPendingState
 * global_name:  tKernel_eiKernel_senseDispatchPendingState
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseDispatchPendingState()
{
	return(sns_dpn());
}

/* #[<ENTRY_FUNC>]# eiKernel_senseKernel
 * name:         eiKernel_senseKernel
 * global_name:  tKernel_eiKernel_senseKernel
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseKernel()
{
	return(sns_ker());
}

/* #[<ENTRY_FUNC>]# eiKernel_senseDispatchPendingStateCPU
 * name:         eiKernel_senseDispatchPendingStateCPU
 * global_name:  tKernel_eiKernel_senseDispatchPendingStateCPU
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseDispatchPendingStateCPU(const void* p_exceptionInfomation)
{
	return(xsns_dpn((void *)p_exceptionInfomation));
}

/* #[<ENTRY_FUNC>]# eiKernel_senseTaskExceptionPendingStateCPU
 * name:         eiKernel_senseTaskExceptionPendingStateCPU
 * global_name:  tKernel_eiKernel_senseTaskExceptionPendingStateCPU
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline bool_t
eiKernel_senseTaskExceptionPendingStateCPU(const void* p_exceptionInfomation)
{
	return(xsns_xpn((void *)p_exceptionInfomation));
}


