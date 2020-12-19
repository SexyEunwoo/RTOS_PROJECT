#ifndef _HAL_RVPB_INTERRUPT_H_
#define _HAL_RVPB_ITNERRUPT_H_

#include "stdint.h"

typedef union Cpu_control
{
	uint32_t all;
	struct {
		uint32_t ENABLE:1;
		uint32_t RESERVED:31;
	} bits;
} Cpc_control;

typedef union Priority_mask
{
	uint32_t all;
	struct {
		uint32_t RESERVED0:4;
		uint32_t PRIORITY:4;
		uint32_t RESERVED1:24;
	} bits;
} Priority_mask;

typedef union Binary_point
{
	uint32_t all;
	struct {
		uint32_t BP:2;
		uint32_t RESERVED:30;
	} bits;
} Binary_point;

typedef union Interrupt_acknowledge
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT_ID:10;
		uint32_t CPU:3;
		uint32_t RESERVED:19;
	} bits;
} Interrupt_acknowledge;

typedef union End_of_interrupt
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT_ID:10;
		uint32_t CPU:3;
		uint32_t RESERVED:19;
	} bits;
} End_of_interrupt;

typedef union Running_interrupt
{
	uint32_t all;
	struct {
		uint32_t RESERVED0:4;
		uint32_t PRIORITY:4;
		uint32_t RESERVED1:24;
	} bits;
} Running_interrupt;

typedef union Highest_pending_interrupt
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT_ID:10;
		uint32_t CPU:3;
		uint32_t RESERVED:19;
	} bits;
} Highest_pending_interrupt;

typedef union Distributor_control
{
	uint32_t all;
	struct {
		uint32_t ENABLE:1;
		uint32_t RESERVED:31;
	} bits;
} DIstributor_control;

typedef union Controller_type
{
	uint32_t all;
	struct {
		uint32_t ID:5;
		uint32_t CPU:3;
		uint32_t RESERVED:24;
	} bits;
} Controller_type;

typedef union Set_enable1
{
	uint32_t all;
	struct {
		uint32_t ENABLE:32;
	} bits;
} Set_enable1;

typedef union Set_enable2
{
	uint32_t all;
	struct {
		uint32_t ENABLE:32;
	} bits;
} Set_enable2;

typedef union Clear_enable1
{
	uint32_t all;
	struct {
		uint32_t CLEAR:32;
	} bits;
} Clear_enable1;

typedef union Clear_enable2
{
	uint32_t all;
	struct {
		uint32_t CLEAR:32;
	} bits;
} Clear_enable2;

typedef union Set_pending1
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Set_pending1;

typedef union Set_pending2
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Set_pending2;

typedef union Clear_pending1
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Clear_pending1;

typedef union Clear_pending2
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Clear_pending2;

typedef union Active1
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Active1

typedef union Active2
{
	uint32_t all;
	struct {
		uint32_t INTERRUPT:32;
	} bits;
} Active2;

typedef struct GIC_CPU
{
	Cpu_control					Cpu_ctrl;
	Priority_mask				Priority;
	Binary_point				Bp;
	Interrupt_acknowledge		Interrupt_ack;
	End_of_interrupt			End_interrupt;
	Running_interrupt			Running;
	Highest_pending_interrupt	Highest_interrupt;
} GIC_CPU;

typedef struct GIC_DISTRIBUTION
{
	Distributor_control	Dist_control;
	Controller_type		Control_type;
	uint32_t			Reserved0[62];
	uint32_t			Reserved1;
	uint32_t			Set_enable1;
	uint32_t			Set_enable2;
	uint32_t			Reserved2[29];
	uint32_t			Reserved3;
	uint32_t			Clear_enable1;
	uint32_t			Clear_enable2;
	uint32_t			Reserved4[29];
	uint32_t			Reserved5;
	uint32_t			Set_pending1;
	uint32_t			Set_pending2;
	uint32_t			Reserved6[29];
	uint32_t			Reserved7;
	uint32_t			Clear_pending1;
	uint32_t			Clear_pending2;
	uint32_t			Reserved8[29];
	uint32_t			Reserved9;
	uint32_t			Active1;
	uint32_t			Active2;
} GIC_DISTRIBUTION;

#define GIC0_CPU_BASE_ADDR				0x1E000000
#define GIC0_DISTRIBUTOR_BASE_ADDR		0x1E001000
#define	GIC1_CPU_BASE_ADDR				0x1E010000
#define GIC1_DISTRIBUTOR_BASE_ADDR		0x1E011000
#define GIC2_CPU_BASE_ADDR				0x1E020000
#define GIC2_DISTRIBUTOR_BASE_ADDR		0x1E021000
#define GIC3_CPU_BASE_ADDR				0x1E030000
#define GIC3_DISTRIBUTOR_BASE_ADDR		0x1E031000

#define PRIORITY_MASK_NONE				0xF
#define INTERRUPT_START_NUM				32
#define INTERRUPT_END_NUM				95

#endif
