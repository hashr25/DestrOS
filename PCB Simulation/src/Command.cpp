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

std::string Command::getDesc()
{
    return commandDesc;
}

void Command::setDesc(std::string newDesc)
{
    commandDesc = newDesc;
}

void Command::setHelp(std::string help)
{
    helpInfo = help;
}

std::string Command::getHelp()
{
    return helpInfo;
}

void Command::setCommandList(std::vector<Command*>* newList)
{
    commandList = newList;
}

std::vector<Command*>* Command::getCommandList()
{
    return commandList;
}

void Command::setPCBController(PCBController* pcbController)
{
    this -> pcbController = pcbController;
}

PCBController* Command::getPCBController()
{
    return pcbController;
}
