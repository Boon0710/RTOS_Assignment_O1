#ifndef IRRIGATION_H_
#define IRRIGATION_H_

#include "software_timer.h"

#define VALVE1_OPEN 1
#define VALVE2_OPEN 2
#define VALVE3_OPEN 3
#define PUMP1_ON 4
#define PUMP2_ON 5
#define IDLE 7

void irrigation_init();
void irrigation_run();

void openValve1();
void closeValve1();

void openValve2();
void closeValve2();

void openValve3();
void closeValve3();

void openPump1();
void closePump1();

void openPump2();
void closePump2();
#endif
