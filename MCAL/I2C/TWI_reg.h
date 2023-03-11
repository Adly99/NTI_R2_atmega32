/*
 * TWI_reg.h
 *
 * Created: 2023-03-10 02:56:21 PM
 *  Author: abdoa
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_


#define     I2C_SLAVE         0
#define     I2C_MASTER        1

#define     ENABLE            0
#define     DISABLE           1

#define     I2C_PRESCALER_1   1
#define     I2C_PRESCALER_4   4
#define     I2C_PRESCALER_16  16
#define     I2C_PRESCALER_64  64

#define     TWBR       *((volatile u8 *)0x20)
#define     TWCR      *((volatile u8 *)0x56)
#define     TWSR       *((volatile u8 *)0x21)
#define     TWDR       *((volatile u8 *)0x23)
#define     TWAR       *((volatile u8 *)0x22)



/*        TWCR_REG Pins    */
#define       TWIE          0
#define       TWEN          2
#define       TWWC          3
#define       TWSTO         4
#define       TWSTA         5
#define       TWEA          6
#define       TWINT         7

/*        TWSR_REG Pins    */
#define       TWPS0         0
#define       TWPS1         1
#define       TWS3          3
#define       TWS4          4
#define       TWS5          5
#define       TWS6          6
#define       TWS7          7

/*        TWAR_REG Pins    */
#define       TWGCE         0
#define       TWA0          1
#define       TWA1          2
#define       TWA2          3
#define       TWA3          4
#define       TWA4          5
#define       TWA5          6
#define       TWA6          7


/*        I2C Physical Pins */
#define       I2C_PORT         PORTC
#define       I2C_SCL          PIN0
#define       I2C_SDA          PIN1


#define       I2C_SC_ACK        0x08
#define       I2C_RSC_ACK       0x10
#define       I2C_MT_SLA_R_ACK  0x40
#define       I2C_MT_SLA_W_ACK  0x18
#define       I2C_MT_DATA_ACK   0x28
#define       I2C_MR_DATA_ACK   0x48
#define       I2C_SR_DATA_ACK   0x80


#endif /* TWI_REG_H_ */