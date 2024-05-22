/*
 * scheduler.h
 *
 *  Created on: Nov 7, 2022
 *      Author: KAI
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

// Task structure
typedef struct Task
{
    void (*pTask)();
    uint32_t Delay;
    uint32_t Period;
    uint32_t RunMe;
    struct Task *next;
} Task;

// Scheduler structure
typedef struct Scheduler
{
    Task *head;
} Scheduler;

// Function prototypes
void SCH_Init(Scheduler *scheduler);
void SCH_Add_Task(Scheduler *scheduler, void (*pFunction)(), uint32_t delay, uint32_t period);
void SCH_Update(Scheduler *scheduler);
void SCH_Dispatch_Tasks(Scheduler *scheduler);

#endif /* INC_SCHEDULER_H_ */