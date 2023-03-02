/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02 
 * Author : Abdelrhman Elsayed
 */ 

//#include <avr/io.h>
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"
#include "..\MCAL\EXTI\EXTI0_int.h"

void LED_INT(void)
{
	led_off(LED_RED);
	_delay_ms(5000);
}
int main(void)
{	EXT0_voidCallBack(LED_INT);
	led_init();
	EXT0_voidInit();
	EXT0_voidEnable();
	
	ESI_EN();
	
    while (1) 
    {
		led_on(LED_RED);
		
		
    }
}

