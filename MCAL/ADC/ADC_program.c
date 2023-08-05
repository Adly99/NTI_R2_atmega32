/************************************************************/
/* 	Author 	 	 :											*/
/* 	Date   		 :											*/
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"

#include "..\HAL\LED\led.h"
/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/
volatile pf y;

/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */

/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{		dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,INPUT);

		ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
		ADCSRA = 0x86;			/* Enable ADC, fr/128  */
		
	
	/* End ( if ) condition for Macros */	
	
	
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
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

void ADC_voidAutoTrigger()
{
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); enable or disable for this mode __ adc auto trigger enable 	**/
    SET_BIT( ADCSRA , 5 );
		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT  ( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0         
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH       
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );	
	#endif
	/* End ( if ) condition for Macros */
}

void ADC_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		y = addresscpy;
	}
}
/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(void)
{		u16 mv_result;
		ADC_voidStartConversion();
		while(CHECK_BIT(ADCSRA,4));  //bit 4 is ADIF IS ADC interrupt flag
		SET_BIT(ADCSRA,4); // clear ADIF
		mv_result = ADCL ;
		mv_result |= (ADCH << 8); // we use ADLAR = 0 	

	return mv_result;
	
}

u16 ADC_u16ReadADCInMV_INTERRUPT(void)
{		u16 mv_result;
	ADC_voidStartConversion();
	mv_result = ADCL ;
	mv_result |= (ADCH << 8); // we use ADLAR = 0

	return mv_result;
	
}


// void ADC_voidCallBack(pf addresscpy)
// {
// 	if(addresscpy != NULL)
// 	{
// 		y = addresscpy;
// 	}
// }

// /** Linker Problem solved INT0 */
// void __vector_16(void) __attribute__(( signal , used ));
// 
// void __vector_16(void)
// {			
// 			u8 String[5];
// 			u16 mv_result = ADCL ;

// 			mv_result |= (ADCH << 8); // we use ADLAR = 0										
// 	 		lcd_vidGotoRowColumn(1,1);
// 	 		itoa(mv_result,String,10);	/* Integer to string conversion */
// 	 		lcd_vidDisplyStr(String);
// 	 		lcd_vidDisplyStr(" ");
// 			ADC_voidStartConversion();
// 
// }

void __vector_16(void) __attribute__(( signal , used ));

void __vector_16(void)
{
	
	y();

}
/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/