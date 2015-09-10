#include "CommandLog.h"

CommandLog::CommandLog()
{

}

void CommandLog::logAndExecute(Command* cmd)
{
    log.push_back(cmd);
    argLog.push_back(cmd -> getArgument());

    cmd -> execute();
}

std::vector<Command*> CommandLog::getLog()
{
    return log;
}
