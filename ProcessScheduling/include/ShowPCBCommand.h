#ifndef SHOWPCBCOMMAND_H
#define SHOWPCBCOMMAND_H

#include "Command.h"


class ShowPCBCommand : public Command
{
    public:
        ShowPCBCommand(PCBController*);

        void execute(std::string);

    private:
};

#endif // SHOWPCBCOMMAND_H
