/*
 * seven_segment_bcd.c
 *

 */ 

#include "seven segment bcd.h"


void seven_seg_init(void)
{
	dio_vidConfigChannel(SEG_COM1_PORT,SEG_COM1_PIN,OUTPUT);
	dio_vidConfigChannel(SEG_COM2_PORT,SEG_COM2_PIN,OUTPUT);
	dio_vidConfigChannel(SEG_COM3_PORT,SEG_COM3_PIN,OUTPUT);
	dio_vidConfigChannel(SEG_COM4_PORT,SEG_COM4_PIN,OUTPUT);
	
	dio_vidConfigChannel(SEG_A_PORT,SEG_A_CHANNEL,OUTPUT);
	dio_vidConfigChannel(SEG_B_PORT,SEG_B_CHANNEL,OUTPUT);
	dio_vidConfigChannel(SEG_C_PORT,SEG_C_CHANNEL,OUTPUT);
	dio_vidConfigChannel(SEG_D_PORT,SEG_D_CHANNEL,OUTPUT);
	
}

void seven_seg_write(u8 value)
{		dio_vidWriteChannel(SEG_COM1_PORT,SEG_COM1_PIN,STD_LOW);
	    dio_vidWriteChannel(SEG_COM2_PORT,SEG_COM2_PIN,STD_HIGH);
		dio_vidWriteChannel(SEG_COM3_PORT,SEG_COM3_PIN,STD_HIGH);
		dio_vidWriteChannel(SEG_COM4_PORT,SEG_COM4_PIN,STD_HIGH);
		
		dio_vidWriteChannel(SEG_A_PORT,SEG_A_CHANNEL,CHECK_BIT(value,0));
		dio_vidWriteChannel(SEG_B_PORT,SEG_B_CHANNEL,CHECK_BIT(value,1));
		dio_vidWriteChannel(SEG_C_PORT,SEG_C_CHANNEL,CHECK_BIT(value,2));
		dio_vidWriteChannel(SEG_D_PORT,SEG_D_CHANNEL,CHECK_BIT(value,3));
}