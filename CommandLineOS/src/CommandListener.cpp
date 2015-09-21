#include "CommandListener.h"

CommandListener::CommandListener()
{
    //ctor
}


std::string CommandListener::getInput()
{
    std::string userInput = "";
    bool goodInput = false;

    while(!goodInput && userInput != "")
    {
        std::cout << "# - ";
        std::cin >> userInput;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else
        {
            goodInput = true;
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
    int space = userInput.find(' ');
    return userInput.substr(space, userInput.size()-space);
}


Command* CommandListener::decipherCommand(std::string cmd, std::vector<Command*> cmdList)
{
    Command* command = NULL;

    for(int i = 0; i < cmdList.size(); i++)
    {
        if(cmdList.at(i) -> getName() == cmd)
        {
            command = cmdList.at(i);
        }
    }

    return command;
}


Command* CommandListener::getCommand(std::vector<Command*> cmdList)
{

}
