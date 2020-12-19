#ifndef _HAL_HALINTERRUPT_H_
#define _HAL_HALINTERRUPT_H_

#define INTERRUPT_HANDLER_NUM	255
typedef (void)(*InterHandler_fptr)(void);

void Hal_interrupt_init(void);
void Hal_interrupt_enable(uint32_t interrupt_num);
void Hal_interrupt_disable(uint32_t interrupt_num);
void Hal_register_handler(InterHandler_fptr handler, uint32_t interrupt_num);
void Hal_interrupt_run_handler(void);

#endif
