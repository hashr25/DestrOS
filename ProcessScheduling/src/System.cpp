#include "System.h"

System::System()
{
    running = true;

    log = new CommandLog;
    pcbController = new PCBController;

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
    delete pcbController;
}

void System::initCommands()
{
    commandList = new std::vector<Command*>;

    ///Project 1 Commands
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

    ///Project 2 Commands
    /*
    Command* cmd9 = new CreatePCBCommand(pcbController);
    commandList -> push_back(cmd9);

    Command* cmd10 = new DeletePCBCommand(pcbController);
    commandList -> push_back(cmd10);

    Command* cmd11 = new BlockPCBCommand(pcbController);
    commandList -> push_back(cmd11);

    Command* cmd12 = new UnblockPCBCommand(pcbController);
    commandList -> push_back(cmd12);
    */
    Command* cmd13 = new SuspendPCBCommand(pcbController);
    commandList -> push_back(cmd13);

    Command* cmd14 = new ResumePCBCommand(pcbController);
    commandList -> push_back(cmd14);

    Command* cmd15 = new SetPCBPriorityCommand(pcbController);
    commandList -> push_back(cmd15);

    Command* cmd16 = new ShowPCBCommand(pcbController);
    commandList -> push_back(cmd16);

    Command* cmd17 = new ShowAllPCBCommand(pcbController);
    commandList -> push_back(cmd17);

    Command* cmd18 = new ShowReadyPCBCommand(pcbController);
    commandList -> push_back(cmd18);

    Command* cmd19 = new ShowBlockedPCBCommand(pcbController);
    commandList -> push_back(cmd19);

    ///Project 3 Commands
    Command* cmd20 = new SJFCommand(pcbController);
    commandList -> push_back(cmd20);

    Command* cmd21 = new FIFOCommand(pcbController);
    commandList -> push_back(cmd21);

    Command* cmd22 = new STCFCommand(pcbController);
    commandList -> push_back(cmd22);

    Command* cmd23 = new FPPSCommand(pcbController);
    commandList -> push_back(cmd23);

    Command* cmd42 = new ExitCommand;
    commandList -> push_back(cmd42);
}

void System::welcome()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                                   " << std::endl;
    std::cout << "                                   Welcome to DestrOS.                     " << std::endl;
    std::cout << "               An interactive command line operating system built for CS361" << std::endl;
    std::cout << "                                  Enjoy your time here!                    " << std::endl;
    std::cout << "                        Type \"help\" for general help information.        " << std::endl;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                                     " << std::endl;

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

