#ifndef DISPLAYHELPCOMMAND_H
#define DISPLAYHELPCOMMAND_H

#include <iostream>

#include "Command.h"


class DisplayHelpCommand : public Command
{
    public:
        DisplayHelpCommand(std::vector<Command*>*);

        void execute(std::string);

    private:
        std::string findListCommandName();
};

#endif // DISPLAYHELPCOMMAND_H
