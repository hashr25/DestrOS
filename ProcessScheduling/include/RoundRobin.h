#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <fstream>

#include "ProcessScheduler.h"


class RoundRobin : public ProcessScheduler
{
    public:
        RoundRobin(PCBController*);

        void sortProcesses();
        void runProcesses();
        void runProcesses(int);
    protected:
    private:
};

#endif // ROUNDROBIN_H
