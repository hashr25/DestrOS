#include "System.h"

System::System()
{
    running = true;
    initCommands();
}

System::~System()
{
    /// Frees all memory used by commands used in the program.
    for(int i = 0; i < commandList -> size(); i++)
    {
        delete commandList -> at(i);
    }
    delete commandList;
}

void System::initCommands()
{
    commandList = new std::vector<Command*>;

    Command* cmd1 = new DisplayHelpCommand(commandList);
    commandList -> push_back(cmd1);

    Command* cmd2 = new DisplayDateCommand;
    commandList -> push_back(cmd2);

    Command* cmd3 = new DisplayVersionCommand;
    commandList -> push_back(cmd3);

    Command* cmd4 = new ListCommandsCommand(commandList);
    commandList -> push_back(cmd4);

    Command* cmd5 = new ExitCommand;
    commandList -> push_back(cmd5);

    Command* cmd6 = new SetDateCommand;
    commandList -> push_back(cmd6);
}

void System::run()
{
    while(running) ///I know, infinite loop until exit command is
    {
        std::string currentInput = listener.getInput();

        ///Convert input into command
        std::string currentCmdStr = listener.getCommandFromInput(currentInput);
        Command* currentCmd = listener.decipherCommand(currentCmdStr, commandList);

        ///Convert input into argument
        std::string currentArg = listener.getArgument(currentInput);

        log.logAndExecute(currentCmd, currentArg);
    }
}

