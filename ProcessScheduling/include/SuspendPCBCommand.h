#ifndef SUSPENDPCBCOMMAND_H
#define SUSPENDPCBCOMMAND_H

#include "Command.h"


class SuspendPCBCommand : public Command
{
    public:
        SuspendPCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // SUSPENDPCBCOMMAND_H
