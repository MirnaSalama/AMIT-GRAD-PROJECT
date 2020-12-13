/*
 * DIO_CFG.h
 *
 * Created: 9/29/2020 1:45:46 AM
 *  Author: Mirna
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct {
	DIO_DirTypes PinDir;
	STD_LevelTypes PinLevel;
	}Dio_PinCFG;

#define PINCOUNT 32

void DIO_Init(void);


#endif /* DIO_CFG_H_ */