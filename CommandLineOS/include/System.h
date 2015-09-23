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
#include "ListCommandsCommand.h"
#include "ExitCommand.h"
#include "SetDateCommand.h"
#include "SetAliasCommand.h"
#include "ViewDirectoryCommand.h"

class System
{
    public:
        System();
        ~System();

        void run();

    private:
        //Data
        std::vector<Command*>* commandList;
        CommandListener listener;
        CommandLog log;

        bool running;

        //Methods
        void initCommands();

        void welcome();
};

#endif // SYSTEM_H
