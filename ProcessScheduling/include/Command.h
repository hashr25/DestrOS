#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

#include "PCBController.h"

class Command
{
public:
    Command();

    void virtual execute(std::string) = 0;

    std::string getName();
    void setAlias(std::string);

    std::string getDesc();
    void setDesc(std::string);

    void setHelp(std::string);
    std::string getHelp();

    void setCommandList(std::vector<Command*>*);
    std::vector<Command*>* getCommandList();

    void setPCBController(PCBController*);
    PCBController* getPCBController();

private:
    std::string commandName;
    std::string commandDesc;

    std::string helpInfo;

    std::vector<Command*>* commandList;
    PCBController* pcbController;
};

#endif // COMMAND_H
