


#ifndef SEVEN_SEGMENT_BCD_H_
#define SEVEN_SEGMENT_BCD_H_


#include "..\MCAL\DIO\dio.h"

#define SEG_A_PORT		DIO_PORTB
#define SEG_A_CHANNEL		DIO_PIN0

#define SEG_B_PORT		DIO_PORTB
#define SEG_B_CHANNEL	DIO_PIN1

#define SEG_C_PORT		DIO_PORTB
#define SEG_C_CHANNEL	DIO_PIN2

#define SEG_D_PORT		DIO_PORTB
#define SEG_D_CHANNEL	DIO_PIN4


#define SEG_COM1_PORT		DIO_PORTA
#define SEG_COM1_PIN		DIO_PIN3

#define SEG_COM2_PORT		DIO_PORTA
#define SEG_COM2_PIN		DIO_PIN2

#define SEG_COM3_PORT		DIO_PORTB
#define SEG_COM3_PIN		DIO_PIN5

#define SEG_COM4_PORT		DIO_PORTB
#define SEG_COM4_PIN		DIO_PIN6


#define CA_SEG					1
#define CC_SEG					0

#define SEG_TYPE				CA_SEG
#define SEGMENT_NUM				4


void seven_seg_init(void);
void seven_seg_write(u8 value);


#endif /* SEVEN SEGMENT BCD_H_ */