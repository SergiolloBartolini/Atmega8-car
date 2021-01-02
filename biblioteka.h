/*
 * biblioteka.h
 *
 * Created: 02.01.2021 22:50:08
 *  Author: SergiuszB
 */
#include "setup.h"

#ifndef BIBLIOTEKA_H_
#define BIBLIOTEKA_H_

void turn_left (void)
{
	LEFT  |= (1<<ML2_EN) | (1<<ML2_IN1) | (1<<ML4_EN) | (1<<ML4_IN1);
	LEFT  &= ~((1<<ML2_IN2)|(1<<ML4_IN2));
	RIGHT |= (1<<MR1_EN) | (1<<MR1_IN2) | (1<<MR3_EN) | (1<<MR3_IN2);
	RIGHT &= ~((1<<MR1_IN1)|(1<<MR3_IN1));	
}
void turn_right (void)
{
	LEFT  |= (1<<ML2_EN) | (1<<ML2_IN2) | (1<<ML4_EN) | (1<<ML4_IN2);
	LEFT  &= ~((1<<ML2_IN1)|(1<<ML4_IN1));
	RIGHT |= (1<<MR1_EN) | (1<<MR1_IN1) | (1<<MR3_EN) | (1<<MR3_IN1);
	RIGHT &= ~((1<<MR1_IN2)|(1<<MR3_IN2));	
	
}
void forward (void)
{
	LEFT  |= (1<<ML2_EN) | (1<<ML2_IN1) | (1<<ML4_EN) | (1<<ML4_IN1);
	LEFT  &= ~((1<<ML2_IN2)|(1<<ML4_IN2));
	RIGHT |= (1<<MR1_EN) | (1<<MR1_IN1) | (1<<MR3_EN) | (1<<MR3_IN1);
	RIGHT &= ~((1<<MR1_IN2)|(1<<MR3_IN2));	
}
void backward (void)
{
	LEFT  |= (1<<ML2_EN) | (1<<ML2_IN2) | (1<<ML4_EN) | (1<<ML4_IN2);
	LEFT  &= ~((1<<ML2_IN1)|(1<<ML4_IN1));
	RIGHT |= (1<<MR1_EN) | (1<<MR1_IN2) | (1<<MR3_EN) | (1<<MR3_IN2);
	RIGHT &= ~((1<<MR1_IN1)|(1<<MR3_IN1));	
	
}
void stop (void)
{
	LEFT  = 0;
	RIGHT = 0;
}

void pilot_controll_ride(void)
{
		if (bit_is_set(PILOT,P_RIGHT) & bit_is_clear (PILOT,P_LEFT) & bit_is_clear (PILOT,P_FORWARD) & bit_is_clear (PILOT,P_BACK))
	{
		turn_right();
	}
	else if(bit_is_set(PILOT,P_LEFT) & bit_is_clear (PILOT,P_RIGHT) & bit_is_clear (PILOT,P_FORWARD) & bit_is_clear (PILOT,P_BACK))
	{
		turn_left();
	}
	else if(bit_is_set(PILOT,P_FORWARD) & bit_is_clear (PILOT,P_LEFT) & bit_is_clear (PILOT,P_RIGHT) & bit_is_clear (PILOT,P_BACK))
	{
		forward();
	}
	else if(bit_is_set(PILOT,P_BACK) & bit_is_clear (PILOT,P_LEFT) & bit_is_clear (PILOT,P_FORWARD) & bit_is_clear (PILOT,P_RIGHT))
	{
		backward();
	}
	else
	{
		stop();
	}
}

#endif /* BIBLIOTEKA_H_ */