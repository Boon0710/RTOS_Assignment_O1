#include "assignment_irrigation.h"


int status = 0;


void irrigation_init()
{
    status = VALVE1_OPEN;
    setTimer(0, 500);
}

void irrigation_run()
{
    switch (status)
    {
    case VALVE1_OPEN:
    	openValve1();
        if (isTimerExpired(0))
        {
            closeValve1();
            status = VALVE2_OPEN;
            setTimer(0, 500);
        }
        break;
    case VALVE2_OPEN:
    	openValve2();
        if (isTimerExpired(0))
        {
            closeValve2();
            status = VALVE3_OPEN;
            setTimer(0, 500);
        }
        break;
    case VALVE3_OPEN:
    	openValve3();
        if (isTimerExpired(0))
        {
            closeValve3();
            status = PUMP1_ON;
            setTimer(0, 1000);
        }
        break;
    case PUMP1_ON:
    	openPump1();
        if (isTimerExpired(0))
        {
            closePump1();
            status = PUMP2_ON;
            setTimer(0, 3000);
        }
        break;
    case PUMP2_ON:
    	openPump2();
        if (isTimerExpired(0))
        {
            closePump2();
            status = IDLE;
            setTimer(0, 6000);
        }
        break;
    case IDLE:
        if (isTimerExpired(0))
        {
            status = VALVE1_OPEN;
            setTimer(0, 500);
        }
        break;
    default:
        break;
    }
}
