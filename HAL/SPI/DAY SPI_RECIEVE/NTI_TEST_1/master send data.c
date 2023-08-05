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


int main(void)
 {	
 
	 led_init();
	 SPI_MASTER_init();
	/*set SS to high */
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
    while (1) 
    {	
		
		SPI_TRANSEV_BYTE('a');
		_delay_ms(1000);

	}
	return 0 ;
}

