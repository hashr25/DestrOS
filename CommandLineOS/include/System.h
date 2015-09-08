#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>

#include "CommandListener.h"
#include "CommandLog.h"

#include "Command.h"
#include "DisplayVersionCommand.h"
#include "DisplayDateCommand.h"
#include "DisplayHelpCommand.h"

class System
{
    public:
        System();

        void initCommands();

        void run();

    private:
        std::vector<Command*> commandList;
        CommandListener listener;
        CommandLog log;
};

#endif // SYSTEM_H
