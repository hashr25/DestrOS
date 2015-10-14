#include "ShortestJobFirst.h"

ShortestJobFirst::ShortestJobFirst(std::vector<PCB*> processes)
{
    setProcesses(processes);
}


std::vector<PCB*> ShortestJobFirst::sortProcesses()
{
    //Copies current vector into local vector
    std::vector<PCB*> sortedProcesses = getProcesses();
    //Sorts the vector with quicksort based on the time remaining
    qSort(sortedProcesses, 0, sortedProcesses.size());

    setProcesses(sortedProcesses);

    return sortedProcesses;
}

void ShortestJobFirst::runProcesses()
{

}

///Taken directly from my Data Structures assignment
void ShortestJobFirst::qSort(std::vector<PCB*>& vect, int left, int right)
{
    long swapLeft = left;
    long swapRight = right;
    long pivot = vect.at((left+right)/2) -> getTimeRemaining();

    while(swapLeft <= swapRight)
    {
        while(vect.at(swapLeft)->getTimeRemaining() < pivot)
        {
            swapLeft++;
        }
        while(vect.at(swapRight)->getTimeRemaining() > pivot)
        {
            swapRight--;
        }
        if(swapLeft <= swapRight)
        {
            PCB* temp = vect.at(swapLeft);
            vect.at(swapLeft) = vect.at(swapRight);
            vect.at(swapRight) = temp;

            swapLeft++;
            swapRight--;
        }
    }

    if(left < swapRight)
    {
        qSort(vect, left, swapRight);
    }
    if(swapLeft < right)
    {
        qSort(vect, swapLeft, right);
    }
}
