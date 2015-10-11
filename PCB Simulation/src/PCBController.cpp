#include "PCBController.h"

PCBController::PCBController()
{
    readyQueue = new PCBQueue;
    blockedQueue = new PCBQueue;
}

PCBController::~PCBController()
{
    delete readyQueue;
    delete blockedQueue;
}

/// ///////////////////////////////////////////
/// Essential PCB Methods
PCB* PCBController::AllocatePCB()
{
    return new PCB;
}

void PCBController::FreePCB(PCB* pcb)
{
    delete pcb;
}

PCB* PCBController::SetupPCB(std::string processName, short processPriority, bool processClass)
{
    PCB* newProcess = NULL;
    if(FindPCB(processName) == NULL)
    {
        if(processPriority >= PRIORITY_MIN && processPriority <= PRIORITY_MAX)
        {
            ///No need to check for class due to implementation as boolean
            newProcess = AllocatePCB();

            newProcess -> setName(processName);
            newProcess -> setPriority(processPriority);
            newProcess -> setClass(processClass);
            newProcess -> setState(READY);
        }
        else
        {
            std::cout << "Invalid process priority" << std::endl;
        }
    }
    else
    {
        std::cout << "Already a process with that name" << std::endl;
    }

    return newProcess;
}

PCB* PCBController::FindPCB(std::string processName)
{
    PCB* foundPCB = NULL;

    //Searching ready queue
    PCBNode* currentNode = readyQueue -> getHead();
    while(currentNode != NULL)
    {
        if(currentNode -> getPCB() -> getName() == processName)
        {
            foundPCB = currentNode -> getPCB();
        }

        currentNode = currentNode -> getNext();
    }

    //Searching blocked queue
    currentNode = blockedQueue -> getHead();
    while(currentNode != NULL)
    {
        if(currentNode -> getPCB() -> getName() == processName)
        {
            foundPCB = currentNode -> getPCB();
        }

        currentNode = currentNode -> getNext();
    }

    return foundPCB;
}

void PCBController::InsertPCB(PCB* pcb)
{
    if(pcb -> getState() == READY)
    {
        readyQueue -> insert(pcb);
    }
    if(pcb -> getState() == BLOCKED)
    {
        blockedQueue -> insert(pcb);
    }
}

void PCBController::RemovePCB(PCB* pcb)
{
    if(pcb -> getState() == READY)
    {
        readyQueue -> remove(pcb);
    }
    if(pcb -> getState() == BLOCKED)
    {
        blockedQueue -> remove(pcb);
    }
}

/// ////////////////////////////////////////////
