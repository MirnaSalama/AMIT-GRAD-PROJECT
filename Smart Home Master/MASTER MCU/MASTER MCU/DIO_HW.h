/*
 * DIO_HW.h
 *
 * Created: 9/29/2020 1:02:13 AM
 *  Author: Mirna
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

#define PORTA_reg (*((volatile Uint8*)0x3B))
#define DDRA_reg (*((volatile Uint8*)0x3A))
#define PINA_reg (*((volatile Uint8*)0x39))

#define PORTB_reg (*((volatile Uint8*)0x38))
#define DDRB_reg (*((volatile Uint8*)0x37))
#define PINB_reg (*((volatile Uint8*)0x36))

#define PORTC_reg (*((volatile Uint8*)0x35))
#define DDRC_reg (*((volatile Uint8*)0x34))
#define PINC_reg (*((volatile Uint8*)0x33))

#define PORTD_reg (*((volatile Uint8*)0x32))
#define DDRD_reg (*((volatile Uint8*)0x31))
#define PIND_reg (*((volatile Uint8*)0x30))



#endif /* DIO_HW_H_ */