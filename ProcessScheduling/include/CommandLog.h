#ifndef COMMANDLOG_H
#define COMMANDLOG_H

#include <iostream>

#include <vector>
#include <Assert.h>

#include "Command.h"

class CommandLog
{
public:
    CommandLog();
    ~CommandLog();

    void logAndExecute(Command*, std::string);

    std::vector<Command*>* getCommands();
    std::vector<std::string>* getArgs();

private:
    std::vector<Command*>* log;
    std::vector<std::string>* argLog;
};

#endif // COMMANDLOG_H
