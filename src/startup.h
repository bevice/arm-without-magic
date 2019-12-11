//
// Created by bevice on 10.12.2019.
//

#ifndef STM32_HAL_TEMPLATE_STARTUP_H
#define STM32_HAL_TEMPLATE_STARTUP_H

#include <stdint.h>


typedef void (*isr_routine)(void);

typedef struct  {
    const uint32_t * stack_top;
    const isr_routine reset;
    const isr_routine NMI;
    const isr_routine HardFault;
    const isr_routine  MemManage;
    const isr_routine BusFault;
    const isr_routine UsageFault;
    const uint32_t reserved0[4];
    const isr_routine SVC;
    const isr_routine DebugMon;
    const uint32_t reserved1;
    isr_routine PendSV;
    isr_routine SysTick;
    isr_routine WWDG;
    isr_routine PVD;
    isr_routine TAMPER;
    isr_routine RTC;
    isr_routine FLASH;
    isr_routine RCC;
    isr_routine EXTI0;
    isr_routine EXTI1;
    isr_routine EXTI2;
    isr_routine EXTI3;
    isr_routine EXTI4;
    isr_routine DMA1_Channel1;
    isr_routine DMA1_Channel2;
    isr_routine DMA1_Channel3;
    isr_routine DMA1_Channel4;
    isr_routine DMA1_Channel5;
    isr_routine DMA1_Channel6;
    isr_routine DMA1_Channel7;
    isr_routine ADC1_2;
    isr_routine USB_HP_CAN1_TX;
    isr_routine USB_LP_CAN1_RX0;
    isr_routine CAN1_RX1;
    isr_routine CAN1_SCE;
    isr_routine EXTI9_5;
    isr_routine TIM1_BRK;
    isr_routine TIM1_UP;
    isr_routine TIM1_TRG_COM;
    isr_routine TIM1_CC;
    isr_routine TIM2;
    isr_routine TIM3;
    isr_routine TIM4;
    isr_routine I2C1_EV;
    isr_routine I2C1_ER;
    isr_routine I2C2_EV;
    isr_routine I2C2_ER;
    isr_routine SPI1;
    isr_routine SPI2;
    isr_routine USART1;
    isr_routine USART2;
    isr_routine USART3;
    isr_routine EXTI15_10;
    isr_routine RTCAlarm;
    isr_routine USBWakeUp;
} ISR_VECTOR_t;

void default_handler(void);

__attribute__((weak, alias("default_handler"))) void NMI_Handler();

__attribute__((weak, alias("default_handler"))) void HardFault_Handler();
__attribute__((weak, alias("default_handler"))) void MemManage_Handler();
__attribute__((weak, alias("default_handler"))) void BusFault_Handler();
__attribute__((weak, alias("default_handler"))) void UsageFault_Handler();
__attribute__((weak, alias("default_handler"))) void SVC_Handler();
__attribute__((weak, alias("default_handler"))) void DebugMon_Handler();
__attribute__((weak, alias("default_handler"))) void PendSV_Handler();
__attribute__((weak, alias("default_handler"))) void SysTick_Handler();
__attribute__((weak, alias("default_handler"))) void WWDG_IRQHandler();
__attribute__((weak, alias("default_handler"))) void PVD_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TAMPER_IRQHandler();
__attribute__((weak, alias("default_handler"))) void RTC_IRQHandler();
__attribute__((weak, alias("default_handler"))) void FLASH_IRQHandler();
__attribute__((weak, alias("default_handler"))) void RCC_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI0_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI1_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI3_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI4_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel1_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel3_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel4_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel5_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel6_IRQHandler();
__attribute__((weak, alias("default_handler"))) void DMA1_Channel7_IRQHandler();
__attribute__((weak, alias("default_handler"))) void ADC1_2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USB_HP_CAN1_TX_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USB_LP_CAN1_RX0_IRQHandler();
__attribute__((weak, alias("default_handler"))) void CAN1_RX1_IRQHandler();
__attribute__((weak, alias("default_handler"))) void CAN1_SCE_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI9_5_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM1_BRK_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM1_UP_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM1_TRG_COM_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM1_CC_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM3_IRQHandler();
__attribute__((weak, alias("default_handler"))) void TIM4_IRQHandler();
__attribute__((weak, alias("default_handler"))) void I2C1_EV_IRQHandler();
__attribute__((weak, alias("default_handler"))) void I2C1_ER_IRQHandler();
__attribute__((weak, alias("default_handler"))) void I2C2_EV_IRQHandler();
__attribute__((weak, alias("default_handler"))) void I2C2_ER_IRQHandler();
__attribute__((weak, alias("default_handler"))) void SPI1_IRQHandler();
__attribute__((weak, alias("default_handler"))) void SPI2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USART1_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USART2_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USART3_IRQHandler();
__attribute__((weak, alias("default_handler"))) void EXTI15_10_IRQHandler();
__attribute__((weak, alias("default_handler"))) void RTCAlarm_IRQHandler();
__attribute__((weak, alias("default_handler"))) void USBWakeUp_IRQHandler();

#endif //STM32_HAL_TEMPLATE_STARTUP_H
