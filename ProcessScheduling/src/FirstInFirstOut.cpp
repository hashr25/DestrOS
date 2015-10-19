#include "FirstInFirstOut.h"

FirstInFirstOut::FirstInFirstOut(PCBController* pcbController) :
    ProcessScheduler(pcbController)
{
    //Handled in Init list
}

void FirstInFirstOut::sortProcesses()
{
    int size = getPCBController() -> getReadyQueue() -> getSize();
    PCB** sortedProcesses = new PCB*[size];
    for(unsigned int i = 0; i < size; i++)
    {
        sortedProcesses[i] = getPCBController() -> getReadyQueue() -> remove();
    }

    //Sorts array
    qSort(sortedProcesses, 0, size-1);

    //puts back into queue
    for(unsigned int i = 0; i < size; i++)
    {
        getPCBController() -> InsertPCB(sortedProcesses[i]);
    }
}

void FirstInFirstOut::runProcesses()
{
    int currentRunningTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int totalProcesses = 0;


    std::ofstream outputFile;
    std::string fileName = "FirstInFirstOutResults.txt";
    outputFile.open(fileName, std::ofstream::out | std::ofstream::trunc); //Clear content at file open

    int size = getPCBController() -> getReadyQueue() -> getSize();

    for(unsigned int i = 0; i < size; i++)
    {
        PCB* pcbToRun = getPCBController() -> getReadyQueue() -> getHead() -> getPCB();


        ///Run Process
        getPCBController() -> runPCB( pcbToRun );
        outputFile << "Running Process: " << pcbToRun -> getName() << "\n";

        ///Calculate Numbers for this process
        int processTimeJustRan = pcbToRun -> getTimeRemaining();
        currentRunningTime += processTimeJustRan;
        totalWaitingTime +=processTimeJustRan;
        totalTurnAroundTime += currentRunningTime - pcbToRun -> getTimeOfArrival();
        totalProcesses++;

        ///This scheduler runs till completion
        pcbToRun -> setTimeRemaining(0);

        ///Process Details
        outputFile << "Process Details: \n";
        outputFile << "    Name:            " << pcbToRun -> getName() << "\n";
        outputFile << "    Class:           " << pcbToRun -> getClass() << "\n";
        outputFile << "    Priority:        " << pcbToRun -> getPriority() << "\n";
        outputFile << "    Memory:          " << pcbToRun -> getMemory() << "\n";
        outputFile << "    Execution Time:  " << pcbToRun -> getExecutionTime() << "\n";
        outputFile << "    Time Remaining:  " << pcbToRun -> getTimeRemaining() << "\n";
        outputFile << "    Time of Arrival: " << pcbToRun -> getTimeOfArrival() << "\n";
        outputFile << "    CPU %:           " << pcbToRun -> getPercentageOfCPU() << "\n";

        ///Finish Process
        outputFile << "Completing Process: " << pcbToRun -> getName() << "\n\n";
        getPCBController() -> completePCB();
    }

    outputFile << "Total Time To Completion: " << totalWaitingTime << "\n";
    outputFile << "Average Turn Around Time: " << totalTurnAroundTime / totalProcesses << "\n";
    outputFile << "Average Waiting Time:     " << totalWaitingTime / totalProcesses << "\n";

    outputFile.close();
}

///Taken directly from my Data Structures assignment
void FirstInFirstOut::qSort(PCB** array, int left, int right)
{
    int swapLeft = left;
    int swapRight = right;
    int pivot = array[(left+right)/2] -> getTimeOfArrival();

    while(swapLeft <= swapRight)
    {
        while(array[swapLeft]->getTimeOfArrival() < pivot)
        {
            swapLeft++;
        }
        while(array[swapRight]->getTimeOfArrival() > pivot)
        {
            swapRight--;
        }
        if(swapLeft <= swapRight)
        {
            PCB* temp = array[swapLeft];
            array[swapLeft] = array[swapRight];
            array[swapRight] = temp;

            swapLeft++;
            swapRight--;
        }
    }

    if(left < swapRight)
    {
        qSort(array, left, swapRight);
    }
    if(swapLeft < right)
    {
        qSort(array, swapLeft, right);
    }
}
