/*
 * LCD.h
 *
 * Created: 9/29/2020 7:06:25 PM
 *  Author: Mirna
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

#define  RS DIO_channelB1
#define  RW DIO_channelB2
#define  E DIO_channelB3

#define LCDDataPort PORTA_reg

void LCD_Init();
void LCD_cmd(Uint8 cmd);
void LCD_clr(void);
void LCD_char(Sint8 data);
void LCD_string(Sint8 * string);
void LCD_StringPos(Sint8 * string,Uint8 row, Uint8 col);
void LCD_CustomChar(Uint8 * data , Uint8 loc);

#endif /* LCD_H_ */