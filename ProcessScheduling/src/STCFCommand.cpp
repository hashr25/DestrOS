#include "STCFCommand.h"

STCFCommand::STCFCommand(PCBController* pcbController)
{
    setAlias("STCF");
    setHelp("Enter Process filename as argument or after command when prompted");
    setDesc("Runs the Shortest Time To Completion Scheduler on file of processes");

    setPCBController(pcbController);
}

void STCFCommand::execute(std::string arg)
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

    ShortestTimeToCompletion stcf(getPCBController());
    stcf.loadProcesses(fileName);

    stcf.runProcesses();

    std::cout << "Processes ran. See ShortestTimeToCompletionResults.txt in OS folder." << std::endl;
}
