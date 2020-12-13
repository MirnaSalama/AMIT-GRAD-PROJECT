/*
 * SPI.c
 *
 * Created: 12/11/2020 9:37:23 PM
 *  Author: Mirna
 */ 
#include "SPI.h"void SPI_Init(Uint8 state){	switch (state)	{				case 'M' :		SPCR |= (1<<SPE)|(1<<MSTR);			SlaveDis();		break;				case 'S' :		SPCR |= (1<<SPE);//enable SPI		break;	}}void SPI_Write(Uint8 data)		/* SPI write data function */{	char flush_buffer;	SPDR = data;			/* Write data to SPI data register */	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */	flush_buffer = SPDR;		/* Flush received data */}Uint8 SPI_Receive()			/* SPI Receive data function */{	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */	return(SPDR);			/* Return received data */}