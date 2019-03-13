#ifndef LINK_H
#define LINK_H

// link for double linked list
// all methods in class declaration

#include <cstdlib>

class Link
{
    public:
        Link(int v, Link * n = NULL, Link * p = NULL) {data = v; next = n; prev = p;}
        void setNext(Link * n){next = n;}
        void setPrev(Link *p){prev = p;}
        Link * getNext(){return next;}
        Link * getPrev(){return prev;}
        int getData(){return data;}
    private:
        int data;
        Link * next;
        Link * prev;
};

#endif // LINK_H
