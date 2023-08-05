

#ifndef SPI_INT_H_
#define SPI_INT_H_

#define DUMMY 0xFF

void SPI_MASTER_init(void);

void SPI_SLAVE_init(void);

u8 SPI_TRANSEV_BYTE(u8 byte);

 u8 SPI_SLAVE_RECIEVE_BYTE(void);   /* SPI read data function */

u8 SPI_MASTER_STR(u8 *str);
#endif /* SPI_INT_H_ */
