#ifndef SHOWREADYPCBCOMMAND_H
#define SHOWREADYPCBCOMMAND_H

#include "Command.h"


class ShowReadyPCBCommand : public Command
{
    public:
        ShowReadyPCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // SHOWREADYPCBCOMMAND_H
