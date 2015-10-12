#ifndef SHOWALLPCBCOMMAND_H
#define SHOWALLPCBCOMMAND_H

#include "Command.h"


class ShowAllPCBCommand : public Command
{
    public:
        ShowAllPCBCommand(PCBController*);

        void execute(std::string);

    private:
};

#endif // SHOWALLPCBCOMMAND_H
