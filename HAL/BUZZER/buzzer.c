/*
 * buzzer.c
 *
 * Created: 3/14/2023 7:27:53 PM
 *  Author: CONNECT
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "..\..\MCAL\DIO\dio.h"
#include "buzzer.h"


void buzzer_init(void)
{
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN6,OUTPUT);
}


void buzzer_on(void)
{
	dio_vidWriteChannel(DIO_PORTC,DIO_PIN6,STD_HIGH);
}
void buzzer_off(void)
{
	dio_vidWriteChannel(DIO_PORTC,DIO_PIN6,STD_LOW);
}