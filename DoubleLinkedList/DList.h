#ifndef DLIST_H
#define DLIST_H

#include <stdexcept>

#include "DLink.h"

class DList
{
    public:
        DList();
        virtual ~DList();

        void addHead(int value);
        void addTail(int value);
        int removeHead();
        int removeTail();

        bool findValue(int value);
        bool findRemove(int value);

    private:
        DLink * head;
        DLink * tail;
};

#endif // DLIST_H
