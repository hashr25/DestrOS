#include "PCBQueue.h"

PCBQueue::PCBQueue()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

void PCBQueue::insert(PCB* newPCB)
{
    PCBNode* newNode = new PCBNode(newPCB);


    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> setNext(newNode);
    }

    tail = newNode;
    size++;
}


PCB* PCBQueue::remove()
{
    PCBNode* toRemove = head;
    head = head -> getNext();

    PCB* toReturn = toRemove -> getPCB();
    size--;

    delete toRemove;
    return toReturn;
}

PCB* PCBQueue::remove(PCB* pcb)
{
    if(head -> getPCB() == pcb)
    {
        head = head -> getNext();
        delete head;
    }
    else
    {
        PCBNode* previousNode = head;
        PCBNode* nodeToRemove = head -> getNext();

        while(nodeToRemove != NULL)
        {
            if(nodeToRemove -> getPCB() == pcb)
            {
                previousNode -> setNext( nodeToRemove->getNext() );
                delete nodeToRemove;
                break;
            }

            previousNode = previousNode -> getNext();
            nodeToRemove = nodeToRemove -> getNext();
        }
    }

    size--;
    return pcb;
}

///Getters and Setters
PCBNode* PCBQueue::getHead()
{
    return head;
}

PCBNode* PCBQueue::getTail()
{
    return tail;
}


void PCBQueue::setHead(PCBNode* head)
{
    this -> head = head;
}

void PCBQueue::setTail(PCBNode* tail)
{
    this -> tail = tail;
}

int PCBQueue::getSize()
{
    return size;
}
