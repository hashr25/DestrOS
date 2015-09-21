#include "System.h"

System::System()
{
    running = true;
}

System::~System()
{
    /// Frees all memory used by commands used in the program.
    for(int i = 0; i < commandList.size(); i++)
    {
        delete commandList.at(i);
    }
}

void System::run()
{
    while(running)
    {
        currentCmd = listener.getCommand(commandList);

        log.logAndExecute(currentCmd);
    }
}
