#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command
{
public:
    Command();

    void virtual execute() = 0;

    void setAlias(std::string);
    void addArgument(std::string);

    void setHelp(std::string);
    std::string getHelp();

private:
    std::string commandName;
    std::vector<std::string> validArguments;
    std::string helpInfo;
};

#endif // COMMAND_H
