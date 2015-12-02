#ifndef MLFQCOMMAND_H
#define MLFQCOMMAND_H

#include <fstream>

#include "Command.h"
#include "MultilevelFeedbackQueue.h"


class MLFQCommand : public Command
{
    public:
        MLFQCommand(PCBController*);

        void execute(std::string);

    private:
};

#endif // MLFQCOMMAND_H
