#include "SetAliasCommand.h"

SetAliasCommand::SetAliasCommand(std::vector<Command*>* cmdList)
{
    setAlias("alias");
    setDesc("Renames any given command to whatever the user pleases");
    setHelp("Use the name of the command you want to change as the argument such as \"<this command> <target command>\".");
    setCommandList(cmdList);
}

void SetAliasCommand::execute(std::string arg)
{
    if(arg != "")
    {
        Command* cmdToChange = getCommand(arg);
        std::string newName = "";

        std::cout << "Enter that command's new name - ";
        std::cin >> newName;

        cmdToChange -> setAlias(newName);

        std::cin.clear();
    }
    else
    {
        std::cout << "You must choose what command you want to rename..." << std::endl;
        std::cout << "Such as \"" << this -> getName() << " <command name>\"" <<std::endl;
    }
}

Command* SetAliasCommand::getCommand(std::string arg)
{
    Command* cmdToReturn = NULL;

    for(int i = 0; i < getCommandList() -> size(); i++)
    {
        if( getCommandList() -> at(i) -> getName() == arg)
        {
            cmdToReturn = getCommandList() -> at(i);
        }
    }

    return cmdToReturn;
}
