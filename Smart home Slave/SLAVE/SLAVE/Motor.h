/*
 * Motor.h
 *
 * Created: 12/12/2020 7:36:13 PM
 *  Author: Mirna
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#define LED_MOTOR_F DIO_channelC2
#define LED_MOTOR_R DIO_channelC3
#define LED_MOTOR_S DIO_channelC4

void Forward(void);
void Reverse(void);
void Stop(void);





#endif /* MOTOR_H_ */