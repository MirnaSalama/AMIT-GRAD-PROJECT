/*
 * MASTER MCU.c
 *
 * Created: 12/11/2020 10:52:20 PM
 * Author : Mirna
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_types.h"
#include "DIO.h"
#include "SPI.h"
#include "USART_RS232_H_file.h"
#include "LCD.h"

int main(void)
{
	
	
	
	
	DIO_Init();
	USART_Init(9600);	SPI_Init('M');	SlaveEn();
	LCD_Init();
	LCD_clr();

	LCD_StringPos("HELLOOOO",1,3);
	_delay_ms(500);
	LCD_clr();
	LCD_StringPos("WELCOME TO UR",1,1);
	LCD_StringPos("SMART HOME",2,2);
	
	_delay_ms(500);	Uint8 Received_Data;
	
		while(1)
		{
			
	
				Received_Data = USART_RxChar();						/* received data from bluetooth terminal*/
				_delay_ms(100);
			
				SPI_Write(Received_Data);				_delay_ms(100);
				
				
		}		

	
}