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

    std::string getDesc();
    void setDesc(std::string);

    std::string getArgument();
    void setArgument(std::string);

    void addValidArgument(std::string);

    void setHelp(std::string);
    std::string getHelp();

    void setCommandList(std::vector<Command*>*);
    std::vector<Command*>* getCommandList();

private:
    std::string commandName;
    std::string commandDesc;
    std::string argument;

    std::vector<std::string> validArguments;
    std::string helpInfo;

    std::vector<Command*>* commandList;
};

#endif // COMMAND_H
