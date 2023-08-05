#ifndef STPR_PRIV_H_
#define STPR_PRIV_H_





typedef struct steppermotor
{
	u8 Stepper_PA;
	u8 Stepper_Channel_A;
	
	u8 Stepper_PB;
	u8 Stepper_Channel_B;
	
	u8 Stepper_PC;
	u8 Stepper_Channel_C;
	
	u8 Stepper_PD;
	u8 Stepper_Channel_D;
	
}StepperMotor;


extern StepperMotor ArrayOf_Steppermotor [ NUMBER_OF_STPRMOTORS ] ;


#endif /* STPR_PRIV_H_ */