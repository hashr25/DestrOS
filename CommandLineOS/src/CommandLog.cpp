#include "CommandLog.h"

CommandLog::CommandLog()
{

}

void CommandLog::logAndExecute(Command* cmd)
{
    log.push_back(cmd);

    cmd -> execute();
}
