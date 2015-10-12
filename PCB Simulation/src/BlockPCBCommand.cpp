#include "BlockPCBCommand.h"

BlockPCBCommand::BlockPCBCommand(PCBController* pcbController)
{
    setAlias("blockPCB");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to set a current PCB to the blocked state");

    setPCBController(pcbController);
}

void BlockPCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToBlock = getPCBController() -> FindPCB(pcbName);
    if(pcbToBlock != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to block: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToBlock = getPCBController() -> FindPCB(pcbName);
        if(pcbToBlock != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    if(pcbToBlock -> getState() == BLOCKED)
    {
        std::cout << "PCB is already blocked." << std::endl;
    }
    else
    {
        getPCBController() -> RemovePCB(pcbToBlock);
        pcbToBlock -> setState(BLOCKED);
        getPCBController() -> InsertPCB(pcbToBlock);

        if(pcbToBlock -> getState() == BLOCKED)
        {
            std::cout << "PCB blocked correctly." << std::endl;
        }
        else
        {
            std::cout << "Error blocking PCB. Please check status and try again." << std::endl;
        }
    }
}
