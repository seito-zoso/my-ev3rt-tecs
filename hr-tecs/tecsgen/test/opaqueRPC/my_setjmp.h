#ifndef my_setjmp_h__
#define my_setjmp_h__

/*
 * setjmp.h がうまく取り込めなかったため、ジェネレータの段階では仮の jmp_buf 型とする
 */

#ifdef TECSGEN
typedef int  jmp_buf[1];
#else
#include <setjmp.h>
#endif

#endif /* my_setjmp_h__ */
