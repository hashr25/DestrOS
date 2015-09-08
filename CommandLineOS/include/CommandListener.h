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
        Command* deciperCommand(std::string, std::vector<Command>);

    protected:


    private:
};

#endif // COMMANDLISTENER_H
