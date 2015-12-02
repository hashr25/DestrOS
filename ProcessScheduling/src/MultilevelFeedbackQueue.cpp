#include "MultilevelFeedbackQueue.h"

MultilevelFeedbackQueue::MultilevelFeedbackQueue(PCBController* pcbController) :
    ProcessScheduler(pcbController)
{
    //Handled in init list
}

void MultilevelFeedbackQueue::sortProcesses()
{
    //No sort
}

void MultilevelFeedbackQueue::runProcesses()
{
    //Nothing...
    //Must run the version with int parameters
}

void MultilevelFeedbackQueue::runProcesses(int numberOfQueues, int timeQuantum, int numberOfCycles)
{
    int currentRunningTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int totalProcesses = 0;

    int quantumTracker = 0;
    int cycleTracker = 0;

    int currentQueue = numberOfQueues;
    int currentMinPriority = getMinPriority(numberOfQueues, currentQueue);
    int currentMaxPriority = getMaxPriority(numberOfQueues, currentQueue);

    PCB* lastProcess = NULL;
    PCB* pcbToRun = NULL;

    std::ofstream outputFile;
    std::string fileName = "MultilevelFeedbackQueuesResults.txt";
    outputFile.open(fileName, std::ofstream::out | std::ofstream::trunc); /// Clear file contents while opening

    outputFile << "Performing Multilevel Feedback Queue with " << numberOfQueues << " queues.\n\n";

    while(getPCBController() -> getReadyQueue() -> getHead() != NULL || getPCBController() -> getRunningProcess() != NULL)
    {
        std::cout << "Cycle #" << cycleTracker << std::endl;


        ///No process running
        if(pcbToRun == NULL)
        {
            ///Current Queue has no processes in it
            while(getPCBController() -> findNextInPriorityQueue(currentMinPriority, currentMaxPriority) == NULL)
            {
                std::cout << "Switching queue from " << currentQueue;

                cycleTracker = 0;

                //Queue 1 is the bottom, queue #numberOfQueues is top
                if(currentQueue == 1)
                {std::cout << "going back to top queue" << std::endl;
                    currentQueue = numberOfQueues;
                }
                else
                {std::cout << "going down a queue" << std::endl;
                    currentQueue--;
                }
                std::cout << " to " << currentQueue << std::endl;

                currentMinPriority = getMinPriority(numberOfQueues, currentQueue);
                currentMaxPriority = getMaxPriority(numberOfQueues, currentQueue);
            }

            ///Run a process
            pcbToRun = getPCBController() -> findNextInPriorityQueue(currentMinPriority, currentMaxPriority);
            std::cout << "Got " << pcbToRun -> getName() << " to run in queue " << currentQueue << std::endl;

            ///Run Process
            getPCBController() -> runPCB( pcbToRun );
            outputFile << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";
            std::cout << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";
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
        quantumTracker++;

        ///Setting last process before pause or completion checks
        lastProcess = pcbToRun;


        ///This means that the next round will change the process, go ahead and output the data.
        if( quantumTracker >= timeQuantum )
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
            std::cout << "Pausing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n\n";

            ShowReadyPCBCommand sr(getPCBController());
            sr.execute("");

            pcbToRun -> setState(READY);
            getPCBController() -> pausePCB();
            pcbToRun = NULL;

            std::cout << "After Insert" << std::endl;
            sr.execute("");

            quantumTracker = 0;
            cycleTracker++;
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
            std::cout << "Completing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n\n";
            getPCBController() -> completePCB();
            pcbToRun = NULL;
            cycleTracker++;
        }

        ///Time to switch queues
        if( cycleTracker >= numberOfCycles &&
            pcbToRun == NULL )
        {
            std::cout << "Switching queue from " << currentQueue;

            cycleTracker = 0;

            //Queue 1 is the bottom, queue #numberOfQueues is top
            if(currentQueue == 1)
            {std::cout << "going back to top queue" << std::endl;
                currentQueue = numberOfQueues;
            }
            else
            {std::cout << "going down a queue" << std::endl;
                currentQueue--;
            }
            std::cout << " to " << currentQueue << std::endl;

            currentMinPriority = getMinPriority(numberOfQueues, currentQueue);
            currentMaxPriority = getMaxPriority(numberOfQueues, currentQueue);
        }
    }

    outputFile << "Total Time To Completion: " << totalWaitingTime << "\n";
    outputFile << "Average Turn Around Time: " << totalTurnAroundTime / totalProcesses << "\n";
    outputFile << "Average Waiting Time:     " << totalWaitingTime / totalProcesses << "\n";

    outputFile.close();
}

int MultilevelFeedbackQueue::getQueueGap(int numberOfQueues)
{
    int queueGap = 256 / numberOfQueues;

    ///Ceiling
    if( numberOfQueues * queueGap < 256 )
    {
        queueGap++;
    }

    return queueGap;
}

int MultilevelFeedbackQueue::getMinPriority(int numberOfQueues, int currentQueue)
{
    return (getQueueGap(numberOfQueues) * (currentQueue - 1) ) - 127;
}

int MultilevelFeedbackQueue::getMaxPriority(int numberOfQueues, int currentQueue)
{
     return (getQueueGap(numberOfQueues) * currentQueue ) - 127;
}
