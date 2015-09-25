#include "System.h"

System::System()
{
    running = true;
    log = new CommandLog;
    initCommands();
    welcome();
}

System::~System()
{
    /// Frees all memory used by commands used in the program.
    for(int i = 0; i < commandList -> size(); i++)
    {
        delete commandList -> at(i);
    }
    delete commandList;

    delete log;
}

void System::initCommands()
{
    commandList = new std::vector<Command*>;

    Command* cmd1 = new DisplayHelpCommand(commandList);
    commandList -> push_back(cmd1);

    Command* cmd2 = new DisplayDateCommand;
    commandList -> push_back(cmd2);

    Command* cmd3 = new SetDateCommand;
    commandList -> push_back(cmd3);

    Command* cmd4 = new DisplayVersionCommand;
    commandList -> push_back(cmd4);

    Command* cmd5 = new ListCommandsCommand(commandList);
    commandList -> push_back(cmd5);

    Command* cmd6 = new SetAliasCommand(commandList);
    commandList -> push_back(cmd6);

    Command* cmd7 = new ViewDirectoryCommand;
    commandList -> push_back(cmd7);

    Command* cmd8 = new DisplayHistoryCommand(log);
    commandList -> push_back(cmd8);

    Command* cmd9 = new ExitCommand;
    commandList -> push_back(cmd9);
}

void System::welcome()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n                                                  " << std::endl;
    std::cout << "                              Welcome to DestrOS.                     " << std::endl;
    std::cout << "          An interactive command line operating system built for CS361" << std::endl;
    std::cout << "                             Enjoy your time here!                    " << std::endl;
    std::cout << "                   Type \"help\" for general help information.        " << std::endl;
    std::cout << "\n\n\n\n\n\n\n\n\n                                                    " << std::endl;

    std::cin.ignore();
    system("CLS");
}

void System::run()
{
    while(running) ///I know, infinite loop. BAAAAD! Until exit command is executed
    {
        std::string currentInput = "";
        currentInput = listener.getInput();

        ///Convert input into command
        std::string currentCmdStr = "";
        currentCmdStr = listener.getCommandFromInput(currentInput);
        Command* currentCmd = listener.decipherCommand(currentCmdStr, commandList);

        ///Convert input into argument
        std::string currentArg = "";
        currentArg = listener.getArgument(currentInput);

        if(currentCmd != NULL)
        {
            log -> logAndExecute(currentCmd, currentArg);
        }
    }
}

