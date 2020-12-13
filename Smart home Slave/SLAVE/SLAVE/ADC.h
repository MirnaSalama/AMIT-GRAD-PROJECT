/*
 * ADC.h
 *
 * Created: 12/13/2020 11:48:34 AM
 *  Author: Mirna
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"

void ADC_Init();
Uint16 ADC_Read(Uint8 channel);

#endif /* ADC_H_ */