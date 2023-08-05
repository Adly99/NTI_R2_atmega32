/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  uart.h
 *       Module:  uart
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_REG_H_
#define UART_REG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define UART_UDR_REG				(*(volatile u8* )0x2C)
#define UART_UCSRA_REG				(*(volatile u8* )0x2B)
#define UART_UCSRB_REG				(*(volatile u8* )0x2A)
#define UART_UBRRH_REG				(*(volatile u8* )0x40)
#define UART_UCSRC_REG				(*(volatile u8* )0x40)
#define UART_UBRRL_REG				(*(volatile u8* )0x29)


#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UDRE_BIT_NO						(5)
#define RXC_BIT_NO						(7)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/
