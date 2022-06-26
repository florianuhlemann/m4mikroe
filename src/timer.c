#include "stm32f4xx.h"
#include "timer.h"


void TIMER_STM32_configure(void) {

	// Configure Timers
	RCC_GetClocksFreq(&RCC_Clocks);
	TIMER_STM32_timerAConfig(TIMER_STM32_TIMER_A_PERIOD);
	TIMER_STM32_timerAStart();

}


void TIMER_STM32_timerAConfig(uint16_t period) {

    //Configure Timer
    RCC_APB2PeriphClockCmd(TIMER_STM32_TIMER_A_PERIPH, ENABLE);
    uint16_t myPrescalerValue = (RCC_Clocks.PCLK_Frequency / 1000000) - 1;

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = myPrescalerValue - 1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = period;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIMER_STM32_TIMER_A, &TIM_TimeBaseStructure);

    // Configure NVIC
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIMER_STM32_TIMER_A_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPriority = TIMER_STM32_TIMER_A_PRIO;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // Initialize Timer
    TIM_ClearITPendingBit(TIMER_STM32_TIMER_A, TIM_IT_Update);

}


void TIMER_STM32_timerAStart(void) {

    TIM_ITConfig(TIMER_STM32_TIMER_A, TIM_IT_Update, ENABLE);
    TIM_SetCounter(TIMER_STM32_TIMER_A, 0);
    TIM_Cmd(TIMER_STM32_TIMER_A, ENABLE);

}


void TIMER_STM32_timerAStop(void) {

    TIM_ITConfig(TIMER_STM32_TIMER_A, TIM_IT_Update, DISABLE);
    TIM_Cmd(TIMER_STM32_TIMER_A, DISABLE);

}


// Timer Interrupt Routine (TIMER_A)
void TIM17_IRQHandler(void) {

    if (TIM_GetITStatus(TIMER_STM32_TIMER_A, TIM_IT_Update) != RESET) {
        TIM_ClearITPendingBit(TIMER_STM32_TIMER_A, TIM_IT_Update);
        //do your work
	}

}






