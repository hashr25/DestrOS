#ifndef PCBQUEUE_H
#define PCBQUEUE_H

#include "PCB.h"
#include "PCBNode.h"

class PCBQueue
{
public:
    PCBQueue();

    void insert(PCB*); //Insert at back
    PCB* remove(); //Remove from front
    PCB* remove(PCB*); //Remove certain PCB

    ///Getters and Setters
    PCBNode* getHead();
    PCBNode* getTail();

    void setHead(PCBNode*);
    void setTail(PCBNode*);

    int getSize();

private:
    PCBNode* head;
    PCBNode* tail;
    int size;
};

#endif // PCBQUEUE_H
