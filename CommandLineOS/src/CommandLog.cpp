#include "CommandLog.h"

CommandLog::CommandLog()
{

}

void CommandLog::logAndExecute(Command* cmd, std::string arg)
{
    log.push_back(cmd);
    argLog.push_back(arg);

    cmd -> execute(arg);

}

std::vector<Command*> CommandLog::getLog()
{
    return log;
}
