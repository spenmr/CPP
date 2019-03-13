#ifndef STACK_H
#define STACK_H

// stack implemented on single linked list

#include "list.h"

class Stack
{
    public:
        Stack(){}
        virtual ~Stack(){}
        void push(int v){theList.addHead(v);}
        int pop(){return theList.removeHead();}
        int peek() { int temp = theList.removeHead(); theList.addHead(temp); return temp;}
    private:
        List theList;
};

#endif // STACK_H
