#include "ProcessScheduler.h"

ProcessScheduler::ProcessScheduler(PCBController* pcbController)
{
    setPCBController(pcbController);
}

void ProcessScheduler::loadProcesses(std::string fileName)
{
    ProcessReader pr;
    std::vector<PCB*> processes = pr.readProcesses(fileName);

    for(unsigned int i = 0; i < processes.size(); i++)
    {
        pcbController -> InsertPCB(processes.at(i));
    }
}

void ProcessScheduler::setPCBController(PCBController* pcbController)
{
    this -> pcbController = pcbController;
}

PCBController* ProcessScheduler::getPCBController()
{
    return pcbController;
}
