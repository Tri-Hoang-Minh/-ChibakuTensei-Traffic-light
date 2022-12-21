/*
 * software_timer.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
extern int timer1_flag;
extern int timer1_counter;
void setTimer1(int time);


extern int timer2_flag;
extern int timer2_counter;
void setTimer2(int time);

extern int timer3_flag;
extern int timer3_counter;
void setTimer3(int time);

extern int timer4_flag;
extern int timer4_counter;
void setTimer4(int time);

extern int timer5_flag;
extern int timer5_counter;
void setTimer5(int time);

extern int timer6_flag;
extern int timer6_counter;
void setTimer6(int time);

extern int timer7_flag;
extern int timer7_counter;
void setTimer7(int time);

extern int timer8_flag;
extern int timer8_counter;
void setTimer8(int time);

extern int timer9_flag;
extern int timer9_counter;
void setTimer9(int time);


void TimerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
