#ifndef SHORTESTTIMETOCOMPLETION_H
#define SHORTESTTIMETOCOMPLETION_H

#include "ProcessScheduler.h"


class ShortestTimeToCompletion : public ProcessScheduler
{
    public:
        ShortestTimeToCompletion(PCBController*);

        void sortProcesses();
        void runProcesses();

    private:
};

#endif // SHORTESTTIMETOCOMPLETION_H
