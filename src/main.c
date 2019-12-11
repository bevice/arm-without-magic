#include <stm32f1xx.h>

__attribute__((unused)) int var_a;
__attribute__((unused)) int var_b= 0;
__attribute__((unused)) int var_c= 0x1234;
void Reset_Handler() {
    //Импортируем символы, которые мы создали в скрпите линковки
    extern uint8_t __data_start__, __data_end__, __data_lma__, __bss_start__, __bss_end__;
    uint8_t *dst;
    //Обнулим сецию BSS
    dst = &__bss_start__;
    while (dst < &__bss_end__)
        *dst++ = 0;
    dst = &__data_start__;

    //Инициализируем переменные в .data данным из флеш-памяти
    uint8_t *src = &__data_lma__;
    while (dst < &__data_end__)
        *dst++ = *src++;

    //Разрешаем тактировать GPIOC на шине APB2
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    // Настраиваем GPIO Pin 13 как выход Push-Pull на максимальной частоте
    GPIOC->CRH |= GPIO_CRH_MODE13;
    while (1) {
        GPIOC->BSRR = GPIO_BSRR_BR13; // Устанавливаем ноль на выходе PIN_13
        GPIOC->BSRR = GPIO_BSRR_BS13; // А теперь устанавливаем 1
    }

}


