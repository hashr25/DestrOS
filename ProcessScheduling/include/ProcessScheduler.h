#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H

#include <vector>

#include "PCBController.h"
#include "PCB.h"

class ProcessScheduler
{
    public:
        ProcessScheduler();

        std::vector<PCB*> virtual sortProcesses() = 0;
        void virtual runProcesses() = 0;

        void setPCBController(PCBController*);
        PCBController* getPCBController();

        void setProcesses(std::vector<PCB*>);
        std::vector<PCB*> getProcesses();

    private:
        PCBController* pcbController;
        std::vector<PCB*> processes;
};

#endif // PROCESSSCHEDULER_H
