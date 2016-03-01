#include "LotteryScheduler.h"

LotteryScheduler::LotteryScheduler(PCBController* pcbController) :
    ProcessScheduler(pcbController)
{
    //Handled in init list
    srand(time(NULL)); //Sets the random seed
}

void LotteryScheduler::sortProcesses()
{
    //No sort
}

void LotteryScheduler::runProcesses()
{
    //Nothing...
    //Must run the version with int parameter
}

void LotteryScheduler::runProcesses(int totalNumberOfTickets)
{
    int ticketsPerPercent = totalNumberOfTickets / 100;
    int currentNumberOfTickets = totalNumberOfTickets;

    getPCBController() -> setTickets(ticketsPerPercent);
    Command* printer = new ShowAllPCBCommand(getPCBController());
    printer -> execute("");
    delete printer;

    int currentRunningTime = 0;
    int totalWaitingTime = 0;
    int totalProcesses = 0;
    int totalTurnAroundTime = 0;

    PCB* lastProcess = NULL;
    PCB* pcbToRun = NULL;

    std::ofstream outputFile;
    std::string fileName = "LotterySchedulerResults.txt";
    outputFile.open(fileName, std::ofstream::out | std::ofstream::trunc); /// Clear file contents while opening

    outputFile << "Performing Lottery Scheduler with " << totalNumberOfTickets << " tickets total.\n\n";

    while(getPCBController() -> getReadyQueue() -> getHead() != NULL || getPCBController() -> getRunningProcess() != NULL)
    {
        ///No process running
        if(pcbToRun == NULL)
        {
            int randomTicket = rand() % currentNumberOfTickets;
            //std::cout << "Pulling ticket #" << randomTicket << std::endl;

            ///Find Ticketed PCB
            pcbToRun = getPCBController() -> findTicketedPCB(randomTicket);



            ///Run Process
            getPCBController() -> runPCB( pcbToRun );
            outputFile << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";
            //std::cout << "Running Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n";
        }


/**
  *     NEED TO FIX THESE VALUE CALCULATIONS WITH THIS SCHEDULER
  */
        ///Calculate Numbers for this process
        //Increments by 1
        currentRunningTime++;
        totalWaitingTime++;
        totalTurnAroundTime += currentRunningTime - pcbToRun -> getTimeOfArrival();
        totalProcesses++;
        ///Increment by 1
        pcbToRun -> setTimeRemaining( pcbToRun -> getTimeRemaining() - 1);

        ///Setting last process before pause or completion checks
        lastProcess = pcbToRun;

        ///This means the process is completely done.
        if(pcbToRun -> getTimeRemaining() <= 0)
        {
            //Reduce number of tickets because of completed pcb
            currentNumberOfTickets = currentNumberOfTickets - lastProcess -> getNumberOfTickets();

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
            //std::cout << "Completing Process: " << getPCBController() -> getRunningProcess() -> getName() << "\n\n";
            getPCBController() -> completePCB();
            pcbToRun = NULL;
        }
    }

    outputFile << "Total Time To Completion: " << totalWaitingTime << "\n";
    outputFile << "Average Turn Around Time: " << totalTurnAroundTime / totalProcesses << "\n";
    outputFile << "Average Waiting Time:     " << totalWaitingTime / totalProcesses << "\n";

    outputFile.close();
}
