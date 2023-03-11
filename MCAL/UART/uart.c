/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "uart.h"
#include "uart_reg.h"
#include "..\MCAL\DIO\dio.h"
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
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;             //USART BAUD rate register low
	UART_UBRRH_REG = (u8)(baudRate>>8);			//USART BAUD rate register high

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	
	
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;  // 

	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	 RXC */
	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	TXC */
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/
void UART_TransmitChr(u8 data)
{
	 // Wait until transmission Register Empty -- Wait for UDR transmit buffer
   while(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO) == 0);
	/* Put data into buffer*/
	UART_UDR_REG = data;
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{
	/*Wait for UDR receive buffer to be filled with data*/
  	  while(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)==0);
	/*Receive data from UDR receive buffer*/
	return UART_UDR_REG;
}

/***************************** RECIEVE DATA ***************************/
u8 UART_TX_BUFFER[1000];
u16 byte_index=	0	;

void UART_TX_STR(u8 *str)
{		u16 i = 0 ;
		while(str[i] != 0)
		{
			UART_TX_BUFFER[i]  = str[i];
			i++;
		}
		UART_TX_BUFFER[i] = NULL;	
	UART_UDR_REG = UART_TX_BUFFER[byte_index];
}




/************************************************************************************/
void UART_TransmitStr(u8 *ptr)
{
	while(*ptr != 0)
	{
		UART_TransmitChr(*ptr);
		ptr++;
		_delay_ms(50);
	}
}
/*******************************************************************************/
void __vector_15(void) __attribute__(( signal , used ));

void __vector_15(void)
{
	
	byte_index++;
	
	if( UART_TX_BUFFER[byte_index] != NULL)
	{
		UART_UDR_REG = UART_TX_BUFFER[byte_index];
	}
	else
	{
		byte_index = 0 ;
	}
	

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
