/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for EXT0		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI0_int.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h" 



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT0_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXTI1_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#elif EXTI1_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXTI1_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	CLEAR_BIT(MCUCR , 2);/************************************* intialize int 0 / 1 / 2 in switch case ****************************************************/
	SET_BIT(MCUCR , 3);
	
	#elif EXTI1_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT1 in initialization function  **/
/** like : void EXT1_voidDisable(); 		  */
	CLEAR_BIT( GICR , 7 );
	SET_BIT(GIFR , 7 ) ;
	
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;	
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidEnable()
{
	
	SET_BIT( GICR , 7 );
	SET_BIT( GICR , 6 );
}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidDisable()
{
	
	CLEAR_BIT( GICR , 7 );
	CLEAR_BIT( GICR , 6 );
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		x = addresscpy;
	}
}

void EXT0_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		x = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT0_voidSetSignalch(u8 SenseCpy)
{
		/*  ( if / else if ) condition for Macros */
		if (EXTI1_SENSE_MODE == IOC )
		{
			SET_BIT(MCUCR , 0);
			CLEAR_BIT(MCUCR , 1);
		}
		else if (EXTI1_SENSE_MODE == RISING)
		{
			SET_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);	
		}	
		else if (EXTI1_SENSE_MODE == FALLING)
		{
			CLEAR_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
		}
		
		else if (EXTI1_SENSE_MODE == LOW_LEVEL)
		{
			CLEAR_BIT(MCUCR , 0);
			CLEAR_BIT(MCUCR , 1);			
		}

		
		else
		{
		
		}
		/* End ( if ) condition for Macros */


	
	
}

/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void )
{
	flagStatus ErrorStatus ;
	
	if( (GET_BIT(GIFR, 6)) == 1 )
	{
		
		ErrorStatus = LBTY_NOK ;
	}
	else if ( (GET_BIT(GIFR, 6)) == 0 )
	{
		
		ErrorStatus = LBTY_OK ;
	}
	
	return ErrorStatus ;
}
*/
/** Linker Problem solved  INT1*/ 
void __vector_2(void) __attribute__(( signal , used ));


void __vector_2(void) 
{
	/*CLI();*/
	/*SREG |= 1<<7;*/
	x();
	
}

/** Linker Problem solved INT0 */
void __vector_1(void) __attribute__(( signal , used ));


void __vector_1(void)
{
	/*CLI();*/
	/*SREG |= 1<<7;*/
	x();
	
}


void ESI_EN(void)
{
	SET_BIT(SREG,7);
}

void ESI_DIS(void)
{
	SET_BIT(SREG,7);
}



/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/