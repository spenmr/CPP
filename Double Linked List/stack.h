#ifndef STACK_H
#define STACK_H

// stack implmented on double liked list

#include "DoubleLinkList.h"

class Stack
{
    public:
        Stack(){}
        virtual ~Stack(){}
        void push(int v){theList.addHead(v);}
        int pop(){return theList.removeHead();}
        int peek() {int data = theList.removeHead(); theList.addHead(data); return data; }
    private:
        DoubleLinkList theList;
};

#endif // STACK_H
