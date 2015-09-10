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
        std::string getArgument(std::string);

        Command* decipherCommand(std::string, std::string, std::vector<Command*>);

        Command* getCommand(std::vector<Command*>);

    protected:


    private:
};

#endif // COMMANDLISTENER_H
