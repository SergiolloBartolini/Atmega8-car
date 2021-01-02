/*
 * setup.h
 *
 * Created: 02.01.2021 22:55:35
 *  Author: SergiuszB
 */ 

#ifndef SETUP_H_
#define SETUP_H_

//Czestotliwosc kontrolera
#define F_CPU 1000000UL

//Definicja portow
#define LEFT PORTD
#define RIGHT PORTC

#define MR1_EN  PC3
#define MR1_IN1 PC4
#define MR1_IN2 PC5

#define ML2_EN  PD5
#define ML2_IN1 PD0
#define ML2_IN2 PD1

#define MR3_EN  PC0
#define MR3_IN1 PC1
#define MR3_IN2 PC2

#define ML4_EN  PD2
#define ML4_IN1 PD3
#define ML4_IN2 PD4

//Pilot
#define PILOT     PINB
#define P_RIGHT   PB0
#define P_BACK    PB7
#define P_FORWARD PB1
#define P_LEFT    PB6

void initial_setup (void)
{
	DDRC  = 0b0111111; 
	DDRD  = 0b00111111;	
	DDRB  = 0b00000000;
	PORTB = 0b11111111;
}

#endif /* SETUP_H_ */