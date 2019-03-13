#ifndef LIST_H
#define LIST_H

// double linked list
// methods in .cpp

#include "link.h"

class DoubleLinkList
{
    public:
        DoubleLinkList();
        ~DoubleLinkList();
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
