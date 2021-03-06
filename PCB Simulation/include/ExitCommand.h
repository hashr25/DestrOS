#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include <iostream>
#include <stdlib.h>

#ifdef __linux__
    #include <unistd.h>
#elif __WIN32
    #include <Windows.h>

#endif // __linux__

#include "Command.h"


class ExitCommand : public Command
{
    public:
        ExitCommand();

        void execute(std::string);

    private:
        void goodBye();
};

#endif // EXITCOMMAND_H
