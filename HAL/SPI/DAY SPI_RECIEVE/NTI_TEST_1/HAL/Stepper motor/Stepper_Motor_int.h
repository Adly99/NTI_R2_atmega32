#ifndef STPR_INT_H_
#define STPR_INT_H_

#include "..\MCAL\DIO\dio.h"
#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
#include "Stepper_Motor_conf.h"
#include "Stepper_Motor_priv.h"

void Stepper_Motor_void_int( void );


void StepperMotor_void_CW_Fullstep( u8 motor_num);


void StepperMotor_void_CCW_Fullstep( u8 motor_num );


void StepperMotor_void_CW_Halfstep( u8 motor_num);


void StepperMotor_void_CCW_Halfstep( u8 motor_num);


void Stepper_Motor_void_stop( u8 motor_num);

#endif /* STPR_INT_H_ */