#ifndef DISPLAYHISTORYCOMMAND_H
#define DISPLAYHISTORYCOMMAND_H

#include <iostream>

#include "Command.h"
#include "CommandLog.h"


class DisplayHistoryCommand : public Command
{
    public:
        DisplayHistoryCommand(CommandLog*);

        void execute(std::string);

        void setLog(CommandLog*);
        CommandLog* getLog();

    private:
        CommandLog* log;
};

#endif // DISPLAYHISTORYCOMMAND_H
