#ifndef SHOWBLOCKEDPCBCOMMAND_H
#define SHOWBLOCKEDPCBCOMMAND_H

#include "Command.h"


class ShowBlockedPCBCommand : public Command
{
    public:
        ShowBlockedPCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // SHOWBLOCKEDPCBCOMMAND_H
