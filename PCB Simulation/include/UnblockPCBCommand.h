#ifndef UNBLOCKPCBCOMMAND_H
#define UNBLOCKPCBCOMMAND_H

#include "Command.h"


class UnblockPCBCommand : public Command
{
    public:
        UnblockPCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // UNBLOCKPCBCOMMAND_H
