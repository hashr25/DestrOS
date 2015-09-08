#include "DisplayDateCommand.h"

DisplayDateCommand::DisplayDateCommand()
{

}

void DisplayDateCommand::execute()
{
    time_t unixTime = time(0);
    tm* currentTime = localtime(&unixTime);

    std::cout << "Current Date: " << currentTime->tm_mon << "-" << currentTime->tm_mday << "-" << currentTime->tm_year << std::endl;
}
