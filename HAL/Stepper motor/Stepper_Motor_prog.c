
#include "Stepper_Motor_int.h"



/********************************************************************/
/* Description   :  This function is used to initialize Stepper Motor */
/*	          Configure output pins and clear them                                          */
/*				 Inputs : void			 				     	*/
/*					 return : void		 					    	*/
/********************************************************************/

void Stepper_Motor_void_int( void )
{	
	// Configure Output Pins
	for( u8 i = 0 ; i < NUMBER_OF_STPRMOTORS ; i++ )
	{
		dio_vidConfigChannel(ArrayOf_Steppermotor[i].Stepper_PA ,ArrayOf_Steppermotor[i].Stepper_Channel_A ,OUTPUT );
		dio_vidConfigChannel(ArrayOf_Steppermotor[i].Stepper_PB ,ArrayOf_Steppermotor[i].Stepper_Channel_B ,OUTPUT );
		dio_vidConfigChannel(ArrayOf_Steppermotor[i].Stepper_PC ,ArrayOf_Steppermotor[i].Stepper_Channel_C ,OUTPUT );
		dio_vidConfigChannel(ArrayOf_Steppermotor[i].Stepper_PD ,ArrayOf_Steppermotor[i].Stepper_Channel_D ,OUTPUT );
	}
	// Configure Clear Pins 
	for( u8 i = 0 ; i < NUMBER_OF_STPRMOTORS ; i++ )
	{
		dio_vidWriteChannel(ArrayOf_Steppermotor[i].Stepper_PA ,ArrayOf_Steppermotor[i].Stepper_Channel_A ,STD_LOW );
		dio_vidWriteChannel(ArrayOf_Steppermotor[i].Stepper_PB ,ArrayOf_Steppermotor[i].Stepper_Channel_B ,STD_LOW );
		dio_vidWriteChannel(ArrayOf_Steppermotor[i].Stepper_PC ,ArrayOf_Steppermotor[i].Stepper_Channel_C ,STD_LOW );
		dio_vidWriteChannel(ArrayOf_Steppermotor[i].Stepper_PD ,ArrayOf_Steppermotor[i].Stepper_Channel_D ,STD_LOW );
	}
}


/****************** FULL STEP ******************/
/* step	|	A	B	C	D                    */
/* 1	|	1	0	0	1                    */
/* 2	|	1	1	0	0                    */
/* 3	|	0	1	1	0                    */
/* 4	|	0	0	1	1                    */

/*           move cloclockwise             */
void StepperMotor_void_CW_Fullstep( u8 motor_num)
{
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
}


/*           move counter cloclockwise           */
void StepperMotor_void_CCW_Fullstep( u8 motor_num)
{
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);

	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );

	_delay_ms(10);


}


/********************** HALF STEP ****************/
/* step	|	A	B	C	D                    */
/* 1	|	1	0	0	1                    */
/* 2	|	1	0	0	0                    */
/* 3	|	1	1	0	0                    */
/* 4	|	0	1	0	0                    */
/* 5	|	0	1	1	0                    */
/* 6	|	0	0	1	0                    */
/* 7	|	0	0	1	1                    */
/* 8	|	0	0	0	1                    */


/*           move cloclockwise             */
void StepperMotor_void_CW_Halfstep( u8 motor_num)
{
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
}

/*           move counter cloclockwise             */
void StepperMotor_void_CCW_Halfstep( u8 motor_num)
{
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);

	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
	
	_delay_ms(10);
	
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_HIGH );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );

	_delay_ms(10);
	
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_HIGH );
	
	_delay_ms(10);	
}


void Stepper_Motor_void_stop( u8 motor_num)
{
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PA ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_A ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PB ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_B ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PC ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_C ,STD_LOW );
	dio_vidWriteChannel(ArrayOf_Steppermotor[motor_num].Stepper_PD ,ArrayOf_Steppermotor[motor_num].Stepper_Channel_D ,STD_LOW );
									   
}