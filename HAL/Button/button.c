/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  button.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "button.h"

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
* \Syntax          : void Button_Init(void)        
* \Description     : initialize buttons HW                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                            
* \Return value:   : None                                
*******************************************************************************/
void button_vidInit(void)
{
	dio_vidConfigChannel(BUTTON0_PORT,BUTTON0_PIN,INPUT);
	dio_vidConfigChannel(BUTTON1_PORT,BUTTON1_PIN,INPUT);
	dio_vidConfigChannel(BUTTON2_PORT,BUTTON2_PIN,INPUT);
}

/******************************************************************************
* \Syntax          : button_status_t Button_GetStatus(button_id_t button)      
* \Description     : read button status by ID                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : button  -> button ID                                                                       
* \Return value:   : button_status_t  PRESSED
*                                     RELEASED                                  
*******************************************************************************/
button_status_t Button_GetStatus(button_id_t button)
{
	button_status_t status = RELEASED;
	switch (button)
	{
	case BUTTON0:
#if (BUTTON0_CONNECTION == PULL_DOWN)

		/*	PULL Down	*/
		if (dio_dioLevelReadChannel(BUTTON0_PORT,BUTTON0_PIN) == STD_HIGH)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}

#else
		/*	PULL UP	*/
		if (dio_dioLevelReadChannel(BUTTON0_PORT,BUTTON0_PIN) == STD_LOW)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}
#endif
		break;

	case BUTTON1:
#if (BUTTON1_CONNECTION == PULL_DOWN)

		/*	PULL Down	*/
		if (dio_dioLevelReadChannel(BUTTON1_PORT,BUTTON1_PIN) == STD_HIGH)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}

#else
		/*	PULL UP	*/
		if (dio_dioLevelReadChannel(BUTTON1_PORT,BUTTON1_PIN) == STD_LOW)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}
#endif
		break;

	case BUTTON2:
#if (BUTTON2_CONNECTION == PULL_DOWN)

		/*	PULL Down	*/
		if (dio_dioLevelReadChannel(BUTTON2_PORT,BUTTON2_PIN) == STD_HIGH)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}

#else
		/*	PULL UP	*/
		if (dio_dioLevelReadChannel(BUTTON2_PORT,BUTTON2_PIN) == STD_LOW)
		{
			status = PRESSED;
		}
		else
		{
			status = RELEASED;
		}
#endif
		break;
	}
	return status;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
