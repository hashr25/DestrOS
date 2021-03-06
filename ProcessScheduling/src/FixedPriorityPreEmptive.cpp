#include "FixedPriorityPreEmptive.h"

FixedPriorityPreEmptive::FixedPriorityPreEmptive(PCBController* pcbController) :
    ProcessScheduler(pcbController)
{
    //Handled in init list
}

void FixedPriorityPreEmptive::sortProcesses()
{
    //No Sort
}

void FixedPriorityPreEmptive::runProcesses()
{
    int currentRunningTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int totalProcesses = 0;

    PCB* lastProcess = NULL;
    PCB* pcbToRun = NULL;

    std::ofstream outputFile;
    std::string fileName = "FixedPriorityPre-EmptiveResults.txt";
    outputFile.open(fileName, std::ofstream::out | std::ofstream::trunc); /// Clear file contents while opening


    while(getPCBController() -> getReadyQueue() -> getHead() != NULL || getPCBController() -> getRunningProcess() != NULL)
    {
        if(pcbToRun == NULL)
        {
            pcbToRun = getPCBController() -> findHighestPriorityPCB(currentRunningTime);
        }


        if(pcbToRun != lastProcess)
        {
            ///Run Process
            getPCBController() -> runPCB( pcbToRun );
            outputFile << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";
        }

/**
  *     NEED TO FIX THESE VALUE CALCULATIONS WITH THIS SCHEDULER
  */
        ///Calculate Numbers for this process
        //Increments by 1
        currentRunningTime++;
        totalWaitingTime++;
        //totalTurnAroundTime += currentRunningTime - pcbToRun -> getTimeOfArrival();
        totalProcesses++;
        ///Increment by 1
        pcbToRun -> setTimeRemaining( pcbToRun -> getTimeRemaining() - 1);

        ///Setting last process before pause or completion checks
        lastProcess = pcbToRun;

        ///This means that the next round will change the process, go ahead and output the data.
        if(getPCBController() -> findHighestPriorityPCB(currentRunningTime) != pcbToRun)
        {
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

            outputFile << "Pausing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n\n";
            getPCBController() -> pausePCB();
            pcbToRun = NULL;
        }
        ///This means the process is completely done.
        else if(pcbToRun -> getTimeRemaining() <= 0)
        {
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
            outputFile << "Completing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n\n";
            getPCBController() -> completePCB();
            pcbToRun = NULL;
        }

    }

    outputFile << "Total Time To Completion: " << totalWaitingTime << "\n";
    outputFile << "Average Turn Around Time: " << totalTurnAroundTime / totalProcesses << "\n";
    outputFile << "Average Waiting Time:     " << totalWaitingTime / totalProcesses << "\n";

    outputFile.close();
}
