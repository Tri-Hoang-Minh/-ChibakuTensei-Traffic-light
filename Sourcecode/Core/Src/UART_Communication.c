/*
 * UART_Communication.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
#include "UART_Communication.h"
// setting UART and Buzzer for traffic light system
void sendDATA(){
	if(timer4_flag)
	{
			if(!timer1_flag)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:TFLIGHT1#\r\n", timer1_counter/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:WAIT:TFLIGHT1#\r\n"), 1000);
			}

			if(!timer2_flag)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:TFLIGHT2#\r\n", timer2_counter/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:WAIT:TFLIGHT2#\r\n"), 1000);
			}
			setTimer4(1000);
		}
}

void sendVALUE_SETTING()
{
	HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!RED:%d:GREEN:%d:YELLOW:%d#\r\n", time_setting_red/1000, time_setting_green/1000, time_setting_yellow/1000), 1000);
}



