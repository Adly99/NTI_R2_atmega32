/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Dc Motors Pins configuration*/
/*             							[config.c] 				*/
/*								Link time configuration	in 		*/
/*										build process			*/
/****************************************************************/


#include "DcMotor_config.h"
#include "DcMotor_priv.h"
#include "..\LIB\bit_math.h"
#include "..\LIB\register.h"
#include "..\LIB\std_types.h"

/*****************************************************************/
/* !comment : Array of struct ( DC Motors ) from config.c	 	 */
/*****************************************************************/

DcMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] = 
{
	{DIO_u8_PIN_0 ,DIO_u8_PIN_7}  ,
	{DIO_u8_PIN_1 ,DIO_u8_PIN_17} ,
	{DIO_u8_PIN_8 ,DIO_u8_PIN_14} , 
	{DIO_u8_PIN_9 ,DIO_u8_PIN_10} , 
	{DIO_u8_PIN_2 ,DIO_u8_PIN_11}
	
	
};

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/