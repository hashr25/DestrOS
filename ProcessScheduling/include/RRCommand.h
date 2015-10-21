#ifndef RRCOMMAND_H
#define RRCOMMAND_H

#include "Command.h"
#include "RoundRobin.h"


class RRCommand : public Command
{
    public:
        RRCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // RRCOMMAND_H
