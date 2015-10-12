#include "DeletePCBCommand.h"

DeletePCBCommand::DeletePCBCommand(PCBController* pcbController)
{
    setAlias("deletePCB");
    setHelp("Enter the PCB name as argument or after command when prompted");
    setDesc("Allows users to delete a current PCB");

    setPCBController(pcbController);
}

void DeletePCBCommand::execute(std::string arg)
{
    std::string pcbName = arg;
    bool goodInput = false;

    PCB* pcbToDelete = getPCBController() -> FindPCB(pcbName);
    if(pcbToDelete != NULL)
    {
        goodInput = true;
    }

    while(!goodInput)
    {
        std::cout << "Enter the name of the process to delete: ";
        std::cin >> pcbName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        pcbToDelete = getPCBController() -> FindPCB(pcbName);
        if(pcbToDelete != NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "That is not a valid process name." << std::endl;
        }
    }

    getPCBController() -> RemovePCB(pcbToDelete);
    getPCBController() -> FreePCB(pcbToDelete);

    if(pcbToDelete == NULL)
    {
        std::cout << "PCB deleted correctly." << std::endl;
    }
    else
    {
        std::cout << "Error deleting PCB. Please check status and try again." << std::endl;
    }
}
