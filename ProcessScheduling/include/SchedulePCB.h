#ifndef SCHEDULEPCB_H
#define SCHEDULEPCB_H

#include "PCB.h"


class SchedulePCB : public PCB
{
public:
    SchedulePCB();

    ///Getters and setters
    void setTimeRemaining(int);
    int getTimeRemaining();

    void setTimeOfArrival(int);
    int getTimeOfArrival();

    void setPercentageOfCPU(int);
    int getPercentageOfCPU();

private:
    int timeRemaining;
    int timeOfArrival;
    int percentageOfCPU;
};

#endif // SCHEDULEPCB_H
