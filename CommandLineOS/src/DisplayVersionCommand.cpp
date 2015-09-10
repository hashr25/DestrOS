#include "DisplayVersionCommand.h"

DisplayVersionCommand::DisplayVersionCommand()
{
    osVersion = "0.001.001 BETA";
    setAlias("ver");
    setHelp("This command shows the current version of the running operating system.");
}

void DisplayVersionCommand::execute()
{
    std::cout << "Version " << osVersion << std::endl;
}
