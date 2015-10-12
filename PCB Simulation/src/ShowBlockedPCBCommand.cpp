#include "ShowBlockedPCBCommand.h"

ShowBlockedPCBCommand::ShowBlockedPCBCommand(PCBController* pcbController)
{
    setAlias("showBlockedPCB");
    setHelp("No valid arguments, just enter to see blocked queue");
    setDesc("Allows users to see all PCBs in blocked state");

    setPCBController(pcbController);
}

void ShowBlockedPCBCommand::execute(std::string arg)
{
    std::cout << "Blocked PCBs:" << std::endl;
    PCBNode* currentNode = getPCBController() -> getBlockedQueue() -> getHead();

    while(currentNode != NULL)
    {
        currentNode -> getPCB() -> printPCBSmall();
        currentNode = currentNode -> getNext();
    }

    std::cout << "\n" << std::endl;
}
