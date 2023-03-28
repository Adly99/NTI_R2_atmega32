
#include "ULTRASONIC_int.h"




u16 OV_counter  = 0 ;
u8 ICU_states = 0 ;
u32 distance = 0 ;


/*********** Ultrasonic_init ***********/
void Ultrasonic_init()
{
	TIMER1_void_SetCAPTURECallBack(Isr_Timer_ICU);
	TIMER1_void_SetOVCallBack(Isr_Timer_OV) ;
	TIMER1_void_Init();
	TIMER1_void_EnableOVInt();
	TIMER1_void_EnableICInt() ;
	GIE_voidEnable();
	dio_vidConfigChannel(Trigger_port,Trigger_pin,OUTPUT) ;
}


/*Timer overflow callback function */
void Isr_Timer_OV()
{
	OV_counter++ ;
}

/*Timer input capture unit call back func function */
void Isr_Timer_ICU()
{
	if(ICU_states == 0)
	{
		
		TIMER1_void_SetTimerReg(0);
		OV_counter = 0 ;
		ICU_states = 1 ;
		// change edge of ICU TO falling
		ICU_voidSetSignalch(FALLING) ;
	}
	else
	{
		// 65535 max of timer1 , d = v * time -> v = 34300 cm/s   and  time = total number of time1 / 2* F_CPU
		
		distance = ( ((OV_counter * 65535) + ICR1) *  1024 * 34300.0) / (2*F_CPU) ;
		OV_counter = 0 ;
		ICU_states = 0 ;
		ICU_voidSetSignalch(RISING) ;
	}
}

/* send the trigger */
void trigger(void)
{
	dio_vidWriteChannel(Trigger_port,Trigger_pin,STD_HIGH);      // portd  pin 7   high
	_delay_us(10) ;
	dio_vidWriteChannel(Trigger_port,Trigger_pin,STD_LOW) ;		// portd  pin 7   low
	
	// Clear Timer counter
	TIMER1_void_SetTimerReg(0 ) ; 			//TCNT0 ==0 
	ICU_voidSetSignalch(RISING) ;
	SET_BIT(TIFR , ICF1);	// Clear ICP flag (Input Capture flag)
	SET_BIT(TIFR , TOV1);	// Clear Timer Overflow flag
}


u32 getdistance(void)
{
	u32 distance_t =0;
	distance_t = distance;
	
	return distance_t;
}




