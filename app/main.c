/*
 * main.c
 *
 *  Created on: May 11, 2019
 *      Author: Boon
 */

#define	F_CPU 8000000UL
#include <avr/io.h>
#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include "TIMER0_int.h"
//#include <avr/interrupt.h>

#include "LCD_int.h"
#include <util/delay.h>



int firstReading = 1 ;
int ovf = 0 ;
int previousState = 0 ;
volatile unsigned char flag ;

float ton = 0 ;
float toff = 0 ;


void TOVF_APP (void)
/* Prototype for ISR of TIMER0 OVF */
// void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;
// void __vector_11 (void)
{
		ovf++;
}
// ISR(TIMER0_OVF_vect)
// {
// 
// }
void EXTI0_APP (void)
// void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
// void __vector_1 (void)
{
	if (flag == 0)            // put all condition
	{
		TIMER0_void_setTCNT0(0);   // TCNT0 = 0		
		ovf=0;	// starting timer ovf ==  0
		EXT0_voidSetSignalch(FALLING);   // SENSE FALLING
		flag = 1 ; 
	}
	else if (flag == 1)
		{	ton = (float)( (TCNT0 + (ovf * 256) )    * (float)  ( (float) 1024 / F_CPU ) );  // CALCULATE ton
			TIMER0_void_setTCNT0(0);

			ovf = 0;          // starting timer ovf ==  0
			flag = 2;
			EXT0_voidSetSignalch(RISING);		
			}
	else if (flag == 2)
		{
			toff = (float)(   (TCNT0 + (ovf * 256) )    * (float)  (  (float) 1024 / F_CPU) );
			TIMER0_void_setTCNT0(0);
			ovf=0;				 // starting timer ovf ==  0
			flag = 1;
			EXT0_voidSetSignalch(FALLING);
		}
	
	

}
/*ISR(INT0_vect)*/





int main()
{
	TIMER0_OVERFLOW_void_setCallBack(TOVF_APP);
	EXT0_voidCallBack(EXTI0_APP);
	int duty = 0 ;
	int freq = 0 ;
	float f = 0 ;
	DIO_voidInitialization();
	EXT0_voidInit();
	LCD_vidInit();

	TIMER0_void_intialization();

	TIMER0_void_overflowInterruptEnable();

	EXT0_voidEnable();
	GIE_voidEnable();
	/*	pre 1024 .. mode CTC "Duty 50%" .. F = fcpu/(pre* counts) = 30.5 HZ	*/
	TCCR2 = 0b00011111;
	OCR2 = 127;

	while(1)
	{
		duty = (100 * ton) /( ton + toff);
		f = 1 / (ton + toff); // Tperiod = TON + TOFF
		freq = (int) f ;
		LCD_vidSendCmd(0x80);
		LCD_vidWriteString((u8 *)"Freq = ");
		LCD_vidWriteChar((freq/100)+48);
		LCD_vidWriteChar(((freq/10)%10)+48);
		LCD_vidWriteChar((freq%10)+48);
		LCD_vidWriteString((u8 *)" HZ");
		LCD_vidGotoXY(2 , 0);
		LCD_vidWriteString((u8 *)  "Duty = ");
		LCD_vidWriteChar(( duty / 10 ) + 48);
		LCD_vidWriteChar(( duty % 10) + 48);
		LCD_vidWriteChar(' ');
		LCD_vidWriteChar('%');
	//_delay_ms(500);
	}
return 0;
}
