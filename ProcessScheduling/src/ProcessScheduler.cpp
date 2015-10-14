#include "ProcessScheduler.h"

ProcessScheduler::ProcessScheduler()
{

}


void ProcessScheduler::setPCBController(PCBController* pcbController)
{
    this -> pcbController = pcbController;
}

PCBController* ProcessScheduler::getPCBController()
{
    return pcbController;
}

void ProcessScheduler::setProcesses(std::vector<PCB*> processes)
{
    this -> processes = processes;
}

std::vector<PCB*> ProcessScheduler::getProcesses()
{
    return processes;
}
