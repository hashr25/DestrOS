#ifndef LOTTERYSCHEDULER_H
#define LOTTERYSCHEDULER_H

#include <stdlib.h>
#include <time.h>

#include "ProcessScheduler.h"
#include "PCBController.h"

#include "ShowAllPCBCommand.h"

class LotteryScheduler : public ProcessScheduler
{
    public:
        LotteryScheduler(PCBController*);


        void sortProcesses();
        void runProcesses();
        void runProcesses(int);

        void setTotalTickets(int);
        int getTotalTickets();

    private:
        int totalTickets;
};

#endif // LOTTERYSCHEDULER_H
