#ifndef LIST_H
#define LIST_H

// double ended, single linked List
// all methods in .cpp file

#include "link.h"

class List
{
    public:
        List();
        ~List();
        void addHead(int v);
        void addTail(int v);
        bool find(int v);
        int removeHead();
        bool deleteItem(int v);
    protected:
    private:
        Link * head;
        Link * tail;
};

#endif // LIST_H
