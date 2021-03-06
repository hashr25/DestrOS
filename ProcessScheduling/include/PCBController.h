#ifndef PCBCONTROLLER_H
#define PCBCONTROLLER_H

#include <iostream> //std::cout, std::endl //Testing purposes

#include "PCB.h"
#include "PCBNode.h"
#include "PCBQueue.h"

class PCBController
{
public:
    PCBController();
    ~PCBController();

/// ///////////////////////////////////////////
/// Essential PCB Methods
    PCB* AllocatePCB();
    void FreePCB(PCB*);
    PCB* SetupPCB(std::string, short, bool);
    PCB* FindPCB(std::string);
    void InsertPCB(PCB*);
    void RemovePCB(PCB*);
    void RemovePCB();

/// ///////////////////////////////////////////

    void runPCB(PCB*);
    void runNextPCB();
    void completePCB();
    void pausePCB();

    PCB* findShortestPCB(int);
    PCB* findHighestPriorityPCB(int);
    PCB* findNextInPriorityQueue(int, int);
    PCB* findTicketedPCB(int);

    PCBQueue* getReadyQueue();
    PCBQueue* getBlockedQueue();

    PCB* getRunningProcess();
    void setTickets(int);

private:
    PCBQueue* readyQueue;
    PCBQueue* blockedQueue;
    PCB* runningProcess;
};

#endif // PCBCONTROLLER_H
