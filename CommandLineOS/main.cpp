#include <iostream>

using namespace std;

#include "System.h"

#include "DisplayDateCommand.h"
#include "DisplayVersionCommand.h"
#include "DisplayHelpCommand.h"
#include "ListCommandsCommand.h"
#include "ExitCommand.h"

void testSuite();
void testCommands();
void testSystem();

int main()
{
    /**   //////////////////////////////
    Uncomment when actively running

    System sys;
    sys.run();

    **/ /// ////////////////////////////

    testSuite();

    return 0;
}

void testSuite()
{
    testSystem();

    testCommands();
}

void testCommands()
{
    std::vector<Command*>* cmdList = new std::vector<Command*>;


    /// Testing Commands
    Command* cmd1 = new DisplayVersionCommand;
    cmdList->push_back(cmd1);

    Command* cmd2 = new DisplayDateCommand;
    cmdList -> push_back(cmd2);

    Command* cmd3 = new ListCommandsCommand(cmdList);
    cmdList -> push_back(cmd3);

    Command* cmd4 = new DisplayHelpCommand(cmdList);
    cmdList -> push_back(cmd4);

    Command* cmd5 = new ExitCommand;
    cmdList -> push_back(cmd5);

    for(int i = 0; i < cmdList -> size(); i++)
    {
        cmdList -> at(i) -> execute("");
    }

    for(int i = 0; i < cmdList -> size(); i++)
    {
        delete cmdList -> at(i);
    }
}

void testSystem()
{
    System sys;
    sys.run();
}
