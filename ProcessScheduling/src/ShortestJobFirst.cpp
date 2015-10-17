#include "ShortestJobFirst.h"

ShortestJobFirst::ShortestJobFirst(PCBController* pcbController) :
    ProcessScheduler(pcbController)
{
    ///Handled in init list
}


void ShortestJobFirst::sortProcesses()
{
    /**
        Vector WAY

    std::vector<PCB*> sortedProcesses;
    //Copies current queue into local vector
    for(unsigned int i = 0; i < getPCBController() -> getReadyQueue() -> getSize(); i++)
    {
        sortedProcesses.push_back(getPCBController() -> getReadyQueue() -> remove());
    }std::cout << "Finished copying into vector" << std::endl;


    //Sorts the vector with quicksort based on the time remaining
    qSort(sortedProcesses, 0, sortedProcesses.size()-1);
    std::cout << "Finished sorting" << std::endl;

    //Puts vector back into queue
    for(unsigned int i = 0; i < sortedProcesses.size(); i++)
    {
        getPCBController() -> InsertPCB(sortedProcesses.at(i));
    }std::cout << "Finished putting back into queue." << std::endl;


        For whatever reason this was not completely sorting the vector
    */

    /**
        Array WAY
                */
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

void ShortestJobFirst::runProcesses()
{
    int totalRunTime = 0;
    int totalProcesses = 0;


    std::ofstream outputFile;
    std::string fileName = "ShortestJobFirstResults.txt";
    outputFile.open(fileName);

    int size = getPCBController() -> getReadyQueue() -> getSize();

    for(unsigned int i = 0; i < size; i++)
    {
        PCB* pcbToRun = getPCBController() -> getReadyQueue() -> getHead() -> getPCB();

        ///Run Process
        getPCBController() -> runPCB( pcbToRun );
        outputFile << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";

        ///Process Details
        outputFile << "Process Details: " << pcbToRun -> getName() << " ";
        outputFile << pcbToRun -> getClass() << " ";
        outputFile << pcbToRun -> getPriority() << " ";
        outputFile << pcbToRun -> getMemory() << " ";
        outputFile << pcbToRun -> getTimeRemaining() << " ";
        outputFile << pcbToRun -> getTimeOfArrival() << " ";
        outputFile << pcbToRun -> getPercentageOfCPU() << "\n";

        ///Finish Process
        totalRunTime += getPCBController() -> getRunningProcess() -> getTimeRemaining();
        totalProcesses++;

        outputFile << "Completing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";

        getPCBController() -> completePCB();
    }

    outputFile << "Average Turn Around Time: " << totalRunTime / totalProcesses << "\n";

    outputFile.close();
}

///Taken directly from my Data Structures assignment
void ShortestJobFirst::qSort(std::vector<PCB*>& vect, int left, int right)
{
    int swapLeft = left;
    int swapRight = right;
    int pivot = vect.at((left+right)/2) -> getTimeRemaining();

    while(swapLeft <= swapRight)
    {
        while(vect.at(swapLeft)->getTimeRemaining() < pivot)
        {
            swapLeft++;
        }
        while(vect.at(swapRight)->getTimeRemaining() > pivot)
        {
            swapRight--;
        }
        if(swapLeft <= swapRight)
        {
            PCB* temp = vect.at(swapLeft);
            vect.at(swapLeft) = vect.at(swapRight);
            vect.at(swapRight) = temp;

            swapLeft++;
            swapRight--;
        }
    }

    if(left < swapRight)
    {
        qSort(vect, left, swapRight);
    }
    if(swapLeft < right)
    {
        qSort(vect, swapLeft, right);
    }
}

void ShortestJobFirst::qSort(PCB** array, int left, int right)
{
    int swapLeft = left;
    int swapRight = right;
    int pivot = array[(left+right)/2] -> getTimeRemaining();

    while(swapLeft <= swapRight)
    {
        while(array[swapLeft]->getTimeRemaining() < pivot)
        {
            swapLeft++;
        }
        while(array[swapRight]->getTimeRemaining() > pivot)
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
