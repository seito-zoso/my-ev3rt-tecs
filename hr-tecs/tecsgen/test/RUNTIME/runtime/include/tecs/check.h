/* tecs/check.h */
#ifndef TECS_CHECK_H_
#define TECS_CHECK_H_

#include "tecs/type.h"

TECS_STATIC_INLINE
int tecs_is_valid_int8(tecs_int8 value)
{
#if TECS_CHAR_BIT > 8
  return -128 <= (int)value && (int)value <= 127;
#else
  return 1;
#endif
}

TECS_STATIC_INLINE
int tecs_is_valid_uint8(tecs_uint8 value)
{
#if TECS_CHAR_BIT > 8
  return 0 <= value && value <= 255;
#else
  return 1;
#endif
}

TECS_STATIC_INLINE
int tecs_is_valid_int16(tecs_int16 value)
{
#if TECS_SHORT_BIT > 16
  return -32767-1 <= value && value <= 32767;
#else
  return 1;
#endif
}

TECS_STATIC_INLINE
int tecs_is_valid_uint16(tecs_uint16 value)
{
#if TECS_SHORT_BIT > 16
  return 0 <= value && value <= 0xffff;
#else
  return 1;
#endif
}

#endif  /* ! TECS_CHECK_H_ */
