#include "SchedulePCB.h"

SchedulePCB::SchedulePCB()
{
    ///Nothing to initialize
}

///Getters and setters
void SchedulePCB::setTimeRemaining(int timeRemaining)
{
    this -> timeRemaining = timeRemaining;
}

int SchedulePCB::getTimeRemaining()
{
    return timeRemaining;
}


void SchedulePCB::setTimeOfArrival(int timeOfArrival)
{
    this -> timeOfArrival = timeOfArrival;
}

int SchedulePCB::getTimeOfArrival()
{
    return timeOfArrival;
}


void SchedulePCB::setPercentageOfCPU(int percentageOfCPU)
{
    this -> percentageOfCPU = percentageOfCPU;
}

int SchedulePCB::getPercentageOfCPU()
{
    return percentageOfCPU;
}
