#ifndef PCB_H
#define PCB_H

///Used for processClass
#define APPLICATION_TYPE    false
#define SYSTEM_TYPE         true

///Used for State
#define RUNNING     1
#define READY       2
#define BLOCKED     3

///Used for priority
#define PRIORITY_MIN    -127
#define PRIORITY_MAX    128

#include <iostream> //std::cout, std::endl //Used for printPCB()
#include <string> //std::string
#include <assert.h> //assert()

class PCB
{
public:
    PCB();

    ///Getters and setters
    void setName(std::string);
    std::string getName();

    void setClass(bool);
    bool getClass();

    void setPriority(short);
    short getPriority();

    void setState(short);
    short getState();

    void setSuspended(bool);
    bool getSuspended();

    void setMemory(int);
    int getMemory();

    void setExecutionTime(int);
    int getExecutionTime();

    void setTimeRemaining(int);
    int getTimeRemaining();

    void setTimeOfArrival(int);
    int getTimeOfArrival();

    void setPercentageOfCPU(int);
    int getPercentageOfCPU();


    ///Methods
    void printPCB();
    void printPCBSmall();

private:
    ///Data
    std::string processName;
    bool processClass;

    short priority;
    short state;
    bool suspended;

    int memory;

    int executionTime;
    int timeRemaining;
    int timeOfArrival;
    int percentageOfCPU;
};

#endif // PCB_H
