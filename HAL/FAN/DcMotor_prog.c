/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Progam algorithm for DC Motor		*/
/*									 [prog.c]				    */
/****************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

/****************************************************************/
/********************* DIO Component DIRECTIVES *****************/
/****************************************************************/

#include "../../MCAL/DIO/dio.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "DcMotor_int.h"
#include "DcMotor_config.h"
#include "DcMotor_priv.h"
#include "../../MCAL/TIMER/TIMER0/TIMR0_int.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/



/****************************************************************/
/* Description    :  This function used to initialize DC Motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void DcMotor_voidInit( void )
{
	
/*****************************************************************/
/* !comment : Loop to initialize all DC Motors				 	 */
/*****************************************************************/
	
		dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);
		dio_vidConfigChannel(DIO_PORTB,DIO_PIN5,OUTPUT);
		dio_vidConfigChannel(DIO_PORTB,DIO_PIN6,OUTPUT);
	

}


/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving. 								*/
/*					 Inputs : Motor Number 	 ,  				*/
/*   						  Motor Direction[left ,right,stop] */
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after DC Motor  */
/*     				 initialized								*/
/****************************************************************/

void DcMotor_voidMove( u8 u8Direction , u8 speed  )
{
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN6,STD_HIGH);
	switch( u8Direction )
	{
		
		case STOP:			
							/** !comment : Turn off all wires			*/
							dio_vidWriteChannel(DIO_PORTB,DIO_PIN6,STD_LOW);
						
		break;
		
		
		case RIGHT:			
							/** !comment : Turn on right Turn off left	*/
						  dio_vidWriteChannel(DIO_PORTB,DIO_PIN5,STD_HIGH);
						  
							
		break;
		
		
		case LEFT:			
							/** !comment : Turn on left Turn off right	*/
						    dio_vidWriteChannel(DIO_PORTB,DIO_PIN5,STD_LOW);
							
		break;
		
		
		default:			
							/** !comment : Turn off all wires ( STOP )	*/
						   dio_vidWriteChannel(DIO_PORTB,DIO_PIN6,STD_LOW);
							
	}
	
	TIMER0_void_SetCompareVal(speed);
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/