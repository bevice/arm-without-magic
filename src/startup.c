//
// Created by bevice on 10.12.2019.
//


#include "startup.h"


__attribute__((weak, alias("default_handler"))) void Reset_Handler();

extern const uint32_t __stack_top__;

__attribute__((section(".isr_vector"), __unused__))
const ISR_VECTOR_t isr_vector = {
    .stack_top = &__stack_top__,
    .reset = &Reset_Handler,
    .reserved0 = {0,0,0,0},
    .reserved1 = 0,
    .NMI = &NMI_Handler,
    .HardFault = &HardFault_Handler,
    .MemManage = &MemManage_Handler,
    .BusFault = &BusFault_Handler,
    .UsageFault = &UsageFault_Handler,
    .SVC = &SVC_Handler,
    .DebugMon = &DebugMon_Handler,
    .PendSV = &PendSV_Handler,
    .SysTick = &SysTick_Handler,

};



void default_handler(){
    while(1);
}


// Default handlers
