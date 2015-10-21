#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>

#include "CommandListener.h"
#include "CommandLog.h"
#include "PCBController.h"

///Project 1 Commands
#include "Command.h"
#include "DisplayVersionCommand.h"
#include "DisplayDateCommand.h"
#include "DisplayHelpCommand.h"
#include "ListCommandsCommand.h"
#include "ExitCommand.h"
#include "SetDateCommand.h"
#include "SetAliasCommand.h"
#include "ViewDirectoryCommand.h"
#include "DisplayHistoryCommand.h"

///Project 2 Commands
#include "CreatePCBCommand.h"
#include "DeletePCBCommand.h"
#include "BlockPCBCommand.h"
#include "UnblockPCBCommand.h"
#include "SuspendPCBCommand.h"
#include "ResumePCBCommand.h"
#include "SetPCBPriorityCommand.h"
#include "ShowPCBCommand.h"
#include "ShowAllPCBCommand.h"
#include "ShowReadyPCBCommand.h"
#include "ShowBlockedPCBCommand.h"

///Project 3 Commands
#include "SJFCommand.h"
#include "FIFOCommand.h"
#include "STCFCommand.h"
#include "FPPSCommand.h"
#include "RRCommand.h"
//#include "MLFQCommand.h"
//#include "LSCommand.h"

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
    CommandLog* log;

    PCBController* pcbController;

    bool running;

    //Methods
    void initCommands();

    void welcome();
};

#endif // SYSTEM_H
