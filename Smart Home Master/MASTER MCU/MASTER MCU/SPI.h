/*
 * SPI.h
 *
 * Created: 12/11/2020 9:37:41 PM
 *  Author: Mirna
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"
#include "avr/io.h"

#define SS   DIO_channelB4#define MOSI DIO_channelB5#define MISO DIO_channelB6#define SCK  DIO_channelB7#define SlaveEn() (DIO_write(SS,STD_low))#define SlaveDis() (DIO_write(SS,STD_high))void SPI_Init(Uint8);void SPI_Write(Uint8 data);Uint8 SPI_Receive();



#endif /* SPI_H_ */