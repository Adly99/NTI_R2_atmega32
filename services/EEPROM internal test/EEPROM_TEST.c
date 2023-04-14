/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02 
 * Author : Abdelrhman Elsayed
 */ 


#include "..\MCAL\DIO\dio.h"
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"
#include "..\MCAL\EXTI\EXTI0_int.h"
#include "..\MCAL\ADC\ADC_int.h"
#include "..\MCAL\UART\uart.h"
#include "..\MCAL\GIE\GIE_int.h"
#include "..\MCAL\SPI\SPI_int.h"
#include "..\MCAL\I2C\TWI_init.h"
#include "..\MCAL\EEPROM\EEPROM_init.h"


int main(void)
 {	
	EEPROM_write(10,0x60);
	
    while (1) 
    {	

	}
	return 0 ;
}

