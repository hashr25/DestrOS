#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H

#include <vector>
#include <fstream>

#include "PCBController.h"
#include "PCB.h"
#include "ProcessReader.h"

class ProcessScheduler
{
    public:
        ProcessScheduler(PCBController*);

        void virtual sortProcesses() = 0;
        void virtual runProcesses() = 0;

        void loadProcesses(std::string);

        void setPCBController(PCBController*);
        PCBController* getPCBController();

    private:
        PCBController* pcbController;
};

#endif // PROCESSSCHEDULER_H
