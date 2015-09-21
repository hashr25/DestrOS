#include "DisplayHelpCommand.h"

DisplayHelpCommand::DisplayHelpCommand(std::vector<Command*>* cmdList)
{
    setAlias("help");
    setDesc("Displays help information about system or command");
    setHelp("Simply enter help for general help or help <command name> for specific help");

    setCommandList(cmdList);
    setArgument("NULL");
}

DisplayHelpCommand::DisplayHelpCommand(std::vector<Command*>* cmdList, std::string argument)
{
    setAlias("help");
    setDesc("Displays help information about system or command");
    setHelp("Simply enter help for general help or help <command name> for specific help");

    setCommandList(cmdList);
    setArgument(argument);
}

void DisplayHelpCommand::execute()
{
    if(getArgument() == "NULL")
    {
        std::cout << "\nIf you truly need help, you might want to install Noobuntu or Macrosoft Doors\n" << std::endl;
        std::cout << "Enter listc for a list of valid commands.\n" << std::endl;
    }
    else
    {
        std::cout << "Holding place; put in call for list entity" << std::endl;
    }
}

