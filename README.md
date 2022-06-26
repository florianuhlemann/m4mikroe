# m4mikroe
Open-source project for mikromedia for STM32 M4 (MikroE) running an STM32F407VGT6 chip. It is combined with an audio chip (VS1053) and an LCD display (MI0283QT-9A with ILI9341V controller). It also features an accelerometer (ADXL345) and an 8Mb serial flash memory (M25P80). A microSD card slot and a mini USB receptacle are added for I/O convencience.

## AC6 Setup
Install OpenSTM32 (AC6 Workspace) IDE. Then make sure the OpenOCD settings are correctly set as follows: Configuration Script "Automated Generation", Mode Setup Reset Mode "Softwaresystem reset" and Connection Setup Frequency "4 MHz".

![ac6_setup](https://user-images.githubusercontent.com/6698320/175802415-c651fcb8-cdb5-465e-8eb0-78a00bbf452a.png)
