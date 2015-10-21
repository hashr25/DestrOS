#include "PCBController.h"

PCBController::PCBController()
{
    readyQueue = new PCBQueue;
    blockedQueue = new PCBQueue;
    runningProcess = NULL;
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
    pcb = NULL;
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

void PCBController::RemovePCB()
{
    readyQueue -> remove();
}

/// ////////////////////////////////////////////

void PCBController::runPCB(PCB* pcb)
{
    runningProcess = pcb;
    RemovePCB(pcb);
    runningProcess -> setState(RUNNING);
}

void PCBController::runNextPCB()
{
    runningProcess = getReadyQueue() -> getHead() -> getPCB();
    RemovePCB();
    runningProcess -> setState(RUNNING);
}

void PCBController::completePCB()
{
    delete runningProcess;
    runningProcess = NULL;
}

void PCBController::pausePCB()
{
    InsertPCB(runningProcess);
    runningProcess = NULL;
}

PCB* PCBController::findShortestPCB(int currentTime)
{
    PCB* blankPCB = new PCB;
    blankPCB -> setTimeRemaining(999999);///Massive time remaining
    PCB* toReturn = blankPCB;

    if(runningProcess != NULL)
    {
        blankPCB -> setTimeRemaining(runningProcess -> getTimeRemaining());
    }

    if(getReadyQueue() -> getHead() != NULL)
    {
        PCBNode* currentSpotInQueue = getReadyQueue() -> getHead();

        while(currentSpotInQueue != NULL)
        {
            if( ( currentSpotInQueue -> getPCB() -> getTimeRemaining() <= toReturn -> getTimeRemaining() ) &&
                ( currentTime >= currentSpotInQueue -> getPCB() -> getTimeOfArrival() ) )
            {
                toReturn = currentSpotInQueue -> getPCB();
            }

            currentSpotInQueue = currentSpotInQueue -> getNext();
        }

    }

    if(toReturn == blankPCB)
    {
        toReturn = NULL;
    }
    delete blankPCB;

    if(runningProcess != NULL && toReturn == NULL)
    {
        toReturn = runningProcess;
    }

    return toReturn;
}

PCB* PCBController::findHighestPriorityPCB(int currentTime)
{
    PCB* blankPCB = new PCB;
    blankPCB -> setPriority(-127); //Min priority
    PCB* toReturn = blankPCB;

    if(runningProcess != NULL)
    {
        blankPCB -> setPriority(runningProcess -> getPriority());
    }

    if(getReadyQueue() -> getHead() != NULL)
    {
        PCBNode* currentSpotInQueue = getReadyQueue() -> getHead();

        while(currentSpotInQueue != NULL)
        {
            if( ( currentSpotInQueue -> getPCB() -> getPriority() >= toReturn -> getPriority() ) &&
                ( currentTime >= currentSpotInQueue -> getPCB() -> getTimeOfArrival() ) )
            {
                toReturn = currentSpotInQueue -> getPCB();
            }

            currentSpotInQueue = currentSpotInQueue -> getNext();
        }

    }

    if(toReturn == blankPCB)
    {
        toReturn = NULL;
    }
    delete blankPCB;

    if(runningProcess != NULL && toReturn == NULL)
    {
        toReturn = runningProcess;
    }

    return toReturn;
}

PCB* findNextPCB(PCB* currentPCB)
{

}

PCBQueue* PCBController::getReadyQueue()
{
    return readyQueue;
}


PCBQueue* PCBController::getBlockedQueue()
{
    return blockedQueue;
}

PCB* PCBController::getRunningProcess()
{
    return runningProcess;
}
