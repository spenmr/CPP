#include "DLink.h"

DLink::DLink(int value, DLink * next, DLink * prev)
{
    this->value = value;
    this->next = next;
    this->prev = prev;
}

void DLink::setNext(DLink * next)
{
    this->next = next;
}
void DLink::setPrev(DLink * prev)
{
    this->prev = prev;
}

int DLink::getValue()
{
    return value;
}
DLink * DLink::getNext()
{
    return next;
}
DLink * DLink::getPrev()
{
    return prev;
}
