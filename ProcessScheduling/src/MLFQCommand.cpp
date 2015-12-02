#include "MLFQCommand.h"

MLFQCommand::MLFQCommand(PCBController* pcbController)
{
    setAlias("MLFQ");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the Multilevel Feedback Queue Scheduler on file of processes");

    setPCBController(pcbController);
}


void MLFQCommand::execute(std::string arg)
{
    std::string fileName = arg;
    int numberOfQueues = 0;
    int timeQuantum = 0;
    int numberOfCycles = 0;
    bool goodInput = false;

    std::ifstream inputFile(fileName.c_str());

    if(inputFile)
    {
        goodInput = true;
    }

    ///File name
    while(!goodInput)
    {
        std::cout << "Enter the name of the file with the processes: ";
        std::cin >> fileName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        std::ifstream inputFile(fileName.c_str());
        if(inputFile)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid file name." << std::endl;
        }
    }

    ///Number of queues
    goodInput = false;
    while(!goodInput)
    {
        std::cout << "Enter number for the number of queues: ";
        std::cin >> numberOfQueues;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if(numberOfQueues > 0 && numberOfQueues < 256)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid number of queues. \nPlease enter a value greater than 0 and less than 256" << std::endl;
        }
    }

    ///Time Quantum
    goodInput = false;
    while(!goodInput)
    {
        std::cout << "Enter number for the time quantum: ";
        std::cin >> timeQuantum;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if(timeQuantum > 0)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid number for time quantum. \nPlease enter a value greater than 0" << std::endl;
        }
    }

    ///Number of cycles
    goodInput = false;
    while(!goodInput)
    {
        std::cout << "Enter number for the number of cycles: ";
        std::cin >> numberOfCycles;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if(numberOfCycles > 0)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid number of cycles. \nPlease enter a value greater than 0" << std::endl;
        }
    }


    MultilevelFeedbackQueue mlfq(getPCBController());
    mlfq.loadProcesses(fileName);

    mlfq.runProcesses(numberOfQueues, timeQuantum, numberOfCycles);

    std::cout << "Processes ran. See MultilevelFeedbackQueueResults.txt in OS folder." << std::endl;
}
