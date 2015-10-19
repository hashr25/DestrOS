#ifndef STCFCOMMAND_H
#define STCFCOMMAND_H

#include <fstream>

#include "Command.h"
#include "ShortestTimeToCompletion.h"


class STCFCommand : public Command
{
    public:
        STCFCommand(PCBController*);

        void execute(std::string);
    private:
};

#endif // STCFCOMMAND_H
