#ifndef LISTCOMMANDSCOMMAND_H
#define LISTCOMMANDSCOMMAND_H

#include <iostream>

#include <Command.h>


class ListCommandsCommand : public Command
{
    public:
        ListCommandsCommand();

        void execute();

    private:
};

#endif // LISTCOMMANDSCOMMAND_H
