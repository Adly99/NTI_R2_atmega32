#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL//DIO/dio.h"
#include "../MCAL//EXT/EXT_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton.h"
#include "../HAL/LCD/LCD.h"




int main(void)
{
	u8 duty  = 0 ;
	dio_vidConfigChannel(DIO_PORTB , DIO_PIN3, OUTPUT);
	
	TIMER0_void_Init();

	
	while (1)
	{
		for(duty=0; duty<255; duty++)
		{
			TIMER0_void_SetCompareVal(duty);  /*increase the LED light intensity*/
			_delay_ms(8);
		}
		for(duty=255; duty>1; duty--)
		{
			TIMER0_void_SetCompareVal(duty);  /*decrease the LED light intensity*/
			_delay_ms(8);
		}
	}

}