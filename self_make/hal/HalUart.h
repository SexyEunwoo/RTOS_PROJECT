#ifndef _HAL_HALUART_H_
#define _HAL_HALUART_H_

#include "stdint.h"

void Hal_uart_init(void);
uint8_t Hal_uart_get_char(void);
void Hal_uart_put_char(uint8_t ch);

#endif
