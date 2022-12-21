/*
 * FSM_AUTOMODE.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
#include "FSM_AUTOMODE.h"
/*
 * First state of automatic mode:
 * Traffic light 1 : GREEN ON.
 * Traffic light 2: RED ON.
 */
void fsm_automode()
{
	// index=0: traffic light 1         and  index=1 : traffic light 2
	switch(status_light)
	{
	     case  AUTO_INIT:
	    	   clearLED(2);
	    	   // setTimer for  GREEN1/ traffic light 1.
	    	   setTimer1(time_led_green_1);              // 7s
	    	   // set timer for REDD2 / traffic light 2.
	    	   setTimer2(time_led_red_2);                // 10s
	    	   setTimer4(10);
	    	   status_light=AUTO_GREEN_1;
	    break;
	     case  AUTO_GREEN_1:
	    	   ToggleLEDGreen(0);
               ToggleLEDRed(1);
               sendDATA();
               if(timer1_flag==1)   // 7s
               {
            	   setTimer1(time_led_yellow_1);   // 3s
            	   status_light=AUTO_YELLOW_1;
               }
           // TODO: implementation fsm_button for PEDES MODE.
                // AUTO GREEN 1:  Pedestrian state is PEDE_GO because pedes_light is located in traffic light 2, In current, traffic light 2 is red => PEDES_Light = GREEN.
   			if(is_button_pressed(0))
   			{ // button of pedestrian is pressed().
   				setTimer5(BUZZER_DUTY_CYCLE);
   				setTimer3(TIME_PEDESTRIAN_LIGHT);                            // 20.000 (20s).
 				status_pedes = PEDES_GO;
                time_buzzer=BUZZER_DUTY_CYCLE;
                time_frequency=BUZZER_FREQUENCY_START;
   			}

           // TODO: implementation fsm_button for TUNNING MODE.
   			if(is_button_pressed(2))  // button 2 is pressed.
   			{
   				status_light=SETTING_LED_RED;
   				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
   				time_setting_red=time_led_red_1;
   				time_setting_green=time_led_green_1;
   				time_setting_yellow=time_led_yellow_1;
				setTimer8(12);
   			}

           // TODO: implementation fsm_button for CHANGE MODE (AUTO=> MANUAL).
   			if(is_button_pressed(1))  // button 1 is pressed.
   			{
   				status_light=MAN_GREEN_1;
   				status_pedes=PEDES_OUTOFSTATE;
   				setTimer9(TIME_MANUAL_MODE);
   				setTimer4(10);
   			}

	    break;
	     case  AUTO_YELLOW_1:   // 3s => 3s
	    	   ToggleLEDYellow(0);
               ToggleLEDRed(1);
               sendDATA();
               if(timer1_flag==1 && timer2_flag==1)  // 10s   => den do = den xanh + den vang
               {
            	   setTimer1(time_led_red_1);
            	   setTimer2(time_led_green_2);
            	   status_light=AUTO_GREEN_2;
               }
           // TODO: implementation fsm_button for PEDES MODE.
      			if(is_button_pressed(0))
      			{ // button of pedestrian is pressed().
      				setTimer5(BUZZER_DUTY_CYCLE);
      				setTimer3(TIME_PEDESTRIAN_LIGHT);
      				status_pedes = PEDES_GO;
                    time_buzzer=BUZZER_DUTY_CYCLE;
                    time_frequency=BUZZER_FREQUENCY_START;
      			}
           // TODO: implementation fsm_button for TUNNING MODE.
       			if(is_button_pressed(2))  // button 2 is pressed.
       			{
       				status_light=SETTING_LED_RED;
       				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
       				time_setting_red=time_led_red_1;
       				time_setting_green=time_led_green_1;
       				time_setting_yellow=time_led_yellow_1;
    				setTimer8(12);
       			}

           // TODO: implementation fsm_button for CHANGE MODE (AUTO=> MANUAL).
       			if(is_button_pressed(1))  // button 1 is pressed.
       			{
       				status_light=MAN_YELLOW_1;
       				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
       				setTimer9(TIME_MANUAL_MODE);
       				setTimer4(10);
       			}

	    break;
	     case  AUTO_GREEN_2:
	    	   ToggleLEDRed(0);   // RED 1 on
               ToggleLEDGreen(1);  // GREEN 2 on
               sendDATA();
               if(timer2_flag==1)
               {
            	   //setTimer3(time_led_red_1);
            	   setTimer2(time_led_yellow_2);
            	   status_light=AUTO_YELLOW_2;
               }
           // TODO: implementation fsm_button for PEDES MODE.
   			if(is_button_pressed(0))
   			{
   				setTimer3(TIME_PEDESTRIAN_LIGHT);
   				status_pedes =	PEDES_STOP;
   				time_buzzer = BUZZER_DUTY_CYCLE;
   				time_frequency = BUZZER_FREQUENCY_START;
   			}

           // TODO: implementation fsm_button for TUNNING MODE.
   			if(is_button_pressed(2))  // button 2 is pressed.
   			{
   				status_light=SETTING_LED_RED;
   				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
   				time_setting_red=time_led_red_1;
   				time_setting_green=time_led_green_1;
   				time_setting_yellow=time_led_yellow_1;
				setTimer8(12);
   			}

           // TODO: implementation fsm_button for CHANGE MODE (AUTO=> MANUAL).
 			if(is_button_pressed(1))  // button 1 is pressed.
   			{
   				status_light=MAN_GREEN_2;
   				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
   				setTimer9(TIME_MANUAL_MODE);
   				setTimer4(10);
   			}
	    break;
	     case  AUTO_YELLOW_2:
	    	   ToggleLEDRed(0);  // RED 1 on
               ToggleLEDYellow(1);  // YELLOW 2 on
               sendDATA();
               if(timer1_flag==1 && timer2_flag==1)
               {
            	   setTimer1(time_led_green_1);
            	   setTimer2(time_led_red_2);
            	   status_light=AUTO_GREEN_1;
               }
           // TODO: implementation fsm_button for PEDES MODE.
      			if(is_button_pressed(0))
      			{
      				setTimer3(TIME_PEDESTRIAN_LIGHT);  // out pedes state
      				status_pedes =	PEDES_STOP;
      				time_buzzer = BUZZER_DUTY_CYCLE;
      				time_frequency = BUZZER_FREQUENCY_START;
      			}
           // TODO: implementation fsm_button for TUNNING MODE.
       			if(is_button_pressed(2))  // button 2 is pressed.
       			{
       				status_light=SETTING_LED_RED;
       				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
       				time_setting_red=time_led_red_1;
       				time_setting_green=time_led_green_1;
       				time_setting_yellow=time_led_yellow_1;
    				setTimer8(12);
       			}

           // TODO: implementation fsm_button for CHANGE MODE (AUTO=> MANUAL).
     			if(is_button_pressed(1))  // button 1 is pressed.
       			{
       				status_light=MAN_YELLOW_2;
       				status_pedes=PEDES_OUTOFSTATE;               // tat pedes_light and buzzer neu co.
       				setTimer9(TIME_MANUAL_MODE);
       				setTimer4(10);
       			}
	    break;
	     default:
	     break;
	}
}

