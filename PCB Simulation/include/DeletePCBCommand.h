#ifndef DELETEPCBCOMMAND_H
#define DELETEPCBCOMMAND_H

#include "Command.h"


class DeletePCBCommand : public Command
{
    public:
        DeletePCBCommand(PCBController*);

        void execute(std::string);

    protected:
    private:
};

#endif // DELETEPCBCOMMAND_H
