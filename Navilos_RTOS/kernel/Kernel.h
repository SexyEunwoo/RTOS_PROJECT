/*
 * Kernel.h
 *
 *  Created on: Oct 28, 2018
 *      Author: maanu
 */

#ifndef KERNEL_KERNEL_H_
#define KERNEL_KERNEL_H_

#include "task.h"

void Kernel_start(void);
void Kernel_yield(void);
<<<<<<< HEAD
=======
void Kernel_send_events(uint32_t event_list);
KernelEventFlag_t Kernel_wait_events(uint32_t waiting_list);
bool Kernel_send_msg(KernelMsgQ_t Qname, void* data, uint32_t count);
uint32_t Kernel_recv_msg(KernelMsgQ_t Qname, void* out_data, uint32_t count);
>>>>>>> parent of 6d310e7... RTOS-2020-12-18 Finished

#endif /* KERNEL_KERNEL_H_ */
