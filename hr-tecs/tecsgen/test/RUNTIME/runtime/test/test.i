# 1 "test.c"
# 1 "../include/tecs.h" 1
 



# 1 "tecs_config.h" 1
# 1 "../include/tecs/config/sh.h" 1
 










typedef long tecs_max_aligner_t;



# 1 "../include/tecs/config/gcc.h" 1
 























































# 65 "../include/tecs/config/gcc.h"



# 16 "../include/tecs/config/sh.h" 2







# 1 "tecs_config.h" 2

# 5 "../include/tecs.h" 2

# 1 "../include/tecs/machine.h" 1
 



# 1 "tecs_config.h" 1

# 5 "../include/tecs/machine.h" 2




# 17 "../include/tecs/machine.h"



# 6 "../include/tecs.h" 2

# 1 "../include/tecs/marshal.h" 1
 



# 1 "../include/tecs/type.h" 1
 



# 1 "tecs_config.h" 1

# 5 "../include/tecs/type.h" 2

# 1 "../include/tecs/define.h" 1
 



# 1 "/usr/local/sh-hitachi-elf/lib/gcc-lib/sh-hitachi-elf/2.95.3/include/stddef.h" 1 3






 







 

 




 


 





 


# 61 "/usr/local/sh-hitachi-elf/lib/gcc-lib/sh-hitachi-elf/2.95.3/include/stddef.h" 3


 





 


















 





 

 





















typedef int ptrdiff_t;









 




 

 


































typedef unsigned int size_t;






















 




 





























 


























typedef long int wchar_t;
























typedef unsigned int  wint_t;




 

 

# 317 "/usr/local/sh-hitachi-elf/lib/gcc-lib/sh-hitachi-elf/2.95.3/include/stddef.h" 3




 













 







# 5 "../include/tecs/define.h" 2







# 6 "../include/tecs/type.h" 2


typedef enum
{
  tecs_true = 1,
  tecs_false = 0
} tecs_bool;

typedef signed char tecs_int8;
typedef unsigned char tecs_uint8;

typedef signed short tecs_int16;
typedef unsigned short tecs_uint16;


typedef signed int tecs_int32;
typedef unsigned int tecs_uint32;










__extension__ typedef signed long long tecs_int64;
__extension__ typedef unsigned long long tecs_uint64;











typedef unsigned char tecs_char;
typedef signed char tecs_schar;
typedef unsigned char tecs_uchar;

typedef float tecs_float;

typedef double tecs_double;





# 5 "../include/tecs/marshal.h" 2

# 1 "../include/tecs/check.h" 1
 



# 1 "tecs_config.h" 1

# 5 "../include/tecs/check.h" 2


static __inline__ 
int tecs_is_valid_int8(tecs_int8 value)
{
  return -128 <= (int)value && (int)value <= 127;
}

static __inline__ 
int tecs_is_valid_uint8(tecs_uint8 value)
{
  return 0 <= value && value <= 255;
}

static __inline__ 
int tecs_is_valid_int16(tecs_int16 value)
{
  return -32767-1 <= value && value <= 32767;
}

static __inline__ 
int tecs_is_valid_uint16(tecs_uint16 value)
{
  return 0 <= value && value <= 0xffff;
}


# 6 "../include/tecs/marshal.h" 2


static __inline__ 
int tecs_marshal_int8(tecs_int8 value, unsigned char data[1])
{
  if (!tecs_is_valid_int8(value))
    return -1;




  *data = value & 0xff;
  return 0;
}

static __inline__ 
int tecs_marshal_uint8(tecs_uint8 value, unsigned char data[1])
{
  if (!tecs_is_valid_uint8(value))
    return -1;
  *data = value & 0xff;
  return 0;
}

static __inline__ 
int tecs_marshal_int16(tecs_int16 value, unsigned char data[2])
{
  if (!tecs_is_valid_int16(value))
    return -1;




  data[0] = ((unsigned int)value >> 8) & 0xff;
  data[1] = value & 0xff;
  return 0;
}

static __inline__ 
int tecs_marshal_uint16(tecs_uint16 value, unsigned char data[2])
{
  if (!tecs_is_valid_uint16(value))
    return -1;
  data[0] = (value >> 8) & 0xff;
  data[1] = value & 0xff;
  return 0;
}


# 7 "../include/tecs.h" 2



# 1 "test.c" 2


tecs_int8 a;
tecs_uint8 b;
tecs_int16 c;
tecs_uint16 d;
tecs_int32 e;
tecs_uint32 f;
tecs_int64 g;
tecs_uint64 h;

tecs_bool i;

tecs_float j;
tecs_double k;

