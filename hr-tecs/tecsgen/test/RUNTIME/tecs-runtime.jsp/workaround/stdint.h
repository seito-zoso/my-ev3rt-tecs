/* stdint.h */
#ifndef TOPPERS_STDINT_H_
#define TOPPERS_STDINT_H_

#ifdef __cplusplus
namespace std { /* namespace tr1 { */
#endif

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#ifdef INT64_LONG_LONG
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
#endif /* INT64_LONG_LONG */

typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef signed short int_least16_t;
typedef unsigned short uint_least16_t;
typedef signed int int_least32_t;
typedef unsigned int uint_least32_t;

#ifdef INT64_LONG_LONG
typedef signed long long int_least64_t;
typedef unsigned long long uint_least64_t;
#endif /* INT64_LONG_LONG */

typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef signed short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef signed int int_fast32_t;
typedef unsigned int uint_fast32_t;

#ifdef INT64_LONG_LONG
typedef signed long long int_fast64_t;
typedef unsigned long long uint_fast64_t;

typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#endif /* INT64_LONG_LONG */

typedef signed int intptr_t;
typedef unsigned int uintptr_t;

#ifdef __cplusplus
 /* } */ }
#endif

#if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS)

#define INT8_C(n)  (n)
#define UINT8_C(n) (n)
#define INT16_C(n)  (n)
#define UINT16_C(n) (n##u)
#define INT32_C(n)  (n##ll)
#define UINT32_C(n) (n##ull)
#define INTMAX_C(n)  (n##ll)
#define UINTMAX_C(n) (n##ull)

#endif

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

#define INT8_MAX  0x7f
#define INT8_MIN  (-INT8_MAX-1)
#define UINT8_MAX 0xff
#define INT16_MAX  0x7fff
#define INT16_MIN  (-INT16_MAX-1)
#define UINT16_MAX 0xffff
#define INT32_MAX  0x7fffffff
#define INT32_MIN  (-INT32_MAX-1)
#define UINT32_MAX 0xffffffff
#define INT64_MAX  0x7fffffffffffffff
#define INT64_MIN  (-INT64_MAX-1)
#define UINT64_MAX 0xffffffffffffffff

#define INT_LEAST8_MAX  0x7fff
#define INT_LEAST8_MIN  (-INT8_MAX-1)
#define UINT_LEAST8_MAX 0xffff
#define INT_LEAST16_MAX  0x7fffffff
#define INT_LEAST16_MIN  (-INT16_MAX-1)
#define UINT_LEAST16_MAX 0xffffffff
#define INT_LEAST32_MAX  0x7fffffffffffffff
#define INT_LEAST32_MIN  (-INT32_MAX-1)
#define UINT_LEAST32_MAX 0xffffffffffffffff

#define INT_FAST8_MAX  0x7fff
#define INT_FAST8_MIN  (-INT8_MAX-1)
#define UINT_FAST8_MAX 0xffff
#define INT_FAST16_MAX  0x7fffffff
#define INT_FAST16_MIN  (-INT16_MAX-1)
#define UINT_FAST16_MAX 0xffffffff
#define INT_FAST32_MAX  0x7fffffffffffffff
#define INT_FAST32_MIN  (-INT32_MAX-1)
#define UINT_FAST32_MAX 0xffffffffffffffff

#define INTMAX_MAX  0x7fffffffffffffff
#define INTMAX_MIN  (-INTMAX_MAX-1)
#define UINTMAX_MAX 0xffffffffffffffff

#define INTPTR_MAX  0x7fffffff
#define INTPTR_MIN  (-INTPTR_MAX-1)
#define UINTPTR_MAX 0xffffffff

#define SIZE_MAX  0xffffffff

#define PTRDIFF_MAX  0x7fffffff
#define PTRDIFF_MIN  (-PTRDIFF_MAX-1)

#define SIGATOMIC_MAX  0x7fffffff
#define SIGATOMIC_MIN  (-SIGATOMIC_MAX-1)

#define WCHAR_MAX  __WCHAR_MAX__
#if -1 * __WCHAR_MAX__ < 0
#define WCHAR_MIN  (-WCHAR_MAX-1)
#else
#define WCHAR_MIN  (WCHAR_MAX-WCHAR_MAX)
#endif

#endif

#endif	/* TOPPERS_STDINT_H_ */

#if defined(__cplusplus) && !defined(TOPPERS_USE_CNAME_)

using std::int8_t;
using std::uint8_t;
using std::int16_t;
using std::uint16_t;
using std::int32_t;
using std::uint32_t;

#ifdef USE_INT64
using std::int64_t;
using std::uint64_t;
#endif /* USE_INT64 */

using std::int_least8_t;
using std::uint_least8_t;
using std::int_least16_t;
using std::uint_least16_t;
using std::int_least32_t;
using std::uint_least32_t;

#ifdef USE_INT64
using std::int_least64_t;
using std::uint_least64_t;
#endif /* USE_INT64 */

using std::int_fast8_t;
using std::uint_fast8_t;
using std::int_fast16_t;
using std::uint_fast16_t;
using std::int_fast32_t;
using std::uint_fast32_t;

#ifdef USE_INT64
using std::int_fast64_t;
using std::uint_fast64_t;

using std::intmax_t;
using std::uintmax_t;
#endif /* USE_INT64 */

using std::intptr_t;
using std::uintptr_t;

#endif	/* defined(__cplusplus) && !defined(TOPPERS_USE_CNAME_) */
