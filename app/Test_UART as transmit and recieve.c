/*
 * NTI_TEST_1.c
 *
 * Created: 2023-03 
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

int main(void)
 {	
	 UART_Init(UART_BAUDRATE_9600);
	 led_init();
	 u8 read = 0;
	 
	
    while (1) 
    {	
		read = UART_ReceiveChr();
		if( read == '5')
		{
			led_on(LED_BLUE);
		}
		
		if( read == '8')
		{
			led_off(LED_BLUE);
		}		
		UART_TransmitChr('b');
	
	}
	return 0 ;
}


