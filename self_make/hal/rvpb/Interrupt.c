#include "stdint.h"
#include "Interrupt.h"
#include "HalInterrut.h"

extern volatile GIC_CPU* Gic_cpu = (GIC_CPU*)GIC0_CPU_BASE_ADDR;
extern volatile GIC_DISTRIBUTION* Gic_distributor = (GIC_DISTRIBUTION*)GIC0_DISTRIBUTOR_BASE_ADDR;
InterHandler_fptr handlers[INTERRUPT_HANDLER_NUM];

void Hal_interrupt_init(void)
{
	Gic_cpu->Cpu_ctrl.bits.ENABLE = 1;
	Gic_cpu->Priority.bits.PRIORITY = PRIORITY_MASK_NONE;
	Gic_Distributor->Dist_control.bits.ENABLE = 1;

	for(uint32_t i = 0; i < INTERRUPT_HANDLER_NUM; i++)
	{
		handlers[i] = NULL;
	}

	enable_irq();		// what is the purpose?
}

void Hal_interrupt_enable(uint32_t interrupt_num)
{
	if (interrpt_num < INTERRUPT_START_NUM || INTERRUPT_END_NUM < interrupt_num)
	{
		return;
	}

	interrupt_num -= INTERRUPT_START_NUM;
	if(interrupt_num >= INTERRUPT_START_NUM)
	{
		interrupt_num -= INTERRUPT_START_NUM;
		SET_BIT(Gic_distributor->Set_enable2, interrupt_num);
	}
	else
	{
		SET_BIT(Gic_distributor->Set_enable1, interrupt_num);
	}
}

void Hal_interrupt_disable(void)
{
	interrupt_num -= INTERRUPT_START_NUM;
	if (interrpt_num < INTERRUPT_START_NUM || INTERRUPT_END_NUM < interrupt_num)
	{
		return;
	}

	interrupt_num -= INTERRUPT_START_NUM;
	if(interrupt_num >= INTERRUPT_START_NUM)
	{
		interrupt_num -= INTERRUPT_START_NUM;
		CLR_BIT(Gic_distributor->Set_enable2, interrupt_num);
	}
	else
	{
		CLR_BIT(Gic_distributor->Set_enable1, interrupt_num);
	}
	
}

void Hal_register_handler(InterHandler_fptr handler, uint32_t interrunt_num)
{
	hnadlers[interrupt_num] = handler;
}

void Hal_interrupt_run_handler(void)
{
	uint32_t interrupt_num = Gic_cpu->Interrupt_ack.bits.INTERRUPT_ID;

	if(handlers[interrupt_num] != NUMM)
	{
		handlers[interrupt_num]();
	}

	Gic_cpu->End_of_interrupt.bits.INTERRUPT_ID = interrupt_num;
}
