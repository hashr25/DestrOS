#include "DisplayHelpCommand.h"

DisplayHelpCommand::DisplayHelpCommand(std::vector<Command*>* cmdList)
{
    setAlias("help");
    setDesc("Displays help information about system or command");
    setHelp("Follow this command with the name of another command to get more information \n    about that command.");

    setCommandList(cmdList);
}

void DisplayHelpCommand::execute(std::string arg)
{
    if(arg == "")
    {
        std::cout << "If you truly need help, you might want to install Noobuntu or Macrosoft Doors\n" << std::endl;
        std::cout << "Enter " << findListCommandName() << " for a list of valid commands." << std::endl;
    }
    else
    {
        ///Do the stuff with the cmd list
        int helpCommandIndex = 2007;

        for(int i = 0; i < getCommandList() -> size(); i++)
        {
            if (getCommandList() -> at(i) -> getName() == arg.substr(0, getCommandList() -> at(i) -> getName().size()))
            {
                helpCommandIndex = i;
            }
        }

        if(helpCommandIndex == 2007)
        {
            std::cout << "Invalid argument for this command" << std::endl;
        }

        else
        {
            std::cout << getCommandList() -> at(helpCommandIndex) -> getHelp() << std::endl;
        }
    }

}

std::string DisplayHelpCommand::findListCommandName()
{
    std::string name = "";

    for(int i = 0; i < getCommandList() -> size(); i++)
    {
        if(getCommandList() -> at(i) -> getDesc() == "Lists all valid commands.")
        {
            name = getCommandList() -> at(i) -> getName();
        }
    }

    return name;
}
