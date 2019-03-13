#ifndef LIST_H
#define LIST_H

    // Include this so can throw exception for empty list
#include <stdexcept>
    // Defines what a link is
#include "Link.h"

class List
{
    public:
        List();
        virtual ~List();

        void addHead(int value);
        void addTail(int value);
        int removeHead();

        bool findValue(int value);
        bool findRemove(int value);

    protected:
    private:
        Link * head;
    Link * tail;
};

#endif // LIST_H
