#include "gpio.h"


// A helper function to initialize all GPIO related items.
void GPIO_STM32_configure(void) {

	// Configure GPIO
	RCC_AHBPeriphClockCmd(GPIO_STM32_LCD_BLED_PERIPH, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = GPIO_STM32_LCD_BLED_PIN;
	GPIO_Init(GPIO_STM32_LCD_BLED_PORT, &GPIO_InitStructure);

}
