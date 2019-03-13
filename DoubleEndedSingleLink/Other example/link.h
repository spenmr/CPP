#ifndef LINK_H
#define LINK_H

// Defines a Link for a singly Linked list
// no .cpp file since all methods are single line

#include <cstdlib>

class Link
{
    public:
        Link(int v, Link * n = NULL) {data = v; next = n;}
        void setNext(Link * n){next = n;}
        Link * getNext(){return next;}
        int getData(){return data;}
    private:
        int data;
        Link * next;
};

#endif // LINK_H
