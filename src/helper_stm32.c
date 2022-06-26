#include "stm32f4xx.h"
#include "helper_stm32.h"


// An init function to collect all system configurations in a single place.
void HELPER_STM32_initSystemClocks(void) {

	// Reset config and disable external clock sources
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_OFF);
	RCC_LSEConfig(RCC_LSE_OFF);

	// Enable internal clock sources and wait until ready
	RCC_HSICmd(ENABLE);
	RCC_LSICmd(ENABLE);
	RCC_HSI14Cmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_HSIRDY)) { /* wait until ready */ }
	while (!RCC_GetFlagStatus(RCC_FLAG_LSIRDY)) { /* wait until ready */ }
	while (!RCC_GetFlagStatus(RCC_FLAG_HSI14RDY)) { /* wait until ready */ }

	// Configure PLL to use HSI and wait until ready
	RCC_PLLCmd(DISABLE);
	RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_12);
	RCC_PLLCmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_PLLRDY)) { /* wait until ready */ }

	// Configure system clocks to use PLL clock source and configure HSI14 for ADC
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	RCC_PCLKConfig(RCC_HCLK_Div1);
	RCC_ADCCLKConfig(RCC_ADCCLK_HSI14);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK); //useful?
	
}


// A function to activate native bootloader for STM32F407
void HELPER_STM32_activateBootloader(void) {

	//do nothing yet

}


// A delay function based purely on the performance of the microprocessor.
void delayMilliseconds (int milliseconds) {

	uint64_t counter = 2175 * milliseconds; //for 48MHz setting
	while (counter > 0) {
		counter--;
	}

}

