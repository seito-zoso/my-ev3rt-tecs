/* tecs.h */
#ifndef	TECS_H_
#define	TECS_H_

#include <limits.h>
#include <stddef.h>
#include <tecs_stddef.h>

typedef unsigned char tecs_char;
/* typedef BOOL tecs_bool; */

#ifdef INT_LEAST64_MAX
typedef int_least64_t tecs_int64;
typedef uint_least64_t tecs_uint64;
#else
typedef struct { int_least32_t high; uint32_t low; } tecs_int64_t;
typedef struct { uint_least32_t high; uint32_t low; } tecs_uint64_t;
#endif

#ifdef INT_LEAST128_MAX
typedef int_least128_t tecs_int128;
typedef uint_least128_t tecs_uint128;
#else
typedef struct { tecs_int64_t high; tecs_uint64_t low; } tecs_int128_t;
typedef struct { tecs_uint64_t high; tecs_uint64_t low; } tecs_uint128_t;
#endif

typedef float tecs_float;
typedef double tecs_double;

#endif	/* ! TECS_H_ */
