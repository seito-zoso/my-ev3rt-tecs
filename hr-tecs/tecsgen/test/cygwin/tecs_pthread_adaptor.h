#ifndef _tecs_pthread_adaptor_h_
#define _tecs_pthread_adaptor_h_

/*
 * pthread.h を tecsgen が取込めないための暫定対策
 * pthread.h に含まれる union に対応していないため、取込むことができない
 */

//#ifdef TECSGEN
#if 0
/* tecsgen から読み込まれている */

typedef intptr_t  pthread_t;
typedef intptr_t  pthread_mutex_t;
//typedef struct    { int_t a; int_t b; }  pthread_once_t;
typedef intptr_t  pthread_once_t;
typedef intptr_t  pthread_cond_t;

#else
/* tecsgen 以外 (gcc) から読み込まれている */

#include "pthread.h"

#endif

#endif /* _tecs_pthread_adaptor_h_ */
