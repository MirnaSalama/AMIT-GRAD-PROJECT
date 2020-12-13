/*
 * ADC.c
 *
 * Created: 12/13/2020 11:48:24 AM
 *  Author: Mirna
 */ 

#include "ADC.h"
#include "DIO.h"
#include <avr/io.h>


void ADC_Init()
{
	setB(ADMUX,REFS0);
	setB(ADMUX,REFS1);
	setB(ADCSRA,ADPS0);
	setB(ADCSRA,ADPS1);
	setB(ADCSRA,ADPS2);
	setB(ADCSRA,ADEN); // enable
}


Uint16 ADC_Read(Uint8 channel)
{
	Uint16 Data=0;
	
	
	ADMUX = (ADMUX & 0b11100000)|(channel & 0b00011111);
	setB(ADCSRA,ADSC);
	
	while (!((ADCSRA) & (1<<ADIF)));
	setB(ADCSRA,ADIF);
	
	Data = ADCL;
	Data |= (ADCH << 8);
	
	return Data;
	
}
