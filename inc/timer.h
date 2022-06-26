// TIMER library: This library provides timer functions and definitions for STM32F4 chip.


// Constants Definitions
#define    TIMER_STM32_TIMER_A_PERIOD   1000


// Variable Definitions
RCC_ClocksTypeDef                                RCC_Clocks;


// TIM Definitions
#define    TIMER_STM32_TIMER_A          TIM17
#define    TIMER_STM32_TIMER_A_PRIO     0x02
#define    TIMER_STM32_TIMER_A_IRQ      TIM17_IRQn
#define    TIMER_STM32_TIMER_A_PERIPH   RCC_APB2Periph_TIM17


// Function Declarations
void TIMER_STM32_configure(void);
void TIMER_STM32_timerAConfig(uint16_t period);
void TIMER_STM32_timerAStart(void);
void TIMER_STM32_timerAStop(void);
