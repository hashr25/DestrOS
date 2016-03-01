#ifndef LSCOMMAND_H
#define LSCOMMAND_H

#include "Command.h"
#include "LotteryScheduler.h"


class LSCommand : public Command
{
    public:
        LSCommand(PCBController*);

        void execute(std::string);

    private:
};

#endif // LSCOMMAND_H
