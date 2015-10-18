#include "FIFOCommand.h"

FIFOCommand::FIFOCommand(PCBController* pcbController)
{
    setAlias("FIFO");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the First In First Out on file of processes");

    setPCBController(pcbController);
}

void FIFOCommand::execute(std::string arg)
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

    FirstInFirstOut fifo(getPCBController());
    fifo.loadProcesses(fileName);

    fifo.sortProcesses();
    fifo.runProcesses();

    std::cout << "Processes ran. See FirstInFirstOutResults.txt in OS folder." << std::endl;
}
