/*
 * FSM_MANUALMODE.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
#include "FSM_MANUALMODE.h"

void fsm_manual_mode()
{
     switch(status_light)
     {
        case MAN_GREEN_1:
        	// Traffic light 1 is GREEN and traffic light 2 is RED.
       	     ToggleLEDGreen(0);
        	 ToggleLEDRed(1);

        	// TODO: Implementation fsm_button for CHANGE MODE In MAN_GREEN_1.
        	 if(is_button_pressed(1))  // button 1 is Pressed.
        	 {
        		 setTimer9(TIME_MANUAL_MODE);  // 10s
        		 status_light=MAN_YELLOW_1;
        	 }
        	 // TODO: Implementation if no buttion is pressed in 10s.
        	 if(timer9_flag==1)
        	 {
        		 status_light=AUTO_YELLOW_1; //(YELLOW in traffic light 1 on, RED in traffic light 2 on)
        		 setTimer1(time_led_yellow_1);
           		 setTimer2(time_led_yellow_1);
           		 setTimer4(10);
        	 }
        	 // TODO: Implementation function , if button 3 is pressed, system will change state (MAN_GREEN_1 => AUTO_YELLOW_1_)
        	 if(is_button_pressed(3))  // button 3 is Pressed.
        	 {
        		 status_light=AUTO_YELLOW_1; //(YELLOW in traffic light 1 on, RED in traffic light 2 on)
        		 setTimer1(time_led_yellow_1);
           		 setTimer2(time_led_yellow_1);
           		 setTimer4(10);
        	 }
        	 //TODO: Implementation function, if button 3 is holded 1s, system will changea all state MANUAL => AUTO_INIT.
        	 if(is_button_pressed_1s(2))  // button 2 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 if(is_button_pressed(2))  // button 2 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 break;


        case MAN_YELLOW_1:
        	// Traffic light 1 is YELLOW and traffic light 2 is RED.
       	     ToggleLEDYellow(0);
        	 ToggleLEDRed(1);

        	// TODO: Implementation fsm_button for CHANGE MODE In MAN_GREEN_1.
        	 if(is_button_pressed(1))  // button 1 is Pressed.
        	 {
        		 setTimer9(TIME_MANUAL_MODE);  // 10s
        		 status_light=MAN_GREEN_2;
        	 }
        	 // TODO: Implementation if no buttion is pressed in 10s.
        	 if(timer9_flag==1)
        	 {
        		 status_light=AUTO_GREEN_2; //(RED in traffic light 1 on, GREEN in traffic light 2 on)
        		 setTimer2(time_led_green_2);
        		 setTimer1(time_led_red_1);
           		 setTimer4(10);
        	 }
        	 // TODO: Implementation function , if button 3 is pressed, system will change state (MAN_YELLOW_1 => AUTO_GREEN_2)
        	 if(is_button_pressed(3))  // button 1 is Pressed.
        	 {
        		 status_light=AUTO_GREEN_2; //(RED in traffic light 1 on, GREEN in traffic light 2 on)
        		 setTimer2(time_led_green_2);
        		 setTimer1(time_led_red_1);
           		 setTimer4(10);
        	 }
        	 //TODO: Implementation function, if button 3 is holded 1s, system will changea all state MANUAL => AUTO_INIT.
        	 if(is_button_pressed_1s(2))  // button 3 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 if(is_button_pressed(2))  // button 2 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 break;

        case MAN_GREEN_2:
        	// Traffic light 1 is RED and traffic light 2 is GREEN.
       	     ToggleLEDRed(0);
        	 ToggleLEDGreen(1);
       // 	 sendDATA();

        	// TODO: Implementation fsm_button for CHANGE MODE In MAN_GREEN_1.
        	 if(is_button_pressed(1))  // button 1 is Pressed.
        	 {
        		 setTimer9(TIME_MANUAL_MODE);  // 10s
        		 status_light=MAN_YELLOW_2;
        	 }
        	 // TODO: Implementation if no buttion is pressed in 10s.
        	 if(timer9_flag==1)
        	 {
        		 status_light=AUTO_YELLOW_2; //(RED in traffic light 1 on, YELLOW in traffic light 2 on)
        		 setTimer1(time_led_yellow_2);
        		 setTimer2(time_led_yellow_2);
           		 setTimer4(10);
        	 }
        	 // TODO: Implementation function , if button 3 is pressed, system will change state (MAN_GREEN_2 => AUTO_YELLOW_2)
        	 if(is_button_pressed(3))  // button 1 is Pressed.
        	 {
        		 status_light=AUTO_YELLOW_2; //(RED in traffic light 1 on, YELLOW in traffic light 2 on)
        		 setTimer1(time_led_yellow_2);
        		 setTimer2(time_led_yellow_2);
           		 setTimer4(10);
        	 }
        	 //TODO: Implementation function, if button 3 is holded 1s, system will changea all state MANUAL => AUTO_INIT.
        	 if(is_button_pressed_1s(2))  // button 1 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 if(is_button_pressed(2))  // button 2 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 break;

        case MAN_YELLOW_2:
        	// Traffic light 1 is RED and traffic light 2 is YELLOW.
       	     ToggleLEDRed(0);
        	 ToggleLEDYellow(1);
      //  	 sendDATA();

        	// TODO: Implementation fsm_button for CHANGE MODE In MAN_GREEN_1.
        	 if(is_button_pressed(1))  // button 1 is Pressed.
        	 {
        		 setTimer9(TIME_MANUAL_MODE);  // 10s
        		 status_light=MAN_GREEN_1;
        	 }
        	 // TODO: Implementation if no buttion is pressed in 10s.
        	 if(timer9_flag==1)
        	 {
        		 status_light=AUTO_GREEN_1; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        		 setTimer2(time_led_red_2);
        		 setTimer1(time_led_green_1);
           		 setTimer4(10);
        	 }
        	 // TODO: Implementation function , if button 3 is pressed, system will change state (MAN_YELLOW_2 => AUTO_GREEN_1)
        	 if(is_button_pressed(3))  // button 1 is Pressed.
        	 {
        		 status_light=AUTO_GREEN_1; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        		 setTimer2(time_led_red_2);
        		 setTimer1(time_led_green_1);
           		 setTimer4(10);
        	 }
        	 //TODO: Implementation function, if button 3 is holded 1s, system will changea all state MANUAL => AUTO_INIT.
        	 if(is_button_pressed_1s(2))  // button 1 is holded 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 if(is_button_pressed(2))  // button 2 is pressed 1s.
        	 {
        		 status_light=AUTO_INIT; //(GREEN in traffic light 1 on, RED in traffic light 2 on)
        	 }
        	 break;
        default:
        	break;
     }
}
