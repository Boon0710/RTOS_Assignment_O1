/*
 * software_timer.h
 *
 *  Created on: Apr 1, 2024
 *      Author: DELL
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_


void setTimer(int index, int value);
int isTimerExpired(int index);

void timerRun();
#endif /* SRC_SOFTWARE_TIMER_H_ */
