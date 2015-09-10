#ifndef COMMANDLOG_H
#define COMMANDLOG_H

#include <vector>
#include <Assert.h>

#include "Command.h"

class CommandLog
{
public:
    CommandLog();

    void logAndExecute(Command*);

    std::vector<Command*> getLog();
    std::vector<std::string> getArgs();

private:
    std::vector<Command*> log;
    std::vector<std::string> argLog;
};

#endif // COMMANDLOG_H
