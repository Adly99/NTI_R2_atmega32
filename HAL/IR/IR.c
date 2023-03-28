/*
 * IR.c
 *
 * Created: 3/16/2023 8:01:14 PM
 *  Author: Dell
 */ 

#include "IR.h"

void IR_Init(){
	dio_vidConfigChannel(IR_PORT,IR_PIN,INPUT);
}
u8 IR_Read(){
	return dio_dioLevelReadChannel(IR_PORT,IR_PIN);
}