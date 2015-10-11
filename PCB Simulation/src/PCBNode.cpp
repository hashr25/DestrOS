#include "PCBNode.h"

PCBNode::PCBNode()
{
    pcb = NULL;
    next = NULL;
}

PCBNode::PCBNode(PCB* pcb)
{
    setPCB(pcb);
    next = NULL;
}

PCBNode::PCBNode(PCB* pcb, PCBNode* next)
{
    setPCB(pcb);
    setNext(next);
}


void PCBNode::setNext(PCBNode* next)
{
    this -> next = next;
}

PCBNode* PCBNode::getNext()
{
    return next;
}

void PCBNode::setPCB(PCB* pcb)
{
    this -> pcb = pcb;
}

PCB* PCBNode::getPCB()
{
    return pcb;
}
