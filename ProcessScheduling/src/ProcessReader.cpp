#include "ProcessReader.h"

ProcessReader::ProcessReader()
{
    ///Nothing to initiate
}



PCB* parseLine(std::string line)
{
    std::string processName;
    bool processClass;
    char processClassKey;
    short processPriority;
    int processMemory;
    int processTimeRemaining;
    int processTimeOfArrival;
    int processPercentageOfCPU;

    std::stringstream ss(line);
    ss >> processName >> processClassKey >> processPriority >> processMemory >> processTimeRemaining >> processTimeOfArrival >> processPercentageOfCPU;

    if(processClassKey == 'A')
    {
        processClass = APPLICATION_TYPE;
    }
    else if(processClassKey == 'S')
    {
        processClass = SYSTEM_TYPE;
    }

    PCB* process = new PCB;

    process -> setName(processName);
    process -> setClass(processClass);
    process -> setPriority(processPriority);
    process -> setMemory(processMemory);
    process -> setTimeRemaining(processTimeRemaining);
    process -> setTimeOfArrival(processTimeOfArrival);
    process -> setPercentageOfCPU(processPercentageOfCPU);

    return process;

}

std::vector<std::string> readProcessFile(std::string fileName)
{
    std::vector<std::string> linesOfFile;
    std::ifstream inputFile(fileName.c_str());
    std::string line;

    while(getline(inputFile, line))
    {
        linesOfFile.push_back(line);
    }

    return linesOfFile;
}

std::vector<PCB*> readProcesses(std::string fileName)
{
    std::vector<std::string> fileLines = readProcessFile(fileName);
    std::vector<PCB*> processes;

    ///For each line in the file
    for(int i = 0; i < fileLines.size(); i++)
    {
        ///Add the process that was written on that line
        processes.push_back(parseLine(fileLines.at(i)));
    }

    return processes;
}
