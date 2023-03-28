/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "lcd.h"
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
extern u8 customChar[NO_CSTOM_CHAR][NO_CSTOM_CHAR_BYTES];
static void enablePulse(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void enablePulse(void)        
* \Description     : send enable pulse to LCD HW                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                        
* \Return value:   : None                                 
*******************************************************************************/

static void enablePulse(void)
{
	dio_vidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_HIGH);
	_delay_us(1);
	dio_vidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_LOW);
	_delay_ms(2);
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void lcd_init(void)        
* \Description     : initialize LCD HW                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                        
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidInit(void)
{
	dio_vidConfigChannel(LCD_RS_PORT, LCD_RS_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_EN_PORT, LCD_EN_CHANNEL, OUTPUT);

	dio_vidConfigChannel(LCD_D4_PORT, LCD_D4_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D5_PORT, LCD_D5_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D6_PORT, LCD_D6_CHANNEL, OUTPUT);
	dio_vidConfigChannel(LCD_D7_PORT, LCD_D7_CHANNEL, OUTPUT);
	// 	dio_vidWriteChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_LOW);

	lcd_vidSendCmd(0x02);
	_delay_ms(5);
	lcd_vidSendCmd(0x03);
	_delay_us(100);
	lcd_vidSendCmd(lcd_Home);
	_delay_ms(15);
	lcd_vidSendCmd(lcd_FunctionSet4bit);
	_delay_ms(1);
	lcd_vidSendCmd(lcd_DisplayOn );
	_delay_ms(1);
	lcd_vidSendCmd(lcd_Clear);
	_delay_ms(1);

/*
 	lcd_vidSendCmd(0x03);
 	_delay_ms(5);
 	lcd_vidSendCmd(0x03);
  	_delay_us(100);
 	lcd_vidSendCmd(0x03);
  	lcd_vidSendCmd(0x02);
  	lcd_vidSendCmd(_LCD_4BIT_MODE); // to initialize LCD in 4-bit mode.
    lcd_vidSendCmd(0x0E);
*/
	lcd_vidCustomWrite();
	lcd_vidGotoRowColumn(0, 0);
}

/******************************************************************************
* \Syntax          : void lcd_vidSendCmd(lcd_Cmd_Type cmd)        
* \Description     : send command to LCD HW                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : cmd	-> LCD command ID                                                                        
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidSendCmd(lcd_cmd_t cmd)
{
	/*	RS -> Command Mode	*/
	dio_vidWriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_LOW);

	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(cmd,4));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(cmd,5));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(cmd,6));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(cmd,7));
	
	enablePulse();
	
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(cmd,0));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(cmd,1));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(cmd,2));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(cmd,3));
	
	enablePulse();
}

/******************************************************************************
* \Syntax          : void lcd_vidSendData(u8 data)        
* \Description     : send data to LCD HW                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data	-> LCD data input                                                                       
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidSendData(u8 data)
{
	/*	RS -> Data Mode	*/
	dio_vidWriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_HIGH);

	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(data,4));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(data,5));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(data,6));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(data,7));
	
	enablePulse();
	
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D4_CHANNEL,CHECK_BIT(data,0));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D5_CHANNEL,CHECK_BIT(data,1));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D6_CHANNEL,CHECK_BIT(data,2));
	dio_vidWriteChannel(LCD_D4_PORT,LCD_D7_CHANNEL,CHECK_BIT(data,3));
	
	enablePulse();
	
}

/******************************************************************************
* \Syntax          : void lcd_vidGotoRowColumn(u8 row, u8 column)        
* \Description     : set LCD DDRAM pointer                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : row	-> LCD row ID
					 column -> LCD column ID															
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidGotoRowColumn(u8 row, u8 column)
{
	switch (row)
	{
	case 0:
		/*	Row 0	*/
		lcd_vidSendCmd(0x80+column); // DD RAM Page 24
		break;

	case 1:
		/* Row 1 */
		lcd_vidSendCmd(0xC0+column);
		break;

 	case 2:
 	/* Row 2 */
 	lcd_vidSendCmd(0x94+column);
 	break;
 	
 	case 3:
 	/* Row 3 */
 	lcd_vidSendCmd(0xD4+column);
 	break;			
	}	
}

/******************************************************************************
* \Syntax          : void lcd_vidDisplyChar(u8 chr)       
* \Description     : sent character to be displayed                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : chr	-> ASCI value of character															
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidDisplyChar(u8 chr)
{
	lcd_vidSendData(chr);
}

/******************************************************************************
* \Syntax          : void lcd_vidDisplyStr(u8* str)       
* \Description     : display string on LCD                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : str	-> string to be displayed														
* \Return value:   : None                                 
*******************************************************************************/
void lcd_vidDisplyStr(char *str)
{
	while (*str != '\0')
	{
		lcd_vidDisplyChar(*str);
		str++;
	}
}

/******************************************************************************
* \Syntax          : void lcd_vidCustomWrite(void)
* \Description     : load LCD CGRAM with configured custom characters
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void lcd_vidCustomWrite(void)
{
	u8 loc_ByteIndex=0;
	u8 loc_CharIndx=0;
	
	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		lcd_vidSendCmd(_LCD_CGRAM_START_ADDRESS +(loc_CharIndx*8));
		for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			lcd_vidDisplyChar(customChar[loc_CharIndx][loc_ByteIndex]);
		}
	}	
}






void lcd_vidsendnumber(u16 value)
{
	u16 rev=0;
	u16 x=0;
	while(value!=0)
	{
		rev=(rev*10)+(value%10);
		value=value/10;
	}

	while(rev!=0)
	{
		x=rev%10;
		rev=rev/10;
		lcd_vidSendData(48+x);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: lcd_cfg.c
 *********************************************************************************************************************/
