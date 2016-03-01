#include "LSCommand.h"

LSCommand::LSCommand(PCBController* pcbController)
{
    setAlias("LS");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the Lottery Scheduler on file of processes");

    setPCBController(pcbController);
}

void LSCommand::execute(std::string arg)
{
    std::string fileName = arg;

    int totalNumberOfTickets = 0;
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

    ///Number of tickets
    goodInput = false;
    while(!goodInput)
    {
        std::cout << "Enter number for the total number of tickets: ";
        std::cin >> totalNumberOfTickets;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if(totalNumberOfTickets > 0)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid number of tickets. \nPlease enter a value greater than 0" << std::endl;
        }
    }


    LotteryScheduler ls(getPCBController());
    ls.loadProcesses(fileName);

    ls.runProcesses(totalNumberOfTickets);

    std::cout << "Processes ran. See LotterySchedulerResults.txt in OS folder." << std::endl;
}
