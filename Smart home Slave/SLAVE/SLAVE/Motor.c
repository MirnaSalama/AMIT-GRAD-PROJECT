/*
 * Motor.c
 *
 * Created: 12/12/2020 7:35:55 PM
 *  Author: Mirna
 */ 

#include "Motor.h"
#include "DIO.h"

#define ENA DIO_channelC5
#define IN1 DIO_channelC6
#define IN2 DIO_channelC7

void Forward()
{
	DIO_write(IN1,STD_high);
	DIO_write(IN2,STD_low);
	DIO_write(ENA,STD_high);
	DIO_write(DIO_channelC2,STD_high);
	DIO_write(DIO_channelC3,STD_low);
	DIO_write(DIO_channelC4,STD_low);
}

void Reverse(void)
{
	DIO_write(IN1,STD_low);
	DIO_write(IN2,STD_high);
	DIO_write(ENA,STD_high);
	DIO_write(DIO_channelC3,STD_high);
	
	DIO_write(DIO_channelC2,STD_low);
	DIO_write(DIO_channelC4,STD_low);
}
void Stop(void)
{
	DIO_write(IN1,STD_low);
	DIO_write(IN2,STD_low);
	DIO_write(ENA,STD_low);
	DIO_write(DIO_channelC4,STD_high);
	
	DIO_write(DIO_channelC2,STD_low);
	DIO_write(DIO_channelC3,STD_low);
	
}
