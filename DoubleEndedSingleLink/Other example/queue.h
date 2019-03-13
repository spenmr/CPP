#ifndef QUEUE_H
#define QUEUE_H

// queue implemented on couble ended,
//single linked list

#include "list.h"


class Queue
{
    public:
        Queue(){}
        virtual ~Queue(){}
        void addTail(int v) { theList.addTail(v); }
        int removeHead() { return theList.removeHead(); }
    private:
        List theList;
};

#endif // QUEUE_H
