#include "Command.h"

Command::Command()
{

}

void Command::setAlias(std::string newName)
{
    commandName = newName;
}

void Command::addArgument(std::string argument);
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
