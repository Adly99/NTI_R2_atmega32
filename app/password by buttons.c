/*
 * valeor2.c
 *
 * Created: 2023-02-17 11:44:28 AM
 * Author : abdoa
 */ 
#include "dio.h"

#include "LCD.h"
//#include <avr/io.h>
#include "BUTTON_config.h"
#include "led_config.h"





int main(void)
{	
	u8 i;
	u8 sum = 0;
	u8 count_id[3] ={0} ;
	u8 button_id[3]={BUTTON1,BUTTON2,BUTTON3};
	//lcd_init();	
	//lcd_gotoRowColumn(1,1);
	//lcd_displyStr("hello");
	//lcd_sendCmd(0x01);
	//_delay_ms(30);
	//lcd_sendData(97);
	//_delay_ms(30);
	//lcd_gotoRowColumn(1,1);
	//lcd_displyStr("hello WORLD");
		
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN6,OUTPUT);

	BUTTON_init(BUTTON1);
	BUTTON_init(BUTTON2);
	BUTTON_init(BUTTON3);
	led_init(YEL);	
	led_init(GREEN);
	led_off(RED);
	dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
	
    while (1) 
	{

		for (i=0;i<3;i++)
		{
			if (BUTTON_READ(button_id[i]) == 0)
			{
				_delay_ms(20);	
				while(BUTTON_READ(button_id[i]) == 0);

					count_id[i]++;
					sum++ ;
					
				led_toggle(GREEN);

			}
		}
		
		if(sum == 6)
			 {
				if (count_id[0] == 2 && count_id[1] == 1 && count_id[2] == 3)
				{
					led_on(YEL);
					_delay_ms(500);
					led_off(YEL);
					sum= 0;
				}	
			 }
		
	}
}