#include "SuspendPCBCommand.h"

SuspendPCBCommand::SuspendPCBCommand(PCBController* pcbController)
{
    setAlias("suspendPCB");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to set a current PCB back to the suspended state");

    setPCBController(pcbController);
}

void SuspendPCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToSuspend = getPCBController() -> FindPCB(pcbName);
    if(pcbToSuspend != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to suspend: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToSuspend = getPCBController() -> FindPCB(pcbName);
        if(pcbToSuspend != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    if(pcbToSuspend -> getSuspended() == true)
    {
        std::cout << "PCB is already suspended." << std::endl;
    }
    else
    {
        pcbToSuspend -> setSuspended(true);

        if(pcbToSuspend -> getSuspended() == true)
        {
            std::cout << "PCB suspended correctly." << std::endl;
        }
        else
        {
            std::cout << "Error suspending PCB. Please check status and try again." << std::endl;
        }
    }
}
