#ifndef PROCESSREADER_H
#define PROCESSREADER_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "PCB.h"

class ProcessReader
{
    public:
        ProcessReader();

        PCB* parseLine(std::string);
        std::vector<std::string> readProcessFile(std::string);
        std::vector<PCB*> readProcesses(std::string);

    private:
};

#endif // PROCESSREADER_H
