#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command
{
public:
    Command();

    void virtual execute() = 0;

    void setAlias(std::string);


private:
    std::string commandName;

};

#endif // COMMAND_H
