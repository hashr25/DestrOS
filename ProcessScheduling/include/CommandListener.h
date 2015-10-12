#ifndef COMMANDLISTENER_H
#define COMMANDLISTENER_H

#include <iostream>
#include <vector>

#include "Command.h"


class CommandListener
{
    public:
        CommandListener();

        std::string getInput();

        std::string getCommandFromInput(std::string);
        Command* decipherCommand(std::string, std::vector<Command*>*);

        std::string getArgument(std::string);

    private:

};

#endif // COMMANDLISTENER_H
