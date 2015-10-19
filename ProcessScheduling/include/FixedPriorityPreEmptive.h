#ifndef FIXEDPRIORITYPREEMPTIVE_H
#define FIXEDPRIORITYPREEMPTIVE_H

#include "ProcessScheduler.h"


class FixedPriorityPreEmptive : public ProcessScheduler
{
    public:
        FixedPriorityPreEmptive(PCBController*);

        void sortProcesses();
        void runProcesses();
    private:
};

#endif // FIXEDPRIORITYPREEMPTIVE_H
