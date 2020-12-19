#include "Uart.h"
#include "HalUart.h"
#include "stdint.h"
#include "Register.h"

extern volatile PL011_t* Uart0;

void Hal_uart_init(void)
{
	Uart0->uartcr.bits.UARTEN = 0;	// UART disable
	Uart0->uartcr.bits.TXE = 1;		// Transmit enable
	Uart0->uartcr.bits.RXE = 1;		// Recevice enable
	Uart0->uartcr.bits.UARTEN = 1;	// UART enable
}

uint8_t Hal_uart_get_char(void)
{
	uint32_t ret;

	while(Uart0->uartfr.bits.RXFE);

	ret = Uart0->uartdr.all;

	if(ret & 0xFFFFFF00)
	{
		Uart0->uartrsr.all = 0xFF;
		return 0;
	}

	return (uint8_t)(ret & 0x000000FF);
}

void Hal_uart_put_char(uint8_t ch)
{
	while(!Uart0->uartfr.bits.TXFE);
	Uart0->uartdr.bits.DATA = ch;
}
