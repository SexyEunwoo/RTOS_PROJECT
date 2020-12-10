#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

static void HW_init(void);

void main(void) {
	HW_init();
	
	Hal_uart_put_char('\n');
	putstr("Hello World!");
}

static void HW_init(void)
{
	Hal_uart_init();
}
