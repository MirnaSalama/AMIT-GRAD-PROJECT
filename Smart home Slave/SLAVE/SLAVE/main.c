/*
 * SLAVE.c
 *
 * Created: 12/11/2020 10:56:15 PM
 * Author : Mirna
 */ 

#include <avr/io.h>
#include "stdlib.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_types.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"

#define ROOM_LIGHT DIO_channelC0




int main(void)
{
	DIO_Init();
	
	SPI_Init('S');
	
	ADC_Init();
	
	LCD_Init();
	LCD_clr();
	
	LCD_StringPos("Your wish is",1,2);
	LCD_StringPos("my command",2,2);

	_delay_ms(500);
	
	Uint8 DATA_IN;
	Uint16 temp=0;
	Uint8 buffer[50];
	
	
	

	
	while (1)	{			
		DATA_IN = SPI_Receive();
		if(DATA_IN == 'a')
		{
			DIO_write(ROOM_LIGHT,STD_high);
			_delay_ms(200);
			LCD_clr();
			LCD_StringPos("LIGHT", 1,2);
			LCD_StringPos("ON", 2,2);
			
		}
		else if(DATA_IN =='b')
		{
			DIO_write(ROOM_LIGHT,STD_low);
			_delay_ms(200);
			LCD_clr();
				LCD_StringPos("LIGHT", 1,2);
				LCD_StringPos("OFF", 2,2);
		}
		else if(DATA_IN =='c')
		{
			Forward();
			_delay_ms(200);
			LCD_clr();
				LCD_StringPos("MOTOR", 1,2);
				LCD_StringPos("FORWARD", 2,2);
		}
		else if(DATA_IN =='d')
		{
			Reverse();
			_delay_ms(200);
			LCD_clr();
			LCD_StringPos("MOTOR", 1,2);
			LCD_StringPos("REVERSE", 2,2);
		}
		else if (DATA_IN =='e')
		{
			Stop();
			_delay_ms(200);
			LCD_clr();
			LCD_StringPos("MOTOR", 1,2);
			LCD_StringPos("STOP", 2,2);
		}
		
else if (DATA_IN =='f')
{
	LCD_clr();	LCD_StringPos("Calculating", 1, 2);	LCD_StringPos("Temprature...", 2, 2);	_delay_ms(1000);
	while(1)
	{
	temp = ADC_Read(1);	temp /=4;	itoa(temp,buffer,10);	LCD_clr();	LCD_StringPos("Temprature =", 1, 1);	LCD_string(buffer);	_delay_ms(500);
	}
}
	
   }
}