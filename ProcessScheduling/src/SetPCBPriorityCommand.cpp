#include "SetPCBPriorityCommand.h"

SetPCBPriorityCommand::SetPCBPriorityCommand(PCBController* pcbController)
{
    setAlias("setPCBPriority");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to set a currently suspended PCB back to its original state");

    setPCBController(pcbController);
}

void SetPCBPriorityCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    short newPriority = 256;

    bool goodInput = false;

    PCB* pcbToChange = getPCBController() -> FindPCB(pcbName);
    if(pcbToChange != NULL)
    {
        goodInput = true;
    }

    ///PCB name input
    while(!goodInput)
    {
        std::cout << "Enter the name of the process to change: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToChange = getPCBController() -> FindPCB(pcbName);
        if(pcbToChange != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    ///Priority change input
    goodInput = false;
    while(!goodInput)
    {
        std::cout << "Enter the new priority between -127 and 128: ";
        std::cin >> newPriority;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else if(newPriority >= PRIORITY_MIN && newPriority <= PRIORITY_MAX)
        {
            ///Correct input
            goodInput = true;
            break;
        }
        else
        {
            std::cout << "That is not a valid priority." << std::endl;
        }
    }


    pcbToChange -> setPriority(newPriority);

    if(pcbToChange -> getPriority() == newPriority)
    {
        std::cout << "Priority changed successfully." << std::endl;
    }
    else
    {
        std::cout << "Error changing priority. Please check status and try again. " << std::endl;
    }
}
