#ifndef LISTCOMMANDSCOMMAND_H
#define LISTCOMMANDSCOMMAND_H

#include <iostream>

#include <Command.h>


class ListCommandsCommand : public Command
{
    public:
        ListCommandsCommand(std::vector<Command*>*);

        void execute(std::string);

    private:
};

#endif // LISTCOMMANDSCOMMAND_H
