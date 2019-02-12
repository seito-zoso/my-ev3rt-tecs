/* tecs/machine.h */
#ifndef TECS_MACHINE_H_
#define TECS_MACHINE_H_

#include "tecs_config.h"

#ifndef __cplusplus
#define tecs_alignof(type)  offsetof(struct { char tecs_fake_; type tecs_value_; }, tecs_value_)
#else
template <typename Type>
struct tecs_alignof_helper
{
  char tecs_fake_;
  Type tecs_value_;
};
#define tecs_alignof(type)  offsetof(tecs_alignof_helper<type>, tecs_value_)
#endif

#endif  /* ! TECS_MACHINE_H_ */
