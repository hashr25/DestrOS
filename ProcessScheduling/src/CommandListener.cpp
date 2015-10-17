#include "CommandListener.h"

CommandListener::CommandListener()
{
    //ctor
}


std::string CommandListener::getInput()
{
    std::cin.clear();
    std::string userInput = "";
    bool goodInput = false;

    while(!goodInput && userInput == "")
    {
        std::cout << "\n# - ";
        std::getline(std::cin, userInput);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else
        {
            goodInput = true;
            std::cout << std::endl;
        }
    }

    return userInput;
}


std::string CommandListener::getCommandFromInput(std::string userInput)
{
    int space = userInput.find(' ');
    return userInput.substr(0,space);
}


std::string CommandListener::getArgument(std::string userInput)
{
    std::string arg = "";
    int space = 42;

    for(unsigned int i = 0; i < userInput.size(); i++)
    {
        if(userInput.at(i) == ' ')
        {
            space = i;
        }
    }

    if(space != 42)
    {
        arg = userInput.substr(space+1, userInput.size()-space-1);
    }



    return arg;
}


Command* CommandListener::decipherCommand(std::string cmd, std::vector<Command*>* cmdList)
{
    Command* command = NULL;

    for(unsigned int i = 0; i < cmdList -> size(); i++)
    {
        if(cmdList -> at(i) -> getName() == cmd)
        {
            command = cmdList -> at(i);
        }
    }

    if(command == NULL)
    {
        std::cout << "Invalid command" << std::endl;
    }

    return command;
}
