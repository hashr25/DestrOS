#include "ShowPCBCommand.h"

ShowPCBCommand::ShowPCBCommand(PCBController* pcbController)
{
    setAlias("showPCB");
    setHelp("Enter PCB name after command or as argument");
    setDesc("Allows users to see a specific PCB");

    setPCBController(pcbController);
}

void ShowPCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToShow = getPCBController() -> FindPCB(pcbName);
    if(pcbToShow != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to show: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToShow = getPCBController() -> FindPCB(pcbName);
        if(pcbToShow != NULL)
        {
            goodInput = true;
            break;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    pcbToShow -> printPCB();
}
