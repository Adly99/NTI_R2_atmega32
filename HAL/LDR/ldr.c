/*
 * ldr.c
 *
 * Created: 3/14/2023 8:14:53 PM
 *  Author: CONNECT
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "..\..\LIB\bit_math.h"
#include "..\..\LIB\std_types.h"
#include "..\LCD\lcd.h"
#include "..\..\MCAL\DIO\dio.h"
#include "..\..\MCAL\ADC\ADC_int.h"
#include "ldr.h"
#include "..\..\ECUAL\LED/LED.h"


void LDR_Function(u16 ldr)
{
	u8 ldr_arr[5];
	CLEAR_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
	ADC_voidStartConversion(DIO_PORTA,DIO_PIN0);///////////channel 0
	ldr=ADC_u16ReadADCInMV();
	if(ldr<1000 && ldr>650)
	{
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("Lighting Level: 2 ");
		/*itoa(ldr,ldr_arr,10);
		lcd_vidDisplyStr(ldr_arr);*/
		LED_ON(RED_LED);
		LED_ON(YELLOW_LED);
		_delay_ms(200);
		
	}
	else if (ldr<650 && ldr>300)
	{
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("Lighting Level: 1 ");
		/*itoa(ldr,ldr_arr,10);
		lcd_vidDisplyStr(ldr_arr);*/
		LED_ON(RED_LED);
		LED_OFF(YELLOW_LED);
		_delay_ms(200);
		
	}
	else if(ldr<300 && ldr>0)
	{
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("Lighting Level: 0 ");
		/*itoa(ldr,ldr_arr,10);
		lcd_vidDisplyStr(ldr_arr);*/
		LED_OFF(RED_LED);
		LED_OFF(YELLOW_LED);
		_delay_ms(200);
		
	}
	
	
}