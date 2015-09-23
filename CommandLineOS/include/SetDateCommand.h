#ifndef SETDATECOMMAND_H
#define SETDATECOMMAND_H

#ifdef __linux__
    #include //Something
#elif __WIN32
    #include <Windows.h>
#endif // __linux__

#include <string>
#include <sstream>

#include "Command.h"
#include "CommandListener.h"

class SetDateCommand : public Command
{
    public:
        SetDateCommand();

        void execute(std::string);

    private:
        int getIntInput();
        int getMonthInput();
        int getDayInput();
        int getYearInput();
        std::string intToString(int);
        std::string formatDate(int, int, int);
};

#endif // SETDATECOMMAND_H
