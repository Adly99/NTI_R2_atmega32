/*
 * NTI_TEST_1.c
 *
 * Created: 2023-02 
 * Author : Abdelrhman Elsayed
 */ 


#include "..\MCAL\DIO\dio.h"
#include "..\HAL\LED\led.h"
#include "..\HAL\Button\button.h"
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\BCD\seven segment bcd.h"
#include "..\MCAL\EXTI\EXTI0_int.h"
#include "..\MCAL\ADC\ADC_int.h"
#include "..\MCAL\UART\uart.h"
#include "..\MCAL\GIE\GIE_int.h"
#include "..\MCAL\SPI\SPI_int.h"


int main(void)
 {	
 

	 SPI_SLAVE_init();

	lcd_vidInit();
	u8 name = 0;

    while (1) 
    {	
		name = SPI_SLAVE_RECIEVE_BYTE();
		lcd_vidDisplyChar(name);
/*
// 		if ( name == 'a')
//  		{
// 
// 		lcd_vidDisplyChar('5');
// 		_delay_ms(100);
// 		lcd_vidDisplyStr("ADLY99");
// 		lcd_vidGotoRowColumn(1,);
// 		}
*/


	}
	return 0 ;
}

