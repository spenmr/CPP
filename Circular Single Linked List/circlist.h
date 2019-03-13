#ifndef CIRCLIST_H
#define CIRCLIST_H

#include <string>
#include <stdexcept>
#include "link.h"

class CircList
{
    public:
        CircList();
        ~CircList();
        void addLink(int value);
        bool findValue(int value);
        int removeNext();
        int showNext();
        bool findRemove(int value);
        std::string displayCirc();
        void step(int steps);
    protected:
    private:
        Link * cur;
};

#endif // CIRCLIST_H
