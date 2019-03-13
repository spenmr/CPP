#ifndef MYSTACK_H
#define MYSTACK_H

#include "dequeue.h"

class myStack{
    private:
        dequeue * theQueue;
    public:
        myStack();
        myStack(int size);
        void push(int value);
        int pop();
        int peek();
        std::string dumpIt();
};

#endif // MYSTACK_H
