/*
 * IncFile1.h
 *
 * Created: 2023-03-11 10:46:27 AM
 *  Author: Abdelrhman Elsayed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define EEARH	*((volatile u8 *)0x3F)
#define EEARL	*((volatile u8 *)0x3E)
#define EEAR	*((volatile u16*)0x3E) // TO PUT ALL DATA IN register EEAR (HIGH + LOW )	

#define	EEDR	*((volatile u8 *)0x3D)
#define	MSB	7
#define	LSB	0

#define	EECR	*((volatile u8 *)0x3C)
#define	EERIE	3	//ready interrupt enable
#define	EEMWE	2	//master write enable
#define	EEWE	1	//write enable
#define	EERE	0	//read enable




#endif /* INCFILE1_H_ */