#ifndef SETPCBPRIORITYCOMMAND_H
#define SETPCBPRIORITYCOMMAND_H

#include "Command.h"


class SetPCBPriorityCommand : public Command
{
    public:
        SetPCBPriorityCommand(PCBController*);

        void execute(std::string);

    private:
};

#endif // SETPCBPRIORITYCOMMAND_H
