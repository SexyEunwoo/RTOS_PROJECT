#include "stdint.h"
#include "HalUart.h"

static void HW_init(void);

void main(void)
{
	HW_init();

	uint32_t i = 100;
	while(i--)
	{
		Hal_uart_put_char('N');
	}
}

static void HW_init(void)
{
	Hal_uart_init();
}
