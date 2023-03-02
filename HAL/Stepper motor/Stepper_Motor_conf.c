#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
#include "..\MCAL\DIO\dio.h"
#include "Stepper_Motor_int.h"
#include "Stepper_Motor_conf.h"
#include "Stepper_Motor_priv.h"


/*****************************************************************/
/* comment: Array of the struct ( StepperMotor ) from config.c	 	 */
/*****************************************************************/

          // if I want to change the port of ant pin ...............
StepperMotor ArrayOf_Steppermotor [ NUMBER_OF_STPRMOTORS ] =
{
	{ DIO_PORTA ,
		 DIO_PIN0 ,
		 DIO_PORTA , 
		 DIO_PIN1 ,
		 DIO_PORTA ,
		 DIO_PIN2 ,
		 DIO_PORTA ,
		 DIO_PIN3 }  
	
};