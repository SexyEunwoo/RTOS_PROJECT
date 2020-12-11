#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

#define TRUE 1

static void HW_init(void);
static void Printf_test();

void main(void) {
	HW_init();
	
	// Hal_uart_put_char('\n');
	// putstr("Hello World!");

	Printf_test();

	/*
	uint32_t i = 100;
	while(i--)
	{
		uint8_t ch = Hal_uart_get_char();
		Hal_uart_put_char(ch);
	}
	*/

	while(TRUE);
}

static void HW_init(void)
{
	Hal_interrupt_init();
	Hal_uart_init();
}

static void Printf_test()
{
	char* str = "printf pointer test";
	char* nullptr = 0;
	uint32_t i = 5;

	debug_printf("%s%u\n", "Hello printf", 5);
	debug_printf("output string pointer: %s\n", str);
	debug_printf("%s is null pointer, %u number\n", nullptr, 10);
	debug_printf("%u = 5\n", i);
	debug_printf("dec=%u hex=%x\n", 0xff, 0xff);
	debug_printf("print zero %u \n", 0);
}
