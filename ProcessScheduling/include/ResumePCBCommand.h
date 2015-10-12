#ifndef RESUMEPCBCOMMAND_H
#define RESUMEPCBCOMMAND_H

#include "Command.h"


class ResumePCBCommand : public Command
{
    public:
        ResumePCBCommand(PCBController*);

        void execute(std::string);
    protected:
    private:
};

#endif // RESUMEPCBCOMMAND_H
