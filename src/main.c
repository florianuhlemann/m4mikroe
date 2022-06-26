#include "stm32f4xx.h"
#include "helper_stm32.h"
#include "gpio_stm32.h"
#include "timer_stm32.h"
			

int myVar = 0;


int main(void) {

	HELPER_STM32_initSystemClocks();
	GPIO_STM32_configure();
	TIMER_STM32_configure();

}
