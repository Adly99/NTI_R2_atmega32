
#ifndef _ULTRASONIC_INT_H
#define _ULTRASONIC_INT_H

#include "..\..\MCAL\DIO\dio.h"  //DIO
#include "..\..\MCAL\GIE\GIE_int.h"  // general interrupt enable
#include "..\..\MCAL\TIMER\TIMER1\TIMER1_int.h"




/*trigger_pin set */
#define  Trigger_pin	DIO_PIN7
#define  Trigger_port   DIO_PORTC


// initiilize in main
void Ultrasonic_init();
void trigger(void) ;
u32 getdistance(void);
/***************************************************************/
void Isr_Timer_OV(void);
void Isr_Timer_ICU(void) ;

#endif