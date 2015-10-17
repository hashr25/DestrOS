#include "SJFCommand.h"

SJFCommand::SJFCommand(PCBController* pcbController)
{
    setAlias("SJF");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the Shortest Job First Scheduler on file of processes");

    setPCBController(pcbController);
}

void SJFCommand::execute(std::string arg)
{
    std::string fileName = arg;
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

    ShortestJobFirst sjf(getPCBController());
    sjf.loadProcesses(fileName);

    sjf.sortProcesses();
    sjf.runProcesses();

    std::cout << "Processes ran. See ShortestJobFirstResults.txt in OS folder." << std::endl;
}
