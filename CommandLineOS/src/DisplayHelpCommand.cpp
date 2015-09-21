#include "DisplayHelpCommand.h"

DisplayHelpCommand::DisplayHelpCommand(std::vector<Command*>* cmdList)
{
    setAlias("help");
    setDesc("Displays help information about system or command");
    setHelp("Simply enter help for general help or help <command name> for specific help");

    setCommandList(cmdList);
}

void DisplayHelpCommand::execute(std::string arg)
{
    if(arg == "")
    {
        std::cout << "\nIf you truly need help, you might want to install Noobuntu or Macrosoft Doors\n" << std::endl;
        std::cout << "Enter listc for a list of valid commands.\n" << std::endl;
    }
    else
    {
        ///Do the stuff with the cmd list
    }

}
