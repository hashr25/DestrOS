#ifndef DISPLAYVERSIONCOMMAND_H
#define DISPLAYVERSIONCOMMAND_H

#include "Command.h"


class DisplayVersionCommand : public Command
{
    public:
        DisplayVersionCommand();
    protected:
    private:
        std::string osVersion;
};

#endif // DISPLAYVERSIONCOMMAND_H
