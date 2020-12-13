/*
* LCD.c
*
* Created: 9/29/2020 7:06:10 PM
*  Author: Mirna
*/

#include "LCD.h"

void LCD_cmd(Uint8 cmd)
{
	LCDDataPort = ((LCDDataPort & 0x0F)|(cmd & 0xF0)); 
	DIO_write(RS,STD_low); 
	DIO_write(E,STD_high);
	_delay_us(100);
	DIO_write(E,STD_low);
	
	_delay_ms(5);
	
	LCDDataPort = ((LCDDataPort & 0x0F)|(cmd << 4));
	DIO_write(RS,STD_low);
	DIO_write(E,STD_high);
	_delay_us(100);
	DIO_write(E,STD_low);
	_delay_ms(2);
}

void LCD_Init()
{
	DIO_write(RW,STD_low);

	_delay_ms(20);
	LCD_cmd(0x33);;
	_delay_us(200);
	LCD_cmd(0x32);
	LCD_cmd(0x28);
	LCD_cmd(0x07);
	LCD_cmd(0x06);
	LCD_cmd(0x18);
	LCD_cmd(0x0C);
	
	LCD_cmd(0x01);//clear
	_delay_ms(2);
}

void LCD_char(Sint8 data)
{
	LCDDataPort = ((LCDDataPort & 0x0F)|(data & 0xF0)); 
	DIO_write(RS,STD_high);
	DIO_write(E,STD_high);
	_delay_us(100);
	DIO_write(E,STD_low);
	
	_delay_ms(5);
	
	LCDDataPort = ((LCDDataPort & 0x0F)|(data << 4));
	DIO_write(RS,STD_high);
	DIO_write(E,STD_high);
	_delay_us(100);
	DIO_write(E,STD_low);
	_delay_ms(2);

}

void LCD_string(Sint8 * string)
{
	Uint8 count=0;
	while(string[count] != '\0')
	{
		LCD_char(string[count]);
		count++;
	}
	
}

void LCD_clr(void)
{
	LCD_cmd(0x01);
}

void LCD_StringPos(Sint8 * string,Uint8 row, Uint8 col)
{
	switch(row)
	{
		case 1:
		LCD_cmd(0x80 |(col & 0x0F));
		LCD_string(string);
		break;
		
		case 2:
		LCD_cmd(0xC0 |(col & 0x0F));
		LCD_string(string);
		break;
		
		
	}
}
void LCD_CustomChar(Uint8 * data , Uint8 loc)
{
	if (loc<8)
	{
		Uint8 i = 0;
		LCD_cmd(0x40 + (loc*8));
		for(i=0; i<8; i++)
		{
			LCD_char(data[i]);
		}
	}
}