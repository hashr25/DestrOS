#include "ExitCommand.h"

ExitCommand::ExitCommand()
{
    setAlias("exit");
    setDesc("Completely shuts down the operating system");
    setHelp("This command shuts down the entire operating system.");
}

void ExitCommand::execute(std::string arg)
{
    goodBye();

    #ifdef __linux__
        sleep(5000);
    #elif __WIN32
        Sleep(5000);
    #endif // __linux__


    exit(EXIT_SUCCESS);
}


void ExitCommand::goodBye()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n                                                  " << std::endl;
    std::cout << "                          Thank you for using DestrOS.                " << std::endl;
    std::cout << "                    Your continued support is appreciated!            " << std::endl;
    std::cout << "                                                                      " << std::endl;
    std::cout << "                        Come back and see us, ya hear?!               " << std::endl;
    std::cout << "\n\n\n\n\n\n\n\n\n                                                    " << std::endl;
}
