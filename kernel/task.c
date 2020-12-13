#include "stdint.h"
#include "stdbool.h"

#include "ARMv7AR.h"
#include "task.h"

static KernelTcb_t	sTask_list[MAX_TASK_NUM];
static uint32_t		sAllocated_tcb_idx;
static uint32_t		sCurrent_tcb_idx;
static KernelTcb_t* Scheduler_round_robin_algorithm(void);
static KernelTcb_t* sCurrent_tcb;
static KernelTcb_t* sNext_tcb;
static __attribute__ ((naked)) void Restore_context(void);

void Kernel_task_init(void)
{
	sAllocated_tcb_idx = 0;
	sCurrent_tcb_idx = 0;

	for(uint32_t i = 0; i < MAX_TASK_NUM; i++)
	{
		sTask_list[i].stack_base = (uint8_t*)(TASK_STACK_START + (i * TASK_STACK_SIZE));
		sTask_list[i].sp = (uint32_t)(sTask_list[i].stack_base + USR_TASK_STACK_SIZE - 4);

		sTask_list[i].sp -= sizeof(KernelTaskContext_t);
		KernelTaskContext_t* ctx = (KernelTaskContext_t*)sTask_list[i].sp;
		ctx->pc = 0;
		ctx->spsr = ARM_MODE_BIT_SYS;
	}
}

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc)
{
	KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_idx++];
	
	if(sAllocated_tcb_idx > MAX_TASK_NUM)
	{
		return NOT_ENOUGH_TASK_NUM;
	}
	
	new_tcb->priority = PRIORITY_NORMAL;

	KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
	ctx->pc = (uint32_t)startFunc;

	return (sAllocated_tcb_idx - 1);
}

void Kernel_task_scheduler(void)
{
	sCurrent_tcb = &sTask_list[sCurrent_tcb_idx];
	sNext_tcb = Scheduler_round_robin_algorithm();

	Kernel_task_context_switching();
}

static KernelTcb_t* Scheduler_round_robin_algorithm(void)
{
	sCurrent_tcb_idx++;
	sCurrent_tcb_idx %= sAllocated_tcb_idx;

	return &sTask_list[sCurrent_tcb_idx];
}

static KernelTcb_t* Scheduler_priority_algorithm(void)
{
	for(uint32_t i = 0; i < sAllocated_tcb_idx; i++)
	{
		if(sTask_list[i].priority <= sTask_list[sCurrent_tcb_idx].priority)
		{
			return &sTask_list[i];
		}
	}

	return &sTask_list[sCurrent_tcb_idx];
}

void Kernel_task_start(void)
{
	sNext_tcb = &sTask_list[sCurrent_tcb_idx];
	Restore_context();
}

__attribute__ ((naked)) void Kernel_task_context_switching(void)
{
	__asm__ ("B Save_context");
	__asm__ ("B Restore_context");
}

static __attribute__ ((naked)) void Save_context(void)
{
	__asm__ ("PUSH {lr}");
	__asm__ ("PUSH {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}");
	__asm__ ("MRS r0, cpsr");
	__asm__ ("PUSH {r0}");

	__asm__ ("LDR r0, =sCurrent_tcb");
	__asm__ ("LDR r0, [r0]");
	__asm__ ("STMIA r0!, {sp}");
}

static __attribute__ ((naked)) void Restore_context(void)
{
	__asm__ ("LDR r0, =sNext_tcb");
	__asm__ ("LDR r0, [r0]");
	__asm__ ("LDMIA r0!, {sp}");

	__asm__ ("POP {r0}");
	__asm__ ("MSR cpsr, r0");
	__asm__ ("POP {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}");
	__asm__ ("POP {pc}");
}
