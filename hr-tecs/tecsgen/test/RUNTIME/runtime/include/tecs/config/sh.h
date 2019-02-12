/* tecs/config/sh.h */
#ifndef TECS_CONFIG_SH_H_
#define TECS_CONFIG_SH_H_

#ifdef __GNUC__

#if defined __SH3E__ || defined __SH4_SINGLE_ONLY__
#define TECS_DOUBLE_FORMAT  IEC559_SINGLE
#endif

#ifndef TECS_MAX_ALIGNER_T_DEFINED
typedef long tecs_max_aligner_t;
#define TECS_MAX_ALIGNER_T_DEFINED
#endif

#include <tecs/config/gcc.h>

#else /* ! __GNUC__ */
#error sorry, not supported!
#endif

#endif  /* ! TECS_CONFIG_SH_H_ */
