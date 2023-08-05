/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02-22 08:45:20 PM
 * Author : abdoa
 */ 

//#include <avr/io.h>
#include "A:\avr_valeo\NTI_TEST_1\NTI_TEST_1\HAL\LED\led.h"
#include "A:\avr_valeo\NTI_TEST_1\NTI_TEST_1\HAL\Button\button.h"
int main(void)
{
	led_init();
	button_vidInit();
	
    /* Replace with your application code */
    while (1) 
    {
		if (Button_GetStatus(BUTTON0) == 1)
		{
			led_on(LED_BLUE);
			led_toggle(LED_RED);
			while(Button_GetStatus(BUTTON0) == 1);
			_delay_ms(300);
			
		}
		
		
		
		
    }
}

