#ifndef DISPLAYHELPCOMMAND_H
#define DISPLAYHELPCOMMAND_H

#include <iostream>

#include "Command.h"


class DisplayHelpCommand : public Command
{
    public:
        DisplayHelpCommand(std::vector<Command*>*);
        DisplayHelpCommand(std::vector<Command*>*, std::string);

        void execute();

    private:
};

#endif // DISPLAYHELPCOMMAND_H
