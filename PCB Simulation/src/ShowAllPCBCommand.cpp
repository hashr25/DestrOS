#include "ShowAllPCBCommand.h"

ShowAllPCBCommand::ShowAllPCBCommand(PCBController* pcbController)
{
    setAlias("showAllPCB");
    setHelp("No valid arguments, just enter to see all PCBs");
    setDesc("Allows users to see all PCBs");

    setPCBController(pcbController);
}

void ShowAllPCBCommand::execute(std::string)
{
    std::cout << "Ready PCBs:" << std::endl;
    PCBNode* currentNode = getPCBController() -> getReadyQueue() -> getHead();

    while(currentNode != NULL)
    {
        currentNode -> getPCB() -> printPCBSmall();
        currentNode = currentNode -> getNext();
    }

    std::cout << "\n" << std::endl;

    std::cout << "Blocked PCBs:" << std::endl;
    currentNode = getPCBController() -> getBlockedQueue() -> getHead();

    while(currentNode != NULL)
    {
        currentNode -> getPCB() -> printPCBSmall();
        currentNode = currentNode -> getNext();
    }

    std::cout << std::endl;
}
