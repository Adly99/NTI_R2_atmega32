/*
 * lm_35.c
 *
 * Created: 3/14/2023 8:37:14 PM
 *  Author: CONNECT
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "..\..\LIB\bit_math.h"
#include "..\..\LIB\std_types.h"

#include "LM35.h"
#include "..\LCD\lcd.h"
#include "..\..\MCAL\DIO\dio.h"
#include "..\..\MCAL\ADC\ADC_int.h"

u16 LM_35_Function(void)
{
	u16 lm;
	char lm_arr[5];
	SET_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
	ADC_voidStartConversion();//////////////////////////////change the channel to channel 1 for LM35 sensor
	lm=ADC_u16ReadADCInMV();	//////////////polling ADC for LM-35
	lm=(lm/10)+20;
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("LM value = ");
	itoa(lm,lm_arr,10);
	lcd_vidDisplyStr(lm_arr);
	lcd_vidDisplyStr(" C ");
	_delay_ms(200);
	return lm;
	
}