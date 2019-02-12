/* namespace TOPPERS_JSP { */


/* TOPPERS/JSP 1.4.2 SH3 MS7727CP01　*/
/* enumのサイズ: 32ビット */

#define TMAX_LOGINFO (6)    
#define NULL ((void *)0)

#define _SH3_MS7727CP01_GNUDEV_

#ifdef _SH3_MS7727CP01_GNUDEV_

#define SH3

#define USE_CPU_EXCEPTION

#define ENUM enum32
	
#else

#undef USE_CPU_EXCEPTION

#endif

/* */

#ifdef M68K

#elif defined(SH3)

#elif defined(SH1)

#ifdef TOKIWA_SH1
#endif /* TOKIWA_SH1 */

#elif defined(ARMV4)

#elif defined(V850)

#elif defined(H8)

#elif defined(H8S)

#elif defined(MICROBLAZE)

#elif defined(IA32)

#define OMIT_VGET_TIM

#elif defined(TMS320C54X)

#elif defined(XSTORMY16)

#define OMIT_VGET_TIM			/* vxget_tim()は非サポート */

#elif defined(MIPS3) || defined(MIPS64)

#elif defined(M16C) && defined(OAKS16)

#elif defined(M16C) && defined(OAKS16_MINI)

#elif defined(LINUX)

#define OMIT_VGET_TIM

#elif defined(NIOS2)

#elif defined(M32C)

#endif



