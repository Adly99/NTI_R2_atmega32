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



int main(void)
 {		
	 dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);  // OC0
	u8 i;
	led_init();
	TIMER0_void_Init();
	//TIMER0_void_SetCompareVal(128);  //OCR /*OCRn: Output Compare Register   ///The value in this register is compared with the content of the TCNTn register. When they are equal, the OCFn flag will get set.*/

///BUZZER
for(i=0;i<255;i++)
{
	TIMER0_void_SetCompareVal(i);
	_delay_ms(12);
}
    while (1) 
    {	
		led_on(LED_GREEN);  // TEST
	}
	return 0 ;
}


