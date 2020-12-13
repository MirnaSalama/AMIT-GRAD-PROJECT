/*
 * SPI.c
 *
 * Created: 12/11/2020 9:37:23 PM
 *  Author: Mirna
 */ 
#include "SPI.h"void SPI_Init(Uint8 state){	switch (state)	{				case 'M' :		SPCR |= (1<<SPE)|(1<<MSTR);			SlaveDis();		break;				case 'S' :		SPCR |= (1<<SPE);		break;	}}void SPI_Write(Uint8 data)		{	char flush_buffer;	SPDR = data;				while(!(SPSR & (1<<SPIF)));		flush_buffer = SPDR;		}Uint8 SPI_Receive()			{	while(!(SPSR & (1<<SPIF)));		return(SPDR);			}