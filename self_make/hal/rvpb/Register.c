#include "Uart.h"
#include "Interrupt.h"

volatile PL011_t* Uart0 = (PL011_t*)UART0_BASE_ADDR;
volatile PL011_t* Uart1 = (PL011_t*)UART1_BASE_ADDR;
volatile PL011_t* Uart2 = (PL011_t*)UART2_BASE_ADDR;
volatile PL011_t* Uart3 = (PL011_t*)UART3_BASE_ADDR;

volatile GIC_CPU* Gic_cpu = (GIC_CPU*)GIC0_CPU_BASE_ADDR;
volatile GIC_DISTRIBUTION* Gic_distributor = (GIC_DISTRIBUTION*)GIC0_DISTRIBUTOR_BASE_ADDR;
