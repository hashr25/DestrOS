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
        std::string currentInput = listener.getInput();

        ///Convert input into command
        currentCmd = NULL;

        ///Convert input into argument
        std::string currentArg = "";

        log.logAndExecute(currentCmd, currentArg);
    }
}
