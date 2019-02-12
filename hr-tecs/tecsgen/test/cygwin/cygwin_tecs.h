#ifndef __cygwin_tecs_h__
#define __cygwin_tecs_h__

/* gcc-4 で多数の built-in ライブラリとの不整合の警告を消すため */
/* tecsgen の C_parser が読めない構文が多いため tecsgen 実行時は include しない */
#ifndef TECSGEN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#endif /* TECSGEN */

#include "kernel.h"
#include "tecs.h"
#include "tecs_pthread_adaptor.h"

#if 0

// tecs_rpc.h に移動
#ifdef INT_LEAST128_MAX
typedef int_least128_t tecs_int128;
typedef uint_least128_t tecs_uint128;
#else
typedef struct { int64_t high; uint64_t low; } int128_t;
typedef struct { uint64_t high; uint64_t low; } uint128_t;
#endif

// tecs_rpc.h に移動
#define E_RPC     (-67)
#define E_RESET   (-68)
#define E_MAGIC   (-69)
#endif

#endif /* __cygwin_tecs_h__ */


