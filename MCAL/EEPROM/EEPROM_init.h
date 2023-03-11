/*
 * EEPROM_init.h
 *
 * Created: 2023-03-11 10:39:00 AM
 *  Author: Abdelrhman Elsayed
 */ 


#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_


#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
#include "..\MCAL\DIO\dio.h"
#include "EEPROM_reg.h"




/*
Function Name        : EEPROM_write
Function Returns     : void
Function Arguments   : u16 address, u8 data
Function Description :  write one byte to the given  address.
*/
void EEPROM_write(u16 uiAddress, u8 ucData);


/*
Function Name        : EEPROM_read
Function Returns     : u8
Function Arguments   :  u16 address
Function Description :  read one byte from the given  address.
*/
u8 EEPROM_read(u16 uiAddress);




#endif /* EEPROM_INIT_H_ */