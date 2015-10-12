#include "ShowReadyPCBCommand.h"

ShowReadyPCBCommand::ShowReadyPCBCommand(PCBController* pcbController)
{
    setAlias("showReadyPCB");
    setHelp("No valid arguments, just enter to see ready queue");
    setDesc("Allows users to see all PCBs in ready state");

    setPCBController(pcbController);
}

void ShowReadyPCBCommand::execute(std::string arg)
{
    std::cout << "Ready PCB's:" << std::endl;
    PCBNode* currentNode = getPCBController() -> getReadyQueue() -> getHead();

    while(currentNode != NULL)
    {
        currentNode -> getPCB() -> printPCBSmall();
        currentNode = currentNode -> getNext();
    }

    std::cout << "\n" << std::endl;
}
