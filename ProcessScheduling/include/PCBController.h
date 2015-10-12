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
/// ///////////////////////////////////////////

    PCBQueue* getReadyQueue();
    PCBQueue* getBlockedQueue();

private:
    PCBQueue* readyQueue;
    PCBQueue* blockedQueue;
};

#endif // PCBCONTROLLER_H
