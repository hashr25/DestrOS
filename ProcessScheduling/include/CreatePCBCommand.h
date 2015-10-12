#ifndef CREATEPCBCOMMAND_H
#define CREATEPCBCOMMAND_H

#include "Command.h"


class CreatePCBCommand : public Command
{
public:
    CreatePCBCommand(PCBController*);

    void execute(std::string);
private:
};

#endif // CREATEPCBCOMMAND_H
