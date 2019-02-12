/* tecs.h */
#ifndef	TECS_H_
#define	TECS_H_

/* gcc-4 で多数の built-in ライブラリとの不整合の警告を消すため */
/* tecsgen の C_parser が読めない構文が多いため tecsgen 実行時は include しない */
#ifndef TECSGEN
// #if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#endif /* TECSGEN */

#include <limits.h>
#include <stddef.h>
#include <t_stddef.h>

typedef unsigned char tecs_char;
typedef BOOL tecs_bool;

#ifdef INT_LEAST64_MAX
typedef int_least64_t tecs_int64_t;
typedef uint_least64_t tecs_uint64_t;
#else
typedef struct { long high; long low; } tecs_int64_t;
typedef struct { long high; long low; } tecs_uint64_t;
#endif

#ifdef INT_LEAST128_MAX
typedef int_least128_t tecs_int128;
typedef uint_least128_t tecs_uint128;
#else
typedef struct { tecs_int64_t high; tecs_uint64_t low; } tecs_int128_t;
typedef struct { tecs_uint64_t high; tecs_uint64_t low; } tecs_uint128_t;
#endif

/*
typedef float tecs_float;
typedef double tecs_double;
*/
typedef float  float32_t;
typedef double double64_t;

#define Inline  static inline

#endif	/* ! TECS_H_ */
