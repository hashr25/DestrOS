#include "CreatePCBCommand.h"

CreatePCBCommand::CreatePCBCommand(PCBController* pcbControler)
{
    setAlias("createPCB");
    setHelp("Follow commands given to create new PCB");
    setDesc("Allows users to create new Process Control Blocks");

    setPCBController(pcbControler);
}

void CreatePCBCommand::execute(std::string arg)
{
    std::string processName;
    bool processClass;
    short processPriority;

    bool goodInput = false;

    ///Name Input
    while (!goodInput)
    {
        std::cout << "Enter the name of the new process(no spaces): ";
        std::cin >> processName;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else if(getPCBController() -> FindPCB(processName) == NULL)
        {
            goodInput = true;
        }
        else
        {
            std::cout << "Process name must be unique." << std::endl;
        }
    }

    ///Class Input
    goodInput = false;
    while(!goodInput)
    {
        std::string userInput = "";

        std::cout << "Enter the class of the process(A for application or S for system): ";
        std::cin >> userInput;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else if(userInput == "A" || userInput == "a")
        {
            goodInput = true;
            processClass = APPLICATION_TYPE;
        }
        else if(userInput == "S" || userInput == "s")
        {
            goodInput = true;
            processClass = SYSTEM_TYPE;
        }
        else
        {
            std::cout << "Class must be valid." << std::endl;
        }
    }

    ///Priority Input
    goodInput = false;
    while(!goodInput)
    {
        short userInput = 256;//This will not clear the input checker in case that nothing is input

        std::cout << "Enter the process priority between -127 and 128: ";
        std::cin >> userInput;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else if(userInput >= PRIORITY_MIN && userInput <= PRIORITY_MAX)
        {
            goodInput = true;
            processPriority = userInput;
        }
        else
        {
            std::cout << "Priority must be valid." << std::endl;
        }
    }

    PCB* newPCB = getPCBController() -> SetupPCB(processName, processPriority, processClass);
    getPCBController() ->InsertPCB(newPCB);
}
