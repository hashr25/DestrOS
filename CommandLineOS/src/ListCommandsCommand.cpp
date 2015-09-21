#include "ListCommandsCommand.h"

ListCommandsCommand::ListCommandsCommand()
{
    //ctor
}

void ListCommandsCommand::execute()
{
    if(getCommandList() != NULL)
    {
        std::cout << "Testing size:" << getCommandList()->size() << std::endl;
    }
    else
    {
        std::cout << "It's null idiot." << std::endl;
    }
    /*for(int i = 0; i < getCommandList()->size(); i++)
    {
        //std::cout << getCommandList()->at(i)->getName() << " - " << getCommandList()->at(i)->getDesc() << std::endl;
        std::cout << "Attempting go through vector. At index: " << i << std::endl;
    }*/
}
