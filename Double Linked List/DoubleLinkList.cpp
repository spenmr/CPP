// Double Linked List methods

#include "DoubleLinkList.h"

    // initialize head and tail pointers
DoubleLinkList::DoubleLinkList()
{
    head = tail = NULL;
}

    // delete any remaining links
DoubleLinkList::~DoubleLinkList()
{
    Link * ptr = head;
    while ( ptr != NULL )
    {
        Link * temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}

    // create new link, add to head
    // special case empty list
void DoubleLinkList::addHead(int v)
{
    if ( head == NULL )
        head = tail = new Link (v, NULL, NULL);
    else
    {
        Link * temp = new Link(v, head, NULL);
        head->setPrev(temp);
        head = temp;
    }
}

    // look for an item on list
    // return true if present
    // identical to single linked method
bool DoubleLinkList::find(int v)
{
    if ( head == NULL )
        return false;

    Link *ptr = head;

    while ( ptr != NULL )
    {
        if ( ptr->getData() == v )
            return true;
        ptr = ptr->getNext();
    }

    return false;
}

    // remove head and return value
    // specail case empty list and singleton list
int DoubleLinkList::removeHead()
{
        // list is empty
    if ( head == NULL )
    {
        // DoubleLinkList empty, do something intelligent
        throw "List empty!!";
    }

        // save valeu and update head
    int temp = head->getData();
    Link * ptr = head;
    head = head->getNext();

        // check for singleton list
    if ( head == NULL )
    {
        tail = NULL;
    }
    else
    {
        head->setPrev(NULL);
    }

        // clean up and go home
    delete ptr;
    return temp;
}

    // find item and delete
    // special case emtpy, head, tail
bool DoubleLinkList::deleteItem(int v)
{
        // list empty, go home now
    if ( head == NULL )
        return false;

        // item at head, update properly
    if ( head->getData() == v )
    {
        return removeHead();
    }

        // not at head, now search for it
    Link * ptr = head->getNext();

    while ( ptr != NULL )
    {
        if ( ptr->getData() == v )
        {
                // these variables are used to make
                // the code easier to understand
            Link * prev = ptr->getPrev();
            Link * next = ptr->getNext();

            prev->setNext(next);
            if ( next == NULL )
                tail = prev;
            else
                next->setPrev(prev);
            delete ptr;
            return true;
        }
        ptr = ptr->getNext();
    }

    return false;
}

    // add item at tail
void DoubleLinkList::addTail(int v)
{
        // empty list, fix and go home
    if ( head == NULL )
    {
        head = tail = new Link(v, NULL, NULL);
        return;
    }

        // new link's next is NULL, prev is tail
    Link * temp = new Link(v, NULL, tail);
    tail->setNext(temp);
    tail = temp;
    return;
}




