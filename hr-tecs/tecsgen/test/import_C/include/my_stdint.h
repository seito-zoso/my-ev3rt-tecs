/*
 * You will find the next line causes tecsgen error.
 *     import_C( "stdint.h" );
 * This is because /usr/include is not in tecsgen's include path.
 * To avoid this, you have to add '-I /usr/include' as tecsgen's option.
 * Or you fill find the next line successes.
 *     import_C( "my_stdint.h" );
 * This is because /usr/include is in C-preprocessor's default include path.
 * I think latter way is better.
 * If you use cross compiler, stdint.h is not always in /usr/include.
 */

#include <stdint.h>
