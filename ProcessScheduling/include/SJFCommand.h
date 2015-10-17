#ifndef SJFCOMMAND_H
#define SJFCOMMAND_H

#include <fstream>

#include "Command.h"
#include "ProcessReader.h"
#include "ShortestJobFirst.h"


class SJFCommand : public Command
{
    public:
        SJFCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // SJFCOMMAND_H
