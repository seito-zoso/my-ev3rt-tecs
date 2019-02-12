/* tecs/type.h */
#ifndef TECS_TYPE_H_
#define TECS_TYPE_H_

#include "tecs_config.h"
#include <tecs/define.h>

typedef int int_t;

typedef enum
{
  true = 1,
  false = 0
} tecs_bool;

typedef unsigned char  char_t;
typedef signed char tecs_int8;
typedef unsigned char tecs_uint8;

typedef signed short tecs_int16;
typedef unsigned short tecs_uint16;

#if TECS_INT_BIT >= 32
typedef signed int tecs_int32;
typedef unsigned int tecs_uint32;
#else
typedef signed long tecs_int32;
typedef unsigned long tecs_uint32;
#endif

#if 0

#if TECS_LONG_BIT >= 64
typedef signed long tecs_int64;
typedef unsigned long tecs_uint64;
#elif TECS_LLONG_BIT >= 64
# ifdef __GNUC__
__extension__ typedef signed long long tecs_int64;
__extension__ typedef unsigned long long tecs_uint64;
# else
typedef signed long long tecs_int64;
typedef unsigned long long tecs_uint64;
# endif
#endif

#endif /* 0 */

#if TECS_INTMAX_BIT >= 128
typedef int128_t tecs_int128;
typedef uint128_t tecs_uint128;
#endif

typedef unsigned char tecs_char;
typedef signed char tecs_schar;
typedef unsigned char tecs_uchar;

typedef float tecs_float;
#if TECS_DOUBLE_FORMAT >= TECS_IEC559_DOUBLE
typedef double tecs_double;
#else
typedef long double tecs_double;
#endif

#endif  /* ! TECS_TYPE_H_ */
