#include "CommandLog.h"

CommandLog::CommandLog()
{
    log = new std::vector<Command*>;
    argLog = new std::vector<std::string>;
}

CommandLog::~CommandLog()
{
    delete log;
    delete argLog;
}

void CommandLog::logAndExecute(Command* cmd, std::string arg)
{
    log->insert(log->begin(), cmd);
    argLog->insert(argLog->begin(), arg);

    cmd -> execute(arg);
}

std::vector<Command*>* CommandLog::getCommands()
{
    return log;
}

std::vector<std::string>* CommandLog::getArgs()
{
    return argLog;
}
