/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  led.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "led.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
* \Syntax          : void led_init(void)        
* \Description     : initialization function for LED module                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                            
* \Return value:   : None                                                                      
*******************************************************************************/
void led_init(void)
{
	dio_vidConfigChannel(LED_RED_PORT,LED_RED_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,OUTPUT);
	dio_vidConfigChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,OUTPUT);
}

/******************************************************************************
* \Syntax          : void led_on(led_id_t ledId)       
* \Description     : turn on LED with id                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledId	-> LED id                                                                            
* \Return value:   : None                                                                      
*******************************************************************************/
void led_on(led_id_t ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
		#if (LED_RED_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_LOW);
		#endif		
		break;
		
		case LED_GREEN:
		#if (LED_GREEN_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_LOW);
		#endif
		break;
		
		case LED_BLUE:
		#if (LED_BLUE_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_LOW);
		#endif
		break;
		
		case LED_YELLOW:
		#if (LED_YELLOW_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_HIGH);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_LOW);
		#endif
		break;
	}
}

/******************************************************************************
* \Syntax          : void led_off(led_id_t ledId)       
* \Description     : turn off LED with id                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledId	-> LED id                                                                            
* \Return value:   : None                                                                      
*******************************************************************************/
void led_off(led_id_t ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
		#if (LED_RED_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_RED_PORT,LED_RED_CHANNEL,STD_HIGH);
		#endif		
		break;
		
		case LED_GREEN:
		#if (LED_GREEN_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL,STD_HIGH);
		#endif
		break;
		
		case LED_BLUE:
		#if (LED_BLUE_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL,STD_HIGH);
		#endif
		break;
		
		case LED_YELLOW:
		#if (LED_YELLOW_CONNECTION == SOURCE)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_LOW);
		#elif (LED_RED_CONNECTION == SINK)
			dio_vidWriteChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL,STD_HIGH);
		#endif
		break;
	}
}

/******************************************************************************
* \Syntax          : void led_toggle(led_id_t ledId)       
* \Description     : toggle LED with id                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledId	-> LED id                                                                            
* \Return value:   : None                                                                      
*******************************************************************************/
void led_toggle(led_id_t ledId)
{
	switch(ledId)
	{
		case LED_RED:
		
			dio_vidFlipChannel(LED_RED_PORT,LED_RED_CHANNEL);	
		break;
		
		case LED_GREEN:
			dio_vidFlipChannel(LED_GREEN_PORT,LED_GREEN_CHANNEL);
		break;
		
		case LED_BLUE:
			dio_vidFlipChannel(LED_BLUE_PORT,LED_BLUE_CHANNEL);

		break;
		
		case LED_YELLOW:
			dio_vidFlipChannel(LED_YELLOW_PORT,LED_YELLOW_CHANNEL);
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: led.c
 *********************************************************************************************************************/
