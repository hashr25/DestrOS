#include "DisplayVersionCommand.h"

DisplayVersionCommand::DisplayVersionCommand()
{
    osVersion = "0.001.001 BETA";
    setAlias("ver");
    setHelp("This command shows the current version of the running operating system.");
    setDesc("Shows the current operating system version number");
}

void DisplayVersionCommand::execute(std::string arg)
{
    std::cout << "Version " << osVersion << std::endl;
}
