/*
 * Buzzer.c
 *
 *  Created on: Dec 19, 2022
 *      Author: Hoang Tri
 */

#include "Buzzer.h"

void Buzzer_RUN()
{
	if(timer5_flag)
	{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, time_frequency);
		setTimer6(time_buzzer/2);
		if(timer2_counter<300)  // led pedestrian is located at traffic light 2.
		{
			time_frequency =time_frequency* 3;
			time_buzzer = (timer2_counter>0)? timer2_counter/6 : time_buzzer/5;
		}
		else
		{
		    time_frequency = time_frequency+100;
			time_buzzer = time_buzzer- 100;
		}


		if(time_frequency >= 1000)
		{
			time_frequency = 1000;
		}
		if(time_buzzer <= 100)
		{
			time_buzzer = 100;
		}
		setTimer5(time_buzzer);
	}
	if(timer6_flag)
	{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
}
