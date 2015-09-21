#include "ExitCommand.h"

ExitCommand::ExitCommand()
{
    setAlias("exit");
    setDesc("Completely shuts down the operating system");
}

void ExitCommand::execute(std::string arg)
{
    std::cout << "\n\n\n\nThank you for using DestrOS!!!" << std::endl;

    #ifdef __linux__
        sleep(3000);
    #elif __WIN32
        Sleep(3000);
    #endif // __linux__


    exit(EXIT_SUCCESS);
}
