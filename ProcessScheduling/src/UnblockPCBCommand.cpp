#include "UnblockPCBCommand.h"

UnblockPCBCommand::UnblockPCBCommand(PCBController* pcbController)
{
    setAlias("unblockPCB");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to set a current blocked PCB back to the ready state");

    setPCBController(pcbController);
}

void UnblockPCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToUnblock = getPCBController() -> FindPCB(pcbName);
    if(pcbToUnblock != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to unblock: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToUnblock = getPCBController() -> FindPCB(pcbName);
        if(pcbToUnblock != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    if(pcbToUnblock -> getState() == READY)
    {
        std::cout << "PCB is not blocked." << std::endl;
    }
    else
    {
        getPCBController() -> RemovePCB(pcbToUnblock);
        pcbToUnblock -> setState(READY);
        getPCBController() -> InsertPCB(pcbToUnblock);

        if(pcbToUnblock -> getState() == BLOCKED)
        {
            std::cout << "PCB unblocked correctly." << std::endl;
        }
        else
        {
            std::cout << "Error unblocking PCB. Please check status and try again." << std::endl;
        }
    }

}
