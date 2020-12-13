/*
 * DIO.c
 *
 * Created: 9/29/2020 1:20:52 AM
 *  Author: Mirna
 */ 
#include "DIO.h"

void DIO_write(DIO_ChannelTypes ChannelID, STD_LevelTypes level)
{
	DIO_PortTypes portX = ChannelID/8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	
	switch (portX)
	{
		case DIO_portA:
		if (level == STD_high)
		{
			setB(PORTA_reg, ChannelPos);
		}
		else
		{
			clrB(PORTA_reg, ChannelPos);
		}
		break;
		
// ----------------------------------------------------------		
		
		case DIO_portB:
		if (level == STD_high)
		{
			setB(PORTB_reg, ChannelPos);
		}
		else
		{
			clrB(PORTB_reg, ChannelPos);
		}
		break;
	
// ----------------------------------------------------------		
		
		case DIO_portC:
		if (level == STD_high)
		{
			setB(PORTC_reg, ChannelPos);
		}
		else
		{
			clrB(PORTC_reg, ChannelPos);
		}
		break;
		
// ----------------------------------------------------------	
		
		case DIO_portD:
		if (level == STD_high)
		{
			setB(PORTD_reg, ChannelPos);
		}
		else
		{
			clrB(PORTD_reg, ChannelPos);
		}
		break;
		
	}
}

STD_LevelTypes DIO_read(DIO_ChannelTypes ChannelID)
{
	STD_LevelTypes ChannelBit=0;
	DIO_PortTypes portX =  ChannelID /8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	
	switch (portX)
	{
		case DIO_portA:
		ChannelBit = getB (PINA_reg,ChannelPos);
		break;	
		
		case DIO_portB:
		ChannelBit = getB (PINB_reg,ChannelPos);
		break;
		
		case DIO_portC:
		ChannelBit = getB (PINC_reg,ChannelPos);
		break;
		
		case DIO_portD:
		ChannelBit = getB (PIND_reg,ChannelPos);
		break;
	}
	return(ChannelBit);
}

void DIO_toggle(DIO_ChannelTypes ChannelID)
{
	DIO_PortTypes portX =  ChannelID /8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	
	switch (portX)
	{
		
		case DIO_portA:
		toggleB (PORTA_reg,ChannelPos);
		break;
		
		case DIO_portB:
	    toggleB (PORTB_reg,ChannelPos);
		break;
		
		case DIO_portC:
		toggleB (PORTC_reg,ChannelPos);
		break;
		
		case DIO_portD:
		toggleB (PORTD_reg,ChannelPos);
		break;
	}
}