#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

#include "ProcessScheduler.h"


class ShortestJobFirst : public ProcessScheduler
{
    public:
        ShortestJobFirst(std::vector<PCB*>);

        std::vector<PCB*> sortProcesses();
        void runProcesses();


    private:
        void qSort(std::vector<PCB*>&, int, int);
};

#endif // SHORTESTJOBFIRST_H
