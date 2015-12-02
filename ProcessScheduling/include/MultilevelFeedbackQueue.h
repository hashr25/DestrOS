#ifndef MUTILEVELFEEDBACKQUEUE_H
#define MUTILEVELFEEDBACKQUEUE_H

#include <fstream>

#include "ProcessScheduler.h"

///For testing purposes
#include "ShowReadyPCBCommand.h"


class MultilevelFeedbackQueue : public ProcessScheduler
{
    public:
        MultilevelFeedbackQueue(PCBController*);

        void sortProcesses();
        void runProcesses();
        void runProcesses(int, int, int);

    private:
        int getQueueGap(int);
        int getMinPriority(int, int);
        int getMaxPriority(int, int);
};

#endif // MUTILEVELFEEDBACKQUEUE_H
