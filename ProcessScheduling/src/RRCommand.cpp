#include "RRCommand.h"

RRCommand::RRCommand(PCBController* pcbController)
{
    setAlias("RR");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the Round Robin Scheduler on file of processes");

    setPCBController(pcbController);
}

void RRCommand::execute(std::string arg)
{
    std::string fileName = arg;
    int timeQuantum = 0;
    bool goodInput = false;

    std::ifstream inputFile(fileName.c_str());

    if(inputFile)
    {
        goodInput = true;
    }

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
            std::cout << "That is not a valid time quantum. \nPlease enter a value greater than 0." << std::endl;
        }
    }


    RoundRobin rr(getPCBController());
    rr.loadProcesses(fileName);

    rr.runProcesses(timeQuantum);

    std::cout << "Processes ran. See RoundRobinResults.txt in OS folder." << std::endl;
}
