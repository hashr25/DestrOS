#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H

#include "ProcessScheduler.h"


class FirstInFirstOut : public ProcessScheduler
{
    public:
        FirstInFirstOut(PCBController*);

        void sortProcesses();
        void runProcesses();
    private:
        void qSort(PCB**, int, int);
};

#endif // FIRSTINFIRSTOUT_H
