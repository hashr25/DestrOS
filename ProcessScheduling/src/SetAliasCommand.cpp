#include "SetAliasCommand.h"

SetAliasCommand::SetAliasCommand(std::vector<Command*>* cmdList)
{
    setAlias("alias");
    setDesc("Renames any given command to whatever the user pleases");
    setHelp("Follow this command by the name of the target command.");
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

        if( getCommand(newName) == NULL )
        {
            cmdToChange -> setAlias(newName);
        }
        else
        {
            std::cout << "There is already a command with that name." <<std::endl;
        }

        //Clear so it doesn't catch next getline...
        std::cin.clear();
        std::cin.ignore();
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

    for(unsigned int i = 0; i < getCommandList() -> size(); i++)
    {
        if( getCommandList() -> at(i) -> getName() == arg)
        {
            cmdToReturn = getCommandList() -> at(i);
        }
    }

    return cmdToReturn;
}
