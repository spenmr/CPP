#ifndef QUEUE_H
#define QUEUE_H

// queue implemented on Double Linked List

#include "DoubleLinkList.h"



class Queue
{
    public:
        Queue(){}
        virtual ~Queue(){}
        void addTail(int v){ theList.addTail(v); }
        int removeHead(){ return theList.removeHead(); }
    private:
        DoubleLinkList theList;
};

#endif // QUEUE_H
