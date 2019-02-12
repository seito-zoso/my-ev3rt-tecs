/* tecs/config/gcc.h */
#ifndef TECS_CONFIG_GCC_H_
#define TECS_CONFIG_GCC_H_

#define TECS_INLINE         __inline__
#define TECS_STATIC_INLINE  static __inline__

#define TECS_ASM            __asm__
#define TECS_ASM_VOLATILE   __asm__ volatile

#define TECS_RESTRICT       __restrict__

#if !defined TECS_LITTLE_ENDIAN && !defined TECS_BIG_ENDIAN
#ifdef  __LITTLE_ENDIAN__
#define TECS_LITTLE_ENDIAN  1
#else
#define TECS_BIG_ENDIAN     1
#endif
#endif

#define TECS_CHAR_BIT       8

#ifndef TECS_SHORT_BIT
#define TECS_SHORT_BIT      16
#endif

#ifndef TECS_INT_BIT
#define TECS_INT_BIT        32
#endif

#ifndef TECS_LONG_BIT
#define TECS_LONG_BIT       TECS_INT_BIT
#endif

#ifndef TECS_LLONG_BIT
#define TECS_LLONG_BIT      (TECS_LONG_BIT < 64 ? 64 : TECS_LONG_BIT)
#endif

#ifndef TECS_POINTER_BIT
#define TECS_POINTER_BIT    32
#endif

#ifndef TECS_FLOAT_FORMAT
#define TECS_FLOAT_FORMAT   TECS_IEC559_SINGLE
#endif

#ifndef TECS_DOUBLE_FORMAT
#define TECS_DOUBLE_FORMAT  TECS_IEC559_DOUBLE
#endif

#ifndef TECS_LDOUBLE_FORMAT
#define TECS_LDOUBLE_FORMAT TECS_IEC559_DOUBLE
#endif

#define TECS_TWOS_COMPLEMENT  1

#ifndef TECS_MAX_ALIGNER_T_DEFINED
typedef union
{
  long long ll;
  double d;
  long double ld;
} tecs_max_aligner_t;
#define TECS_MAX_ALIGNER_T_DEFINED
#endif

#endif  /* ! TECS_CONFIG_GCC_H_ */
