/*
 * EEPROM_prog.c
 *
 * Created: 2023-03-11 10:38:37 AM
 *  Author: abdoa
 */ 

#include "EEPROM_init.h"
/*
// 	EERIE	3	//ready interrupt enable
// 	EEMWE	2	//master write enable
// 	EEWE	1	//write enable
// 	EERE	0	//read enable
*/

void EEPROM_write(u16 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEARL = (u8) uiAddress;
	EEARH = (u8) (uiAddress >> 8);
	EEDR = ucData;
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);			 // enable master
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR,EEWE);
}


u8 EEPROM_read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEARL = (u8) uiAddress;
	EEARH = (u8) (uiAddress >> 8);
	/* Start eeprom read by writing EERE */
	SET_BIT(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}