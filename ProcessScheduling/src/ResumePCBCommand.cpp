#include "ResumePCBCommand.h"

ResumePCBCommand::ResumePCBCommand(PCBController* pcbController)
{
    setAlias("resumePCB");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to set a currently suspended PCB back to its original state");

    setPCBController(pcbController);
}

void ResumePCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToResume = getPCBController() -> FindPCB(pcbName);
    if(pcbToResume != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to resume: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToResume = getPCBController() -> FindPCB(pcbName);
        if(pcbToResume != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    if(pcbToResume -> getSuspended() == false)
    {
        std::cout << "PCB is not suspended." << std::endl;
    }
    else
    {
        pcbToResume -> setSuspended(true);

        if(pcbToResume -> getSuspended() == true)
        {
            std::cout << "PCB resumed correctly." << std::endl;
        }
        else
        {
            std::cout << "Error resuming PCB. Please check status and try again." << std::endl;
        }
    }
}
