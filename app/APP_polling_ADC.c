/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02 
 * Author : Abdelrhman Elsayed
 */ 

//#include <avr/io.h>
#include "..\MCAL\DIO\dio.h"
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"
#include "..\MCAL\EXTI\EXTI0_int.h"
#include "..\MCAL\ADC\ADC_int.h"

int main(void)
 {	
	
	
	u8 string[5];
	u16 res;
    lcd_vidInit();
	ADC_voidInit();
	ADC_voidEnable();
	lcd_vidDisplyStr("ADC value");
    while (1) 
    {	
		lcd_vidSendCmd(0xc4);			/* LCD16x2 cursor position */
		res =ADC_u16ReadADCInMV();
		itoa(res,string,10);
		lcd_vidDisplyStr(string);
		lcd_vidDisplyStr(" ");
		_delay_ms(100);
		lcd_vidSendCmd(0X01);

		
 }
	return 0 ;
}

