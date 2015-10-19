#ifndef FPPSCOMMAND_H
#define FPPSCOMMAND_H

#include <fstream>

#include "Command.h"
#include "FixedPriorityPreEmptive.h"

class FPPSCommand : public Command
{
    public:
        FPPSCommand(PCBController*);

        void execute(std::string);
    private:
};

#endif // FPPSCOMMAND_H
