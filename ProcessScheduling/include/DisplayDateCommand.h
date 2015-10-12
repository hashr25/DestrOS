#ifndef DISPLAYDATECOMMAND_H
#define DISPLAYDATECOMMAND_H

#include <iostream>
#include <ctime>

#include "Command.h"

class DisplayDateCommand : public Command
{
public:
    DisplayDateCommand();

    void execute(std::string);

private:


};

#endif // DISPLAYDATECOMMAND_H
