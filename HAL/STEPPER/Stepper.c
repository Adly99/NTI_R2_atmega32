/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Stepper.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
Stepper Steppers[NumberOfStepperMotors]={
	{DIO_PORTA,DIO_PIN4,DIO_PORTA,DIO_PIN5,DIO_PORTC,DIO_PIN4,DIO_PORTC,DIO_PIN5,4096,0},
};
#define StepDelay 5
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                                                                         
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Stepper_init(){
	for(u8 StepperInitCounter=0;StepperInitCounter<sizeof(Steppers)/sizeof(Stepper);StepperInitCounter++){
		dio_vidConfigChannel(Steppers[StepperInitCounter].FirstWirePort,Steppers[StepperInitCounter].FirstWirePin,OUTPUT);
		dio_vidConfigChannel(Steppers[StepperInitCounter].SecondWirePort,Steppers[StepperInitCounter].SecondWirePin,OUTPUT);
		dio_vidConfigChannel(Steppers[StepperInitCounter].ThirdWirePort,Steppers[StepperInitCounter].ThirdWirePin,OUTPUT);
		dio_vidConfigChannel(Steppers[StepperInitCounter].FourthWirePort,Steppers[StepperInitCounter].FourthWirePin,OUTPUT);
		
		dio_vidWriteChannel(Steppers[StepperInitCounter].FirstWirePort,Steppers[StepperInitCounter].FirstWirePin,STD_HIGH);
		dio_vidWriteChannel(Steppers[StepperInitCounter].SecondWirePort,Steppers[StepperInitCounter].SecondWirePin,STD_HIGH);
		dio_vidWriteChannel(Steppers[StepperInitCounter].ThirdWirePort,Steppers[StepperInitCounter].ThirdWirePin,STD_HIGH);
		dio_vidWriteChannel(Steppers[StepperInitCounter].FourthWirePort,Steppers[StepperInitCounter].FourthWirePin,STD_HIGH);		
		
		dio_vidWriteChannel(Steppers[StepperInitCounter].FirstWirePort,Steppers[StepperInitCounter].FirstWirePin,STD_LOW);
		dio_vidWriteChannel(Steppers[StepperInitCounter].FourthWirePort,Steppers[StepperInitCounter].FourthWirePin,STD_HIGH);
		_delay_ms(250);
		dio_vidWriteChannel(Steppers[StepperInitCounter].SecondWirePort,Steppers[StepperInitCounter].SecondWirePin,STD_LOW);
		dio_vidWriteChannel(Steppers[StepperInitCounter].FirstWirePort,Steppers[StepperInitCounter].FirstWirePin,STD_HIGH);
		_delay_ms(250);
		dio_vidWriteChannel(Steppers[StepperInitCounter].ThirdWirePort,Steppers[StepperInitCounter].ThirdWirePin,STD_LOW);
		dio_vidWriteChannel(Steppers[StepperInitCounter].SecondWirePort,Steppers[StepperInitCounter].SecondWirePin,STD_HIGH);
		_delay_ms(250);
		dio_vidWriteChannel(Steppers[StepperInitCounter].FourthWirePort,Steppers[StepperInitCounter].FourthWirePin,STD_LOW);
		dio_vidWriteChannel(Steppers[StepperInitCounter].ThirdWirePort,Steppers[StepperInitCounter].ThirdWirePin,STD_HIGH);
		_delay_ms(250);
		Steppers[StepperInitCounter].CurrentStep=3;
	}
}
void Stepper_moveFullStep(u8 StepperIndex,u8 Direction){
	if(Direction == StepperForward){
		switch(Steppers[StepperIndex].CurrentStep%4){
			case 3:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 0:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);			
			break;
			case 1:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 2:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
		}
		if (Steppers[StepperIndex].CurrentStep++ == Steppers[StepperIndex].StepperStepsNumberPerRev-1)
		{
			Steppers[StepperIndex].CurrentStep = 0;
		}
	}
	if(Direction == StepperReverse){
		switch(Steppers[StepperIndex].CurrentStep%4){
			case 1:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 2:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 3:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 0:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
		}
		if (Steppers[StepperIndex].CurrentStep-- == 0)
		{
			Steppers[StepperIndex].CurrentStep = Steppers[StepperIndex].StepperStepsNumberPerRev-1;
		}
	}
}
void Stepper_moveFullStepRev(u8 StepperIndex,u8 Direction){
	for(u16 moveFullStepRevCounter=0;moveFullStepRevCounter<Steppers[StepperIndex].StepperStepsNumberPerRev;moveFullStepRevCounter++){
		Stepper_moveFullStep(StepperIndex,Direction);
	}
}
void Stepper_moveHalfStep(u8 StepperIndex,u8 Direction){
	if(Direction == StepperForward){
		switch(Steppers[StepperIndex].CurrentStep%8){
			case 7:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 0:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 1:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 2:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 3:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 4:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 5:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 6:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;			
		}
		if (Steppers[StepperIndex].CurrentStep++ == (Steppers[StepperIndex].StepperStepsNumberPerRev*2)-1)
		{
			Steppers[StepperIndex].CurrentStep = 0;
		}
	}
	if(Direction == StepperReverse){
		switch(Steppers[StepperIndex].CurrentStep%8){
			case 1:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 2:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 3:dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 4:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 5:dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 6:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 7:dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].ThirdWirePort,Steppers[StepperIndex].ThirdWirePin,STD_HIGH);
			dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;
			case 0:dio_vidWriteChannel(Steppers[StepperIndex].FirstWirePort,Steppers[StepperIndex].FirstWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].FourthWirePort,Steppers[StepperIndex].FourthWirePin,STD_LOW);
			dio_vidWriteChannel(Steppers[StepperIndex].SecondWirePort,Steppers[StepperIndex].SecondWirePin,STD_HIGH);
			_delay_ms(StepDelay);
			break;		
		}
		if (Steppers[StepperIndex].CurrentStep-- == 0)
		{
			Steppers[StepperIndex].CurrentStep = (Steppers[StepperIndex].StepperStepsNumberPerRev*2)-1;
		}
	}
}
void Stepper_moveFullStepDeg(u8 StepperIndex, u8 Direction, u16 AngleInDegrees){
	for(u16 moveFullStepRevCounter=0;moveFullStepRevCounter<(u32)((((u32)Steppers[StepperIndex].StepperStepsNumberPerRev*60))/360);moveFullStepRevCounter++){
			Stepper_moveFullStep(StepperIndex,Direction);
		}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
