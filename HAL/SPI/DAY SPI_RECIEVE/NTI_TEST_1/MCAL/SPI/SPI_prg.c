
#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
#include "..\MCAL\DIO\dio.h"
 #include "SPI_int.h"
 #include "SPI_priv.h"
 #include "SPI_config.h"


void SPI_MASTER_init(void)
{
	/*Set SS / MOSI / SCK  as output pins for master*/
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN4,OUTPUT);		//SS
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN5,OUTPUT);		//MOSI
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,OUTPUT);		//SCK
		/*set SS to high */
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_HIGH);
		
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN6,INPUT);			//MISO
	
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);	
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to fosc/16*/
	SET_BIT(SPCR,SPR0);


}


void SPI_SLAVE_init(void)
{
	/*Set SS / MOSI / SCK  as output pins for master*/
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN4,INPUT);        //SS
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN5,INPUT);		   //MOSI
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,INPUT);		   //SCK	
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN6,OUTPUT);	   //MISO
// 
// 	/*Enable SLAVE mode*/
// 	CLEAR_BIT(SPCR,MSTR);
	
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	

}

u8 SPI_TRANSEV_BYTE(u8 byte)
{	
	SPDR = byte ; // start transmission
	//WHILE TRANSMISSION
	while( CHECK_BIT(SPSR,SPIF) == 0 );
	return SPDR;
}

// u8 SPI_MASTER_RECIEVE_BYTE(void)   /* SPI read data function */
// {
// 	SPDR = DUMMY;
// 	while( CHECK_BIT(SPSR,SPIF) == 0 );	/* Wait till reception complete */
// 	return SPDR;			/* Return received data */
// }
// 
// 
// u8 SPI_SLAVE_TRANSMIT_BYTE(void)
// {
// 	SPDR = byte ; // start transmission
// 	//WHILE TRANSMISSION
// 	while( CHECK_BIT(SPSR,SPIF) == 0 );
// 	return SPDR;
// }
//

 
 u8 SPI_SLAVE_RECIEVE_BYTE(void)   /* SPI read data function */
{
 
	while( CHECK_BIT(SPSR,SPIF) == 0 );	/* Wait till reception complete */
return SPDR;			/* Return received data */
 }

// u8 SPI_SLAVE_RECIEVE_BYTE(u8 Data)
// {
// 	/*Put data on SPDR*/
// 	SPDR=Data;
// 	/*Wait until data is received in SPI register*/
// 	while(CHECK_BIT(SPSR,SPIF)==0);
// 	/*read the received data*/
// 	return SPDR ;
// }