#include <iostream>

using namespace std;

#include "System.h"

#include "DisplayDateCommand.h"

int main()
{
    //System sys;
    //sys.run();

    Command* cmd = new DisplayVersionCommand;
    cmd -> execute();

    return 0;
}
