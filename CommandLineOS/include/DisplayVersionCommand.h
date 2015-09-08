#ifndef DISPLAYVERSIONCOMMAND_H
#define DISPLAYVERSIONCOMMAND_H

#include <iostream>

#include "Command.h"


class DisplayVersionCommand : public Command
{
    public:
        DisplayVersionCommand();

        void execute();

    protected:


    private:
        std::string osVersion;

};

#endif // DISPLAYVERSIONCOMMAND_H
