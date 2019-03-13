// methods for double ended
// singly Linked List

#include "list.h"

    // initialize pointers to head and tail
List::List()
{
    head = tail = NULL;
}

    // delete any remaining Links
List::~List()
{
    Link * ptr = head;
    while ( ptr != NULL )
    {
        Link * temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}

    // create new Link containing value v
    // and insert it at the head of the List
void List::addHead(int v)
{
    if ( head == NULL )
        head = tail = new Link (v, NULL);
    else
        head = new Link (v, head);
}

    // return true if the List contains
    // a Link with the value v
bool List::find(int v)
{
        // if nothing in list, go away
    if ( head == NULL )
        return false;

        // otherwise walk down list searching
        // if find true, if reach end, false
    Link *ptr = head;

    while ( ptr != NULL )
    {
        if ( ptr->getData() == v )
            return true;
        else
            ptr = ptr->getNext();
    }

    return false;
}

    // remove Link at head of List
    // return value it contains
int List::removeHead()
{
    if ( head == NULL )
    {
        // List empty, do something intelligent
        throw "List empty!!";

    }

        // non-empty list, so remove it
    int temp = head->getData();
    Link * ptr = head;

    head = head->getNext();

        // if List now empty, reset
        // tail pointer
    if ( head == NULL )
        tail = NULL;

        // clean up and go home
    delete ptr;
    return temp;
}

    // Look for link containing v
    // if found, delete and return true
    // else return false
bool List::deleteItem(int v)
{
        // list empty, obviously not there
    if ( head == NULL )
        return false;

        // in first Link,
        // properly update head
        // if single item, update tail also
    if ( head->getData() == v )
    {
        Link * temp = head;
        head = head->getNext();
        if ( head == NULL )
            tail = NULL;
        delete temp;
        return true;
    }

        // not in first, now walk the List
        // if removing last, update tail
    Link * ptr = head->getNext();
    Link * last = head;

    while ( ptr != NULL )
    {
        if ( ptr->getData() == v )
        {
            last->setNext(ptr->getNext());
            if ( last->getNext() == NULL )
                tail = last;
            delete ptr;
            return true;
        }
        last = ptr;
        ptr = ptr->getNext();
    }

    return false;
}

    // create new link containing value v
    // and insert at tail
    // special case empty list
void List::addTail(int v)
{
    if ( head == NULL )
    {
        head = tail = new Link(v, NULL);
        return;
    }

    Link * temp = new Link(v, NULL);
    tail->setNext(temp);
    tail = temp;
    return;
}




