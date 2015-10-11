#ifndef PCBNODE_H
#define PCBNODE_H

#include "PCB.h"


class PCBNode
{
public:
    PCBNode();
    PCBNode(PCB*);
    PCBNode(PCB*, PCBNode*);

    void setNext(PCBNode*);
    PCBNode* getNext();

    void setPCB(PCB*);
    PCB* getPCB();

private:
    PCBNode* next;
    PCB* pcb;
};

#endif // PCBNODE_H
