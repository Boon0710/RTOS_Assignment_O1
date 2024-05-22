#include "scheduler.h"
#include <stdlib.h>
#include <stddef.h>

void SCH_Init(Scheduler *scheduler)
{
    scheduler->head = NULL;
}

// Add task to scheduler
void SCH_Add_Task(Scheduler *scheduler, void (*pFunction)(), uint32_t delay, uint32_t period)
{
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->pTask = pFunction;
    new_task->Delay = delay;
    new_task->Period = period;
    new_task->RunMe = 0;
    new_task->next = NULL;

    if (scheduler->head == NULL)
    {
        scheduler->head = new_task;
    }
    else
    {
        if (new_task->Delay < scheduler->head->Delay)
        {
            new_task->next = scheduler->head;
            scheduler->head->Delay -= new_task->Delay;
            scheduler->head = new_task;
        }
        else
        {
            Task *current = scheduler->head;
            new_task->Delay -= current->Delay;

            while (current->next && current->next->Delay < new_task->Delay)
            {
                current = current->next;
                new_task->Delay -= current->Delay;
            }

            new_task->next = current->next;
            current->next = new_task;

            Task *remaining = new_task->next;
            int prev_delay = new_task->Delay;
            while (remaining)
            {
                remaining->Delay -= prev_delay;
                prev_delay = remaining->Delay;
                remaining = remaining->next;
            }
        }
    }
}

// Update scheduler
void SCH_Update(Scheduler *scheduler)
{
    Task *update_task = scheduler->head;
    if (update_task)
    {
        if (update_task->Delay > 1)
        {
            update_task->Delay -= 1;
        }
        else
        {
            update_task->RunMe += 1;
            update_task->Delay = update_task->Period;
        }
    }
}

// Dispatch tasks
void SCH_Dispatch_Tasks(Scheduler *scheduler)
{
    Task *dispatch_task = scheduler->head;

    if (dispatch_task->RunMe > 0)
    {
        dispatch_task->RunMe -= 1;
        dispatch_task->pTask();

        scheduler->head = scheduler->head->next;
        SCH_Add_Task(scheduler, dispatch_task->pTask, dispatch_task->Delay, dispatch_task->Period);
        free(dispatch_task);
    }
}


