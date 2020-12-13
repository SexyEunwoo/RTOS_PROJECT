#ifndef HAL_RVPB_TIMER_H_
#define HAL_RVPB_TIMER_H_

typedef union TimerXControl_t
{
	uint32_t all;
	struct {
		uint32_t OneShot:1;
		uint32_t TimerSize:1;
		uint32_t TimerPre:2;
		uint32_t Reserved0:1;
		uint32_t IntEnable:1;
		uint32_t TimerMode:1;
		uint32_t TimerEn:1;
		uint32_t Reserved1:24;
	} bits;
} TimerXControl_t;

typedef union TimerXRIS_t
{
	uint32_t all;
	struct {
		uint32_t TimerXRIS:1;
		uint32_t Reserved:31;
	} bits;
} TimerXRIS_t;

typedef union TimerXMIS_t
{
	uint32_t all;
	struct {
		uint32_t TimerXMIS:1;
		uint32_t Reserved:31;
	} bits;
} TimerXMIS_t;

typedef struct Timer_t
{
	uint32_t		timerxload;		// Goal
	uint32_t		timerxvalue;	// Reducing register
	TimerXControl_t	timerxcontrol;	// timer setup register
	uint32_t		timerxintclr;	// inform interrupt is done to
	TimerXRIS_t		timerXris;		// not used
	TimerXMIS_t		timerxmis;		// not used
	uint32_t		timerxbgload;	// not used
} Timer_t;

#define TIMER_CPU_BASE	0x10011000
#define TIMER_INTERRUPT	36

#define TIMER_FREERUNNING	0
#define TIMER_PERIOIC		1

#define TIMER_16BIT_COUNTER	0
#define TIMER_32BIT_COUNTER	1

#define TIMER_1MZ_INTERVAL	(1024 * 1024)

#endif
