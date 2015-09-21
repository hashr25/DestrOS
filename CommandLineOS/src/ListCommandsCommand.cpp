#include "ListCommandsCommand.h"

ListCommandsCommand::ListCommandsCommand(std::vector<Command*>* cmdList)
{
    setAlias("listc");
    setHelp("This command lists all possible commands. No valid arguments");
    setDesc("Lists all valid commands.");
    setCommandList(cmdList);
}

void ListCommandsCommand::execute(std::string arg)
{
    for(int i = 0; i < getCommandList()->size(); i++)
    {
        std::cout << getCommandList()->at(i)->getName() << " - " << getCommandList()->at(i)->getDesc() << std::endl;
    }
}
