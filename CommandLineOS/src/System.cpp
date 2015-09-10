#include "System.h"

System::System()
{
    running = true;
}

void System::run()
{
    while(running)
    {
        currentCmd = listener.getCommand(commandList);

        log.logAndExecute(currentCmd);
    }
}
