#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

#include "ProcessScheduler.h"

#include "ShowReadyPCBCommand.h"

class ShortestJobFirst : public ProcessScheduler
{
    public:
        ShortestJobFirst(PCBController*);

        void sortProcesses();
        void runProcesses();


    private:
        void qSort(std::vector<PCB*>&, int, int);
        void qSort(PCB**, int, int);
};

#endif // SHORTESTJOBFIRST_H
