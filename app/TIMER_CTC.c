/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02 
 * Author : Abdelrhman Elsayed
 */ 

//#include <avr/io.h>
#include "..\MCAL\DIO\dio.h"
#include "..\MCAL\GIE\GIE_int.h"
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"
#include "..\MCAL\EXTI\EXTI0_int.h"
#include "..\MCAL\ADC\ADC_int.h"
#include "..\MCAL\TIMER\TIMR0_int.h"


u8 counter = 0 ;

void LED_INTERRUPT(void)
{	counter++;
	if (counter > 100)
	{
		led_toggle(LED_RED);
		counter = 0;
	}
	
}


int main(void)
 {
	 TIMER0_void_SetCTCCallBack(LED_INTERRUPT);	
	led_init();
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(126);
	TIMER0_void_EnableCTCInt();
	GIE_voidEnable();
    while (1) 
    {	
		led_on(LED_GREEN);
	}
	return 0 ;
}


