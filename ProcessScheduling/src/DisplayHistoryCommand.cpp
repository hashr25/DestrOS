#include "DisplayHistoryCommand.h"

DisplayHistoryCommand::DisplayHistoryCommand(CommandLog* newLog)
{
    setAlias("history");
    setDesc("Displays history of past commands run on this system");
    setHelp("This command will print out the commands and arguments ran on this system");

    setLog(newLog);
}


void DisplayHistoryCommand::execute(std::string argument)
{
    for(unsigned int i = 0; i < log -> getCommands() -> size(); i++)
    {
        std::cout << log -> getCommands() -> at(i) -> getName(); ;
        if(log -> getArgs() -> at(i) != "")
        {
            std::cout << " - " << log -> getArgs() -> at(i);
        }
        std::cout << std::endl;
    }
}


void DisplayHistoryCommand::setLog(CommandLog* newLog)
{
    log = newLog;
}

CommandLog* DisplayHistoryCommand::getLog()
{
    return log;
}
