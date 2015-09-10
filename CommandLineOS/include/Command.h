#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

class Command
{
public:
    Command();

    void virtual execute() = 0;

    std::string getName();
    void setAlias(std::string);

    std::string getArgument();
    void setArgument(std::string);

    void addValidArgument(std::string);

    void setHelp(std::string);
    std::string getHelp();

private:
    std::string commandName;
    std::string argument;

    std::vector<std::string> validArguments;
    std::string helpInfo;
};

#endif // COMMAND_H
