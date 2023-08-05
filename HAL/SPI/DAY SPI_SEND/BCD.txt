/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02-22 08:45:20 PM
 * Author : abdoa
 */ 

//#include <avr/io.h>
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"

int main(void)
{
// 	led_init();
// 		button_vidInit();
// 		lcd_vidInit();
// 		//u8 *name = "abdelrh";
// 		_delay_ms(20);
			u8 i;
// 				
// 	/*lcd_vidDisplyChar()*/
// 		//lcd_vidDisplyStr(name);
// 		//_delay_ms(100);
// 		//lcd_vidDisplyStr("elsay");
	seven_seg_init();
	
	

    while (1) 
    {
		for (i=0 ; i<10 ; i++)
		{
			seven_seg_write(i);
			_delay_ms(200);
		}


	

		
		
		
    }
}

