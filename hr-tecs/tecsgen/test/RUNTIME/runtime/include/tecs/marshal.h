/* tecs/marshal.h */
#ifndef TECS_MARSHAL_H_
#define TECS_MARSHAL_H_

#include <tecs/type.h>
#include <tecs/check.h>

#if 0

TECS_STATIC_INLINE
int tecs_marshal_int8(tecs_int8 value, unsigned char data[1])
{
  if (!tecs_is_valid_int8(value))
    return -1;
#ifndef TECS_TWOS_COMPLEMENT
  if (value < 0)
    value = ((-value & 0x7f) ^ 0xff) + 1;
#endif
  *data = value & 0xff;
  return 0;
}

TECS_STATIC_INLINE
int tecs_marshal_uint8(tecs_uint8 value, unsigned char data[1])
{
  if (!tecs_is_valid_uint8(value))
    return -1;
  *data = value & 0xff;
  return 0;
}

TECS_STATIC_INLINE
int tecs_marshal_int16(tecs_int16 value, unsigned char data[2])
{
  if (!tecs_is_valid_int16(value))
    return -1;
#ifndef TECS_TWOS_COMPLEMENT
  if (value < 0)
  value = (tecs_int16)(((-value & 0x7fff) ^ 0xffff) + 1);
#endif
  data[0] = ((unsigned int)value >> 8) & 0xff;
  data[1] = value & 0xff;
  return 0;
}

TECS_STATIC_INLINE
int tecs_marshal_uint16(tecs_uint16 value, unsigned char data[2])
{
  if (!tecs_is_valid_uint16(value))
    return -1;
  data[0] = (value >> 8) & 0xff;
  data[1] = value & 0xff;
  return 0;
}
#endif /* 0 */

#endif  /* ! TECS_MARSHAL_H_ */
