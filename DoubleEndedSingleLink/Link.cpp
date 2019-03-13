#include "Link.h"

    //Constructor, default values makes coding simpler
Link::Link(int value, Link * next)
{
    this->value = value;
    this->next = next;
}

    // destructor that does nothing
Link::~Link()
{

}

    // setNext but no setValue
void Link::setNext(Link * next)
{
    this->next = next;
}

    // standard getters
int Link::getValue()
{
    return value;
}
Link * Link::getNext()
{
    return next;
}
