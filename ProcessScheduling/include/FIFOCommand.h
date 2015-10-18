#ifndef FIFOCOMMAND_H
#define FIFOCOMMAND_H

#include "Command.h"
#include "PCBController.h"
#include "FirstInFirstOut.h"


class FIFOCommand : public Command
{
    public:
        FIFOCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // FIFOCOMMAND_H
