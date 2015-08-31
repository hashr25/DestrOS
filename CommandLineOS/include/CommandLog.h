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

private:
    std::vector<Command*> log;
};

#endif // COMMANDLOG_H
