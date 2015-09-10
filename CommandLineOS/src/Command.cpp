#include "Command.h"

Command::Command()
{

}

std::string Command::getName()
{
    return commandName;
}

void Command::setAlias(std::string newName)
{
    commandName = newName;
}

std::string Command::getArgument()
{
    return argument;
}

void Command::setArgument(std::string argument)
{
    this -> argument = argument;
}

void Command::addValidArgument(std::string argument)
{
    validArguments.push_back(argument);
}


void Command::setHelp(std::string help)
{
    helpInfo = help;
}

std::string Command::getHelp()
{
    return helpInfo;
}
