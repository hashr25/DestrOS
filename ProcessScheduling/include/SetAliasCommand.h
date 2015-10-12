#ifndef SETALIASCOMMAND_H
#define SETALIASCOMMAND_H

#include "Command.h"
#include "CommandListener.h"


class SetAliasCommand : public Command
{
    public:
        SetAliasCommand(std::vector<Command*>*);

        void execute(std::string);

    private:
        Command* getCommand(std::string);
};

#endif // SETALIASCOMMAND_H
