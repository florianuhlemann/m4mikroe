// GPIO library: This library provides GPIO functions and definitions for STM32F4 chip.


// GPIO Definitions
#define    GPIO_STM32_LCD_BLED_PERIPH     RCC_AHBPeriph_GPIOE
#define    GPIO_STM32_LCD_BLED_PORT       GPIOE
#define    GPIO_STM32_LCD_BLED_PIN        GPIO_Pin_9


// Function Declarations
void GPIO_STM32_configure(void);
