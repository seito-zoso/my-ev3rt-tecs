#ifdef TECSGEN
#define TOPPERS_SVC_CALL
#define TOPPERS_TARGET_SVC_H
#define while(n) return(n)
#define TOPPERS_SIL_H

#ifndef __attribute__
#define __attribute__(n)
#endif

#endif
#include <kernel.h>

extern void	tTask_start_task(intptr_t exinf);
extern void	tTask_start_exception(TEXPTN texptn, intptr_t exinf);

extern void tInitializeRoutine_start(intptr_t exinf);
extern void tTerminateRoutine_start(intptr_t exinf);

extern void tISR_start(intptr_t exinf);

extern void tCyclicHandler_start(intptr_t exinf);
extern void tAlarmHandler_start(intptr_t exinf);

