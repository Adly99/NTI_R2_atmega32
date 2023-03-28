/*
 * IR.h
 *
 * Created: 3/16/2023 8:01:30 PM
 *  Author: Dell
 */ 


#ifndef IR_H_
#define IR_H_

#include "../../MCAL/DIO/dio.h"

#define IR_PORT DIO_PORTC
#define IR_PIN DIO_PIN7

void IR_Init(void);
u8 IR_Read(void);


#endif /* IR_H_ */