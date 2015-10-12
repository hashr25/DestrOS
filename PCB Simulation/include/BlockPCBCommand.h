#ifndef BLOCKPCBCOMMAND_H
#define BLOCKPCBCOMMAND_H

#include "Command.h"


class BlockPCBCommand : public Command
{
    public:
        BlockPCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // BLOCKPCBCOMMAND_H
