#include "DisplayDateCommand.h"

DisplayDateCommand::DisplayDateCommand()
{
    setAlias("date");
    setHelp("This command will display, but not store, the current date.");
    setDesc("Displays the current date (actual date on your machine) ");
}

void DisplayDateCommand::execute(std::string arg)
{
    time_t unixTime = time(0);
    tm* currentTime = localtime(&unixTime);

    //Magic numbers to correct the discrepancies of this way of importing
    std::cout << "Current Date: " << currentTime->tm_mon+1 << "-" << currentTime->tm_mday << "-" << currentTime->tm_year+1900 << std::endl;
}
