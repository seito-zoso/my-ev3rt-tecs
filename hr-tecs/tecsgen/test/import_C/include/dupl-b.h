#ifndef _dupl_b_h_
#define  _dupl_b_h_
typedef int INT;
typedef int INT;
typedef void (*FP)(void);
typedef void (**FDP)(void);
typedef void (**FDP)(void);
struct tag_struct { int a; };
typedef volatile struct st_uart uart_t;
volatile uart_t a = 10;

typedef unsigned char uint8_t;
typedef struct tag_structB {
	volatile uint8_t a;
  } structB;

volatile uint8_t  a;

int unsigned const b;

const struct tag_structB c;
volatile struct tag_structB c;
struct tag_structB const c;
structB const d;
const structB d;
volatile int e;
extern int32_t f;
volatile int32_t g;
auto int32_t h;
register int32_t h;
// signed int32_t i;     // 修飾不可能
// long int32_t j;	// 修飾不可能
int32_t k;

// long double l;     // TECS には　long doulbe を扱う手段がない (double80_t がよいか?)

#endif  /* _dupl_b_h_ */

