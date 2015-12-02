#include "PCB.h"

PCB::PCB()
{
    ///Setting default values
    setState(READY);
    setSuspended(false);
}

/// ///////////////////////////////////////////////
///Getters and setters

void PCB::setName(std::string processName)
{
    this -> processName = processName;
}

std::string PCB::getName()
{
    return processName;
}


void PCB::setClass(bool processClass)
{
    this -> processClass = processClass;
}

bool PCB::getClass()
{
    return processClass;
}


void PCB::setPriority(short priority)
{
    ///Testing purposes
    assert((priority >= -127 || priority <= 128) && "Priority must be between -127 and 128");

    this -> priority = priority;
}

short PCB::getPriority()
{
    return priority;
}


void PCB::setState(short state)
{
    ///Testing purposes
    assert((state >= RUNNING && state <= BLOCKED) && "State must be a valid state");

    this -> state = state;
}

short PCB::getState()
{
    return state;
}


void PCB::setSuspended(bool suspended)
{
    this -> suspended = suspended;
}

bool PCB::getSuspended()
{
    return suspended;
}


void PCB::setMemory(int memory)
{
    this -> memory = memory;
}

int PCB::getMemory()
{
    return memory;
}

void PCB::setExecutionTime(int executionTime)
{
    this -> executionTime = executionTime;
}

int PCB::getExecutionTime()
{
    return executionTime;
}

void PCB::setTimeRemaining(int timeRemaining)
{
    this -> timeRemaining = timeRemaining;
}

int PCB::getTimeRemaining()
{
    return timeRemaining;
}


void PCB::setTimeOfArrival(int timeOfArrival)
{
    this -> timeOfArrival = timeOfArrival;
}

int PCB::getTimeOfArrival()
{
    return timeOfArrival;
}


void PCB::setPercentageOfCPU(int percentageOfCPU)
{
    this -> percentageOfCPU = percentageOfCPU;
}

int PCB::getPercentageOfCPU()
{
    return percentageOfCPU;
}


/// /////////////////////////////////////////////////

///Used for the commands to show PCBs, no other reason to use
void PCB::printPCB()
{
///Process name
    std::cout << "\nProcess Name:     " << processName << std::endl;

///Process class
    std::cout << "Process Class:    ";
    if(processClass == APPLICATION_TYPE)
    {
        std::cout << "Application" << std::endl;
    }
    else if(processClass == SYSTEM_TYPE)
    {
        std::cout << "System" << std::endl;
    }

///Process priority
    std::cout << "Process Priority: " << priority << std::endl;

///Process State
    std::cout << "Process State:    ";
    ///Suspended or not...
    if(suspended)
    {
        std::cout << "Suspended-";
    }
    ///Running/Ready/Blocked
    if(state == RUNNING)
    {
        std::cout << "Running" << std::endl;
    }
    else if(state == READY)
    {
        std::cout << "Ready" << std::endl;
    }
    else if(state == BLOCKED)
    {
        std::cout << "Blocked" << std::endl;
    }

///Memory
    std::cout << "Process Memory:   " << memory << std::endl;
}


void PCB::printPCBSmall()
{
///Process name
    std::cout << "\nProcess Name: " << processName << " - ";

///Process class
    std::cout << "Class: ";
    if(processClass == APPLICATION_TYPE)
    {
        std::cout << "Application - ";
    }
    else if(processClass == SYSTEM_TYPE)
    {
        std::cout << "System - ";
    }

///Process priority
    std::cout << "Priority: " << priority << " - ";

///Process State
    std::cout << "Process State: ";
    ///Suspended or not...
    if(suspended)
    {
        std::cout << "S-";
    }
///Running/Ready/Blocked
    if(state == RUNNING)
    {
        std::cout << "Running ";
    }
    else if(state == READY)
    {
        std::cout << "Ready ";
    }
    else if(state == BLOCKED)
    {
        std::cout << "Blocked ";
    }
    std::cout << std::endl;
}
